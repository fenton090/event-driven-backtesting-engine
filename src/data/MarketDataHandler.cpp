#include "MarketDataHandler.h"
#include <sstream>
#include <iostream>

using namespace std;

MarketDataHandler::MarketDataHandler(const string& filename) {
    file.open(filename);

    if(!file.is_open()) {
        cerr<<"Error opening file\n";
    }

    std::string header;
    getline(file, header);
}

shared_ptr<MarketEvent> MarketDataHandler::getNextEvent() {
    string line;
    if(!getline(file, line)) {
        return nullptr;
    }

    stringstream ss(line);
    std::string date, open, high, low, close, volumestr;
    getline(ss, date, ',');
    getline(ss, open, ',');
    getline(ss, high, ',');
    getline(ss, low, ',');
    getline(ss, close, ',');
    getline(ss, volumestr, ',');

    if(close.empty() || volumestr.empty()) {
        return getNextEvent();
    }

    double price;
    long long volume;

    try {
        price = stod(close);
        volume = stoll(volumestr);
    } catch(const std::exception& e) {
        cerr<<"Error parsing line: " << line << "\n";
        return getNextEvent();
    }
    

    return make_shared<MarketEvent>("AAPL", price, volume, date);
}