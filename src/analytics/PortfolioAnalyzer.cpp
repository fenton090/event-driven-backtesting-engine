#include "PerformanceAnalyzer.h"

#include <cmath>

void PerformanceAnalyzer::record(double value) {
    portfolioValues.push_back(value);
}

double PerformanceAnalyzer::computeReturns() const {
    if(portfolioValues.size() < 2) return 0.0;

    double initialValue = portfolioValues.front();
    double finalValue = portfolioValues.back();

    return (finalValue - initialValue) / initialValue;
}

std::vector<double> PerformanceAnalyzer::computeReturnSeries() const {
    std::vector<double> returns;

    for(int i = 1; i < portfolioValues.size(); i++) {
        double prev = portfolioValues[i-1];
        double curr = portfolioValues[i];

        if(prev != 0) {
            returns.push_back((curr - prev) / prev);
        } else {
            returns.push_back(0.0);
        }
    }

    return returns;
}

double PerformanceAnalyzer::computeSharpeRatio(double riskFreeRate) const {
    auto returns = computeReturnSeries();

    if(returns.empty()) return 0.0;

    int sum = 0;
    for(double r : returns) {
        sum+=r;
    }

    // mean
    double avgReturn = sum / returns.size();
    
    double stdDev = 0.0;

    for(double r : returns) {
        stdDev += (r - avgReturn) * (r - avgReturn);
    }
    stdDev = sqrt(stdDev / returns.size());

    if(stdDev == 0) return 0.0;

    // Sharpe Ratio
    return (avgReturn - riskFreeRate) / stdDev;
}

double PerformanceAnalyzer::computeMaxDrawdown() const {
    double maxDrawdown = 0.0;
    double peak = portfolioValues.front();

    for(double value : portfolioValues) {
        if(value > peak) {
            peak = value;
        }

        double drawdown = (peak - value) / peak;
        if(drawdown > maxDrawdown) {
            maxDrawdown = drawdown;
        }
    }

    return maxDrawdown;
}