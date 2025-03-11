#include "map_ex.hpp"

bool AddWord(DICT& dictionary, const std::string& input)
{
    bool result = dictionary.insert({input, input.size()}).second;
    return result;
}
