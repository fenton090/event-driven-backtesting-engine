#ifndef MARKET_EVENT_H
#define MARKET_EVENT_H

#include "Event.h"
#include <string>
using namespace std;

class MarketEvent : public Event {
public:
    string symbol;
    double price;
    int volume;
    string timestamp;

    MarketEvent(const string& symbol, double price, int volume, const string& timestamp)
        : symbol(symbol), price(price), volume(volume), timestamp(timestamp) {
        type = EventType::MARKET;
    }

};


#endif