#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

class IStatistics {
public:
    virtual ~IStatistics() {}

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char * name() const = 0;


};

#endif // STATISTICS_H
