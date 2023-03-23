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


#endif // STATISTICS_H
