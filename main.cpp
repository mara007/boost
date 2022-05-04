#include <iostream>

#include "ranges/ranges.h"

int main(const int argc, const char* argv[]) {
    std::cout << "Hello world of BOOST\n";

    ranges_t<int> int_ranges, int_ranges2;
    std::cout << int_ranges << std::endl;

    int_ranges.add(0,5);
    int_ranges.add(6, 10);
    int_ranges.add(10, 16);
    std::cout << "ranges with data:" << int_ranges << std::endl;

    int_ranges.sub(3,9);
    std::cout << "ranges with subscracted data:" << int_ranges << std::endl;

    int_ranges2.add(1,3);
    int_ranges2.add(10, 11);
    int_ranges2.add(13, 15);
    std::cout << "ranges2 : " << int_ranges2 << std::endl;

    std::cout << "difference: " << int_ranges._ranges - int_ranges2._ranges << std::endl;

    return 0;
}