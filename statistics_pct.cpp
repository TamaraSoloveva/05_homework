#include "statistics_pct.h"

void Pct::update(double next) {
    vect.push_back(next);
}


double Pct::eval() const {
    std::vector<double> vectCp = vect;
    sort(vectCp.begin(), vectCp.end());
    double proc = (double)pct/100 * vectCp.size();
    double ind = round(proc);
    if (ind >= vect.size())
        ind--;
    else if((ind > 0) && (ind < vect.size()))
        ind--;
    return vect.at(ind);
}


const char * Pct::name() const {
   return str.c_str();
}
