#include <stdexcept>
#include <utility>

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "Server.hpp"

using namespace net::server;

static const int NUM_MAXIMUM_CONNECTION_BACKLOG = 100;

Server::Server(std::string ip_addr, int port) : m_IpAddr(std::move(ip_addr)), m_Port(port) {
    this->m_SockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->m_SockFd < 0)
        throw std::runtime_error("Failed to create socket!");
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    int ret_code = bind(this->m_SockFd, (sockaddr *) &server_addr, sizeof(server_addr));
    if (ret_code < 0)
        throw std::runtime_error("Failed to bind socket!");
}

std::unique_ptr<Connection> Server::Listen() {
    sockaddr_in client_addr;
    listen(this->m_SockFd, NUM_MAXIMUM_CONNECTION_BACKLOG);
    unsigned int addr_sz = sizeof(client_addr);
    int sockfd = accept(this->m_SockFd, (sockaddr *) &client_addr, &addr_sz);
    if (sockfd < 0)
        throw std::runtime_error("Failed to accept connection!");
    std::unique_ptr<Connection> connection(new Connection(this->m_IpAddr, this->m_Port, sockfd));
    return connection;
}