#ifndef STATISTICS_PCT_H
#define STATISTICS_PCT_H

#include "statistics.h"

//подсчёт процентилей, val - значение процентиля
class Pct : public IStatistics {
public:
    Pct(const int &val) : pct(val), str("pct ") {
        str.append(std::to_string(val)); }
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    int pct;
    std::vector<double> vect;
    std::string str;
};


#endif // STATISTICS_PCT_H
