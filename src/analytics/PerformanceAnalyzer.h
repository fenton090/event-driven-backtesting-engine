#ifndef PERFORMANCE_ANALYZER_H
#define PERFORMANCE_ANALYZER_H

#include <vector>

class PerformanceAnalyzer {
private:
    std::vector<double> portfolioValues;

public:
    void record(double value);

    double computeReturns() const;

    std:: vector<double> computeReturnSeries() const;

    double computeSharpeRatio(double riskFreeRate = 0.0) const;

    double computeMaxDrawdown() const;
};

#endif