#include "statistics_std.h"

void Std::update(double next) {
    sum += next;
    cnt++;
    vect.push_back(next);
}

double Std::eval() const {
    double mean =  sum/cnt;
    double sumSqrt = 0;
    for (size_t i=0; i<vect.size(); ++i) {
        sumSqrt += (vect.at(i) - mean) * (vect.at(i) - mean);
    }
    return std::sqrt(sumSqrt/vect.size());
}

const char * Std::name() const {
    return "Std";
}
