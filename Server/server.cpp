#include <server.h>

using namespace HTTP;

int main(){
    TcpServer server = TcpServer("0.0.0.0",8080);
    return 0;
}