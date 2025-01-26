#include <cstdint>
#include <iostream>

#include "lib.h"

double calculate_pi(const std::uint32_t num_iterations)
{
    double calculate=0;

    for (std::uint32_t n = 0; n <= num_iterations; n++)
    {
        calculate += ((1/(4*n+1)) - (1/(4*n+3)));
    }
    calculate*=4;
    return calculate;
}

void print_dec_to_bin(std::uint8_t value)
{
    std::uint32_t binary=0;
    while(value>0)
    {
        if (value%2 == 0)
        {
            binary*=10;
        }
        else
        {
            binary+=1;
        }
        value/=2;
    }

    std::cout << binary;
}
