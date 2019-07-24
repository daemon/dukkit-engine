#pragma once

#include <memory>
#include <string>

#include "Connection.hpp"

namespace net {
namespace server {

class Server {
public:
    Server(std::string ip_addr, int port);

    std::unique_ptr<Connection> Listen();

private:
    std::string m_IpAddr;
    int m_Port;
    int m_SockFd;
};

}
}