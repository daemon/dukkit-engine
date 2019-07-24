#pragma once

#include <string>
#include <vector>

#include "UUID.hpp"

namespace data {
namespace chat {

class ChatPlayer {
public:
    ChatPlayer(UUID4 uuid, std::vector<std::string> names = {});
};

}
}