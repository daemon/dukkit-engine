#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "Connection.hpp"

using namespace net;

static constexpr size_t READ_CHUNK_LENGTH = 2048;

Connection::~Connection() {
    // TODO
}

std::vector<uint8_t> Connection::Read() const {
    thread_local uint8_t buffer[READ_CHUNK_LENGTH];
    int n = read(this->m_SockFd, buffer, READ_CHUNK_LENGTH);
    std::vector<uint8_t> data(buffer, buffer + n);
    return data;
}
