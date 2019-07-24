#pragma once

namespace event {

class MessageHandler {
public:
    virtual void OnEvaluateSentiment(data::chat::ChatGraph) = 0;
};

}
