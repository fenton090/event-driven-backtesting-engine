#include "../events/MarketDataHandler.h"
#include <sstream>
#include <iostream>

using namespace std;

MarketDataHandler::MarketDataHandler(const string& filename) {
    file.open(filename);

    if(!file.is_open()) {
        cerr<<"Error opening file\n";
    }
}

shared_ptr<MarketEvent> MarketDataHandler::getNextEvent() {
    string line;
    if(!getline(file, line)) {
        return nullptr;
    }

    stringstream ss(line);
    string symbol, pricestr, volumestr, timestamp;
    getline(ss, symbol, ',');
    getline(ss, pricestr, ',');
    getline(ss, volumestr, ',');
    getline(ss, timestamp, ',');

    double price = stod(pricestr);
    long long volume = stoll(volumestr);

    return make_shared<MarketEvent>(symbol, price, volume, timestamp);
}