#ifndef MARKET_DATA_HANDLER_H
#define MARKET_DATA_HANDLER_H

#include <fstream>
#include <memory>
#include "../events/MarketEvent.h"

using namespace std;

class MarketDataHandler {
private:
    ifstream file;

public:
    MarketDataHandler(const string& fileName);

    shared_ptr<MarketEvent> getNextEvent();

};


#endif