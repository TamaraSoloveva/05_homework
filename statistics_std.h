#ifndef STATISTICS_STD_H
#define STATISTICS_STD_H

#include "statistics.h"

//среднеквадратическое отклонение
class Std : public IStatistics {
public:
    Std() : sum(0), cnt(0) { }
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double sum;
    int cnt;
    std::vector<double> vect;
};

#endif // STATISTICS_STD_H
