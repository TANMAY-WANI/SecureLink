#ifndef INCLUDED_HTTP_TCPSERVER
#define INCLUDED_HTTP_TCPSERVER

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

using namespace std;

namespace HTTP{
    class TcpServer{
        public:
            TcpServer(string ip,int port);
            ~TcpServer();
        private:
                string ip_addr;
                int m_port;
                int m_socket;
                int new_socket;
                long incomming_msg;
                struct sockaddr_in sock_addr;
                unsigned int sock_addr_len;
                string server_msg;

                int startServer();
                int closeServer();
                int bindSocket();
                void listenSocket();
                void acceptConnection(int &new_socket);
    };
}
#endif
