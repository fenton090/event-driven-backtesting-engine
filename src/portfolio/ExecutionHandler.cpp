#include "../events/ExecutionHandler.h"

using namespace std;

void ExecutionHandler::onMarketEvent(shared_ptr<MarketEvent> event) {
    latestPrices[event->symbol] = event->price;
}

shared_ptr<FillEvent> ExecutionHandler::onOrderEvent(shared_ptr<OrderEvent> order) {
    double price = latestPrices[order->symbol];

    return make_shared<FillEvent> (
        order->symbol,
        order->orderType,
        order->quantity,
        price,
        order->timestamp
    );
}