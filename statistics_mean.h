#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include "statistics.h"

//арифметическое среднее, посчитанное на основе всех элементов последовательности
class Mean : public IStatistics {
public:
    Mean() : sum(0), cnt(0) { }
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double sum;
    int cnt;
};

#endif // STATISTICS_MEAN_H
