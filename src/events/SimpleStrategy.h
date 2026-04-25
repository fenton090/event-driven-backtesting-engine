#ifndef SIMPLE_STRATEGY_H
#define SIMPLE_STRATEGY_H

#include "Strategy.h"

using namespace std;

class SimpleStrategy : public Strategy {
public:
    shared_ptr<SignalEvent>  onMarketEvent(shared_ptr<MarketEvent> event) override {
        if(event->price <150) {
            return make_shared<SignalEvent>(event->symbol, "BUY", event->timestamp);
        } else if(event->price > 150) {
            return make_shared<SignalEvent>(event->symbol, "SELL", event->timestamp);
        }

        return nullptr;
    }


};

#endif