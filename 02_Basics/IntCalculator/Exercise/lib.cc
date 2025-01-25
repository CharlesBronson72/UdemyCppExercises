#include <cstdint>

#include "lib.h"

std::uint32_t modulo(const std::uint32_t number_a, const std::uint32_t number_b)
{
    if (number_b > 0)
    {
        return number_a % number_b;
    }
    else return 0;
}

std::uint32_t sum_of_digits(const std::uint32_t number)
{
   /* if (number==0)
    {
        return 1;
    }*/

    std::uint32_t digits = 0;
    std::uint32_t number_loop = number;
    do
    {
        digits++;
        number_loop /= 10;
    }while(number_loop > 0);

    return digits;

}

std::uint32_t cross_sum(const std::uint32_t number)
{
    std::uint32_t cross_sumvar = 0;
    std::uint32_t number_loop = number;

    while (number_loop>0)
    {
        cross_sumvar+=number_loop%10;
        number_loop/=10;
    }

    return cross_sumvar;
}
