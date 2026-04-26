#ifndef MOVING_AVERAGE_CROSSOVER_STRATEGY_H
#define MOVING_AVERAGE_CROSSOVER_STRATEGY_H

#include "Strategy.h"
#include <deque>

class MovingAverageCrossoverStrategy : public Strategy {
private:
    int shortWindow;
    int longWindow;
    std::deque<double> priceHistory;

    double prevShortMA = 0.0;
    double prevLongMA = 0.0;
    bool isInitialized = false;

public:
    MovingAverageCrossoverStrategy(int shortW, int longW);

    std::shared_ptr<SignalEvent> onMarketEvent(std::shared_ptr<MarketEvent> event) override;

private:
    double computeMovingAverage(int window) const;
};

#endif