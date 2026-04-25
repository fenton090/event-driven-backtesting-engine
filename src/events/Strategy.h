#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>
#include "MarketEvent.h"
#include "SignalEvent.h"

using namespace std;

class Strategy {
public:
    virtual shared_ptr<SignalEvent> onMarketEvent(shared_ptr<MarketEvent> event) =0;

    virtual ~Strategy() {}
};

#endif