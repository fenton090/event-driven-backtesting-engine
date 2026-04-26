#include "../events/BacktestEngine.h"
#include <iostream>

using namespace std;

BacktestEngine::BacktestEngine(const string& dataFile) : dataHandler(dataFile) {
    strategy = make_unique<SimpleStrategy> ();
    portfolio = make_unique<Portfolio> (10000.0);
    execution = make_unique<ExecutionHandler> ();
    performanceAnalyzer = make_unique<PerformanceAnalyzer> ();
}

void BacktestEngine::run() {
    while(true) {
        auto marketEvent = dataHandler.getNextEvent();

        if(!marketEvent) break;
        eventQueue.push(marketEvent);

        while(!eventQueue.empty()) {
            auto event = eventQueue.pop();

            if(event->type == EventType::MARKET) {
                auto me = static_pointer_cast<MarketEvent>(event);

                portfolio->onMarketEvent(me);
                execution->onMarketEvent(me);

                double value = portfolio->getPortfolioValue();
                performanceAnalyzer->record(value);

                std::cout<< "Portfolio sharpe ratio: " << performanceAnalyzer->computeSharpeRatio() << "\n";
                std::cout<< "Max drawdown: " << performanceAnalyzer->computeMaxDrawdown() << "\n";

                std::cout << "PnL: " << portfolio->getPnl() << "\n";
                std::cout << "----------------------\n";

                auto signal = strategy->onMarketEvent(me);

                if(signal) eventQueue.push(signal);
            }else if(event->type == EventType::SIGNAL) {
                auto se = static_pointer_cast<SignalEvent>(event);

                auto order = portfolio->onSignalEvent(se);

                if(order) {
                    eventQueue.push(order);
                }

            } else if(event->type == EventType::ORDER) {
                auto oe = static_pointer_cast<OrderEvent>(event);

                auto fill = execution->onOrderEvent(oe);

                if(fill) {
                    eventQueue.push(fill);
                }
            } else if(event->type == EventType::FILL) {
                auto fe = static_pointer_cast<FillEvent>(event);

                portfolio->onFillEvent(fe);

                
            }
        }
    }
}