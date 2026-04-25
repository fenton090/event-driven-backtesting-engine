#ifndef ORDER_EVENT_H
#define ORDER_EVENT_H

#include "Event.h"
#include <string>

using namespace std;

class OrderEvent : public Event {
public: 
    string symbol;
    string orderType;
    int quantity;
    string timestamp;

    OrderEvent(const string symbol, const string orderType, int quantity, const string timestamp) :
        symbol(symbol), orderType(orderType), quantity(quantity), timestamp(timestamp) {
            type = EventType::ORDER;
        }
};

#endif