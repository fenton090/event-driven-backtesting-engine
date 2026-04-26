#include "Portfolio.h"
#include <iostream>

using namespace std;

Portfolio::Portfolio(double initialCash) : cash(initialCash), initialCash(initialCash) {}

shared_ptr<OrderEvent> Portfolio::onSignalEvent(shared_ptr<SignalEvent> signal) {
    double allocation = 0.1;
    double price = latestPrices[signal->symbol];

    int quantity = static_cast<int>((cash*allocation)/price);

    if(signal->signalType == "BUY") {
        return make_shared<OrderEvent>(signal->symbol, "BUY", quantity, signal->timestamp);
    } else if(signal->signalType == "SELL"){
        return make_shared<OrderEvent>(signal->symbol, "SELL", quantity, signal->timestamp);
    }
    return nullptr;
}

void Portfolio::onMarketEvent(shared_ptr<MarketEvent> event) {
    latestPrices[event->symbol] = event->price;
}

void Portfolio::onFillEvent(shared_ptr<FillEvent> fill) {
    int quantity = fill->quantity;
    double cost = quantity*fill->price;

    if(fill->orderType == "BUY") {
        cash -= cost;
        positions[fill->symbol]+=quantity;
    } else if(fill->orderType == "SELL") {
        cash += cost;
        positions[fill->symbol]-=quantity;
    }

    cout << "Portfolio Update:\n";
    cout << "Cash: " << cash << "\n";
    cout << "Position (" << fill->symbol << "): "
        << positions[fill->symbol] << "\n";
    
}

double Portfolio::getPortfolioValue() const {
    double total = cash;

    for(const auto pair: positions) {
        const string &symbol = pair.first;
        int quantity = pair.second;

        if(latestPrices.find(symbol) != latestPrices.end()) {
            total += quantity * latestPrices.at(symbol);
        }
    }

    return total;
}

double Portfolio::getPnl() const {
    return getPortfolioValue() - initialCash;
}