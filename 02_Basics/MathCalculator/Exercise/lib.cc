#include <cstdint>
#include <iostream>

#include "lib.h"

double calculate_pi(const std::uint32_t num_iterations)
{
    double calculate=0;

    for (std::uint32_t n = 0; n <= num_iterations; n++)
    {
        calculate += (( 1.0 / (4.0 * n + 1.0) ) - ( 1.0 / (4.0 * n + 3.0) ));
    }
    return calculate*4;
}

void print_dec_to_bin(std::uint8_t value)
{
    std::cout << "Die Dezimalzahl : " << static_cast<std::uint32_t>(value) << " in binär ist : 0b";
    for (std::int8_t exponent = 7; exponent >= 0; exponent--)
    {
        std::uint8_t exponenti8 = static_cast<std::uint8_t>(std::pow(2,exponent));

        if (value >= exponenti8)
        {
            std::cout << "1";
            value -= exponenti8;
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << "\n\n";
}
