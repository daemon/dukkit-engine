#pragma once

#include <cinttypes>
#include <string>
#include <utility>
#include <vector>

namespace net {

class Connection {
public:
    Connection(std::string ip_addr, int port, int sockfd) : 
        m_IpAddr(std::move(ip_addr)), 
        m_Port(port), 
        m_SockFd(sockfd) {}
    ~Connection();

    std::vector<uint8_t> Read() const;
    void Send(const std::vector<uint8_t> &buffer) const;
    void Close();

private:
    std::string m_IpAddr;
    int m_Port;
    int m_SockFd;
};

}