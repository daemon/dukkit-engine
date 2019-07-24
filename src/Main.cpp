#include "RestfulServer.hpp"
#include "Server.hpp"

int main() {
    net::server::Server server{"0.0.0.0", 7777};
    server.Listen();
}
