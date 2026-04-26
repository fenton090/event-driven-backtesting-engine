#ifndef BACKTEST_ENGINE_H
#define BACKTEST_ENGINE_H

#include "EventQueue.h"
#include "MarketDataHandler.h"
#include "Strategy.h"
#include "SimpleStrategy.h"
#include "Portfolio.h"
#include "ExecutionHandler.h"
#include "PerformanceAnalyzer.h"

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