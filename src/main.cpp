#include "engine/BacktestEngine.h"

using namespace std;

int main() {
    BacktestEngine engine("data/data_apple.csv");
    engine.run();
    
    return 0;
}
