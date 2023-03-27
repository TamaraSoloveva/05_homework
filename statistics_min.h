#ifndef STATISTICS_MIN_H
#define STATISTICS_MIN_H

#include "statistics.h"

//поиск минимального значения из последовательности
class Min : public IStatistics {
public:
    Min( const double val) : m_min{val} { }
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double m_min;
};

#endif // STATISTICS_MIN_H
