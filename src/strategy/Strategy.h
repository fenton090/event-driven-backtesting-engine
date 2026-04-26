#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>
#include "../events/MarketEvent.h"
#include "../events/SignalEvent.h"

using namespace std;

class Strategy {
public:
    virtual shared_ptr<SignalEvent> onMarketEvent(shared_ptr<MarketEvent> event) =0;

    virtual ~Strategy() {}
};

#endif