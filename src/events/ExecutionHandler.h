#ifndef EXECUTION_HANDLER_H
#define EXECUTION_HANDLER_H

#include <string>
#include <memory>
#include <unordered_map>
#include "MarketEvent.h"
#include "OrderEvent.h"
#include "FillEvent.h"

using namespace std;

class ExecutionHandler {
private:
    unordered_map<string, double> latestPrices;

public:
    void onMarketEvent(shared_ptr<MarketEvent> event);

    shared_ptr<FillEvent> onOrderEvent(shared_ptr<OrderEvent> orderEvent);
};

#endif