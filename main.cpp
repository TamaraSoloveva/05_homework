#include <iostream>
#include "statistics.h"

using namespace std;

int main()
{
    const size_t statistics_count = 6;
    IStatistics *statistics[statistics_count];

    double val = 0;

    int fl=1;

    while (std::cin >> val) {
        if (fl) {
            statistics[0] = new Min{val};
            statistics[1] = new Max{val};
            statistics[2] = new Mean{};
            statistics[3] = new Std{};
            statistics[4] = new Pct{40};
            statistics[5] = new Pct{95};
            fl=0;
        }
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        for (size_t i = 0; i < statistics_count; ++i) {
            delete statistics[i];
        }
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}
