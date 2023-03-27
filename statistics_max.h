#ifndef STATISTICS_MAX_H
#define STATISTICS_MAX_H

#include "statistics.h"

//максимальное значение из последовательности
class Max : public IStatistics {
public:
    Max( const double val ) : m_max(val) { }
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double m_max;
};

#endif // STATISTICS_MAX_H
