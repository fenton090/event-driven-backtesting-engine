#include "MovingAverageCrossoverStrategy.h"

MovingAverageCrossoverStrategy::MovingAverageCrossoverStrategy(int shortW, int longW)
 : shortWindow(shortW), longWindow(longW) {}

std::shared_ptr<SignalEvent> MovingAverageCrossoverStrategy::onMarketEvent(std::shared_ptr<MarketEvent> event) {
    priceHistory.push_back(event->price);

    if(priceHistory.size() > longWindow) {
        priceHistory.pop_front();
    }

    if(priceHistory.size() < longWindow) {
        return nullptr;
    }

    double shortMA = computeMovingAverage(shortWindow);
    double longMA = computeMovingAverage(longWindow);

    if(!isInitialized) {
        prevShortMA = shortMA;
        prevLongMA = longMA;
        isInitialized = true;
        return nullptr;
    }

     // Crossover logic
     if(prevShortMA <= prevLongMA && shortMA > longMA) {
        prevShortMA = shortMA;
        prevLongMA = longMA;
        return std::make_shared<SignalEvent>(event->symbol, "BUY", event->timestamp);
    } else if(prevShortMA >= prevLongMA && shortMA < longMA) {
        prevShortMA = shortMA;
        prevLongMA = longMA;
        return std::make_shared<SignalEvent>(event->symbol, "SELL", event->timestamp);
    }

    prevShortMA = shortMA;
    prevLongMA = longMA;

    return nullptr;
}

double MovingAverageCrossoverStrategy::computeMovingAverage(int window) const {
    double sum = 0.0;
    for(int i = priceHistory.size() - window; i < priceHistory.size(); i++) {
        sum += priceHistory[i];
    }
    return sum / window;
}