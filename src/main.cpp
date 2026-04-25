#include "events/BacktestEngine.h"

using namespace std;

int main() {
    BacktestEngine engine("data/data.csv");
    engine.run();
    
    return 0;
}
