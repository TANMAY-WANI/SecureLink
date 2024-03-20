#include <server.h>

#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace std;

namespace
{
    void log(const string &message)
    {
        std::cout << message << std::endl;
    }
    void exitWithError(const std::string &errorMessage)
    {
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace HTTP
{

    // Constructor
    TcpServer::TcpServer(string ip, int port)
        : ip_addr(ip),
          m_port(port),
          m_socket(),
          new_socket(),
          incomming_msg(),
          sock_addr(),
          sock_addr_len(sizeof(sock_addr)),
          server_msg()
    {
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(m_port);
        sock_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
        startServer();
    }

    // Destructor
    TcpServer::~TcpServer()
    {
        closeServer();
    }

    // Start Server Method
    int TcpServer::startServer()
    {
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            exitWithError("Socket creation failed");
            return -1;
        }
        return 0;
    }

    // Bind the socket
    int TcpServer::bindSocket()
    {
        if (bind(m_socket, (sockaddr*) &sock_addr, sock_addr_len) < 0)
        {
            exitWithError("Cannot connect socket to address");
            return 1;
        }
        return 0;
    }

    int TcpServer::closeServer()
    {
        close(m_socket);
        close(new_socket);
        exit(0);
    }
}