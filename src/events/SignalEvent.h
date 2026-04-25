#ifndef SIGNAL_EVENT_H
#define SIGNAL_EVENT_H

#include "Event.h"
#include <string>

class SignalEvent : public Event {
public:
    std::string symbol;
    std::string signalType; // BUY / SELL
    std::string timestamp;

    SignalEvent(const std::string& symbol,
                const std::string& signalType,
                const std::string& timestamp)
        : symbol(symbol), signalType(signalType), timestamp(timestamp) {
        type = EventType::SIGNAL;
    }
};

#endif