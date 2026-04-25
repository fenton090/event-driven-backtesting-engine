#ifndef FILL_EVENT_H
#define FILL_EVENT_H

#include <string>
#include "Event.h"

using namespace std;

class FillEvent : public Event{
public:
    string symbol;
    string orderType;
    int quantity;
    double price;
    string timestamp;

    FillEvent(const string symbol, const string orderType, int quantity, double price, const string timestamp) :
        symbol(symbol), orderType(orderType), quantity(quantity), price(price), timestamp(timestamp) {
            type = EventType::FILL;
    }
};

#endif