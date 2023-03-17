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

class Min : public IStatistics {
public:
  /*  Min() : m_min{std::numeric_limits<double>::min()} {
    }*/
    Min( const double val) : m_min{val} {
       }


    void update(double next) override {
        if (next < m_min) {
            m_min = next;
        }
    }

    double eval() const override {
        return m_min;
    }

    const char * name() const override {
        return "min";
    }

private:
    double m_min;
};

class Max : public IStatistics {
public:
   /* Max() : m_max{std::numeric_limits<double>::min()} {
    }*/
    Max( const double val ) : m_max(val) {

    }

    void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char * name() const override {
        return "max";
    }

private:
    double m_max;
};

class Mean : public IStatistics {
public:
    Mean() : sum(0), cnt(0) {

    }

    void update(double next) override {
        sum += next;
        cnt++;
    }

    double eval() const override {
        return sum/cnt;
    }

    const char * name() const override {
        return "mean";
    }

private:
    double sum;
    int cnt;
};

class Std : public IStatistics {
public:
    Std() : sum(0), cnt(0) {

    }

    void update(double next) override {
        sum += next;
        cnt++;
        vect.push_back(next);
    }

    double eval() const override {
        double mean =  sum/cnt;
        double sumSqrt = 0;
        for (int i=0; i<vect.size(); ++i) {
            sumSqrt += (vect.at(i) - mean) * (vect.at(i) - mean);
        }
        return std::sqrt(sumSqrt/vect.size());
    }

    const char * name() const override {
        return "Std";
    }

private:
    double sum;
    int cnt;
    std::vector<double> vect;

};

class Pct : public IStatistics {
public:
    Pct(const int &val) : pct(val) {

    }

    void update(double next) override {
        vect.push_back(next);
    }

    double eval() const override {
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

    const char * name() const override {
       std::string str = "pct ";
       str.append(std::to_string(pct));
       //вижу, что некорректно, но не понимаю почему
       // return str.c_str();
    }


private:
    int pct;
    std::vector<double> vect;


};


#endif // STATISTICS_H
