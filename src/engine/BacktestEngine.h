#ifndef BACKTEST_ENGINE_H
#define BACKTEST_ENGINE_H

#include "../events/EventQueue.h"
#include "../data/MarketDataHandler.h"
#include "../strategy/Strategy.h"
#include "../strategy/SimpleStrategy.h"
#include "../portfolio/Portfolio.h"
#include "../execution/ExecutionHandler.h"
#include "../analytics/PerformanceAnalyzer.h"

using namespace std;

class BacktestEngine {
private:
    EventQueue eventQueue;
    MarketDataHandler dataHandler;
    unique_ptr<Strategy> strategy;
    unique_ptr<Portfolio> portfolio;
    unique_ptr<ExecutionHandler> execution;
    unique_ptr<PerformanceAnalyzer> performanceAnalyzer;

public:
    BacktestEngine(const string& dataFile);
    
    void run();
};

#endif