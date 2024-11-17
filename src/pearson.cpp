#include <pearson.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

double Correlations::pearsonCorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Vectors must have the same length.");
    }
    if (x.empty()) {
        throw std::invalid_argument("Vectors must not be empty.");
    }

    size_t n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    for (size_t i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double numerator = n * sumXY - sumX * sumY;
    double denominator = std::sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

    if (denominator == 0) {
        throw std::runtime_error("Denominator is zero, correlation is undefined.");
    }

    return numerator / denominator;
}

