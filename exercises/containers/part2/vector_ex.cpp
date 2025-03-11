#include "vector_ex.hpp"

// std::vector documentation:
// https://en.cppreference.com/w/cpp/container/vector

std::vector<int> GetEven(std::vector<int> const& source) {
    std::vector<int> evens;

    for (const int& elem: source)
        if (elem % 2 == 0)
            evens.push_back(elem);

    return evens;
}

void PrintVectorOfInt(std::ostream& output, std::vector<int> const& data)
{
    output << "[ ";
    bool first = true;
    for (auto const& x: data) {
        if (!first) {
            output << ", ";
        }
        first = false;
        output << x;
    }
    output << "]";
}
