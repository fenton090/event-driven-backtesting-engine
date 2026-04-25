#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <memory>
#include <unordered_map>
#include "OrderEvent.h"
#include "SignalEvent.h"
#include "MarketEvent.h"
#include "FillEvent.h"

using namespace std;

class Portfolio {
private:
    double cash;
    double initialCash;
    unordered_map<string, int> positions;
    unordered_map<string, double> latestPrices;

public:
    Portfolio(double initialCash);

    shared_ptr<OrderEvent> onSignalEvent(shared_ptr<SignalEvent> signal);

    void onMarketEvent(shared_ptr<MarketEvent> event);

    void onFillEvent(shared_ptr<FillEvent> fill);

    double getPortfolioValue() const;

    double getPnl() const;

};

#endif