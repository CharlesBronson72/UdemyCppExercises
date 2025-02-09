#include <cstddef>
#include <cstdint>

#include "lib.h"

bool all_of(const std::int32_t *array,
            const std::size_t length,
            const std::int32_t value)
{
    if (array!=nullptr && length>0)
    {
        std::int32_t counttruevalue = 0;
        for (std::int32_t i = 0; i < length; i++)
        {
            if (array[i] == value) counttruevalue++;
        }

        return ((counttruevalue==length-1) ? (true):(false));
    }

    return false;
}

bool any_of(const std::int32_t *array,
            const std::size_t length,
            const std::int32_t value)
{
    if (array!=nullptr && length>0)
    {
        for (std::int32_t i = 0; i < length; i++)
        {
            if (array[i] == value) return true;
        }

        return false;
    }

    return false;
}

bool none_of(const std::int32_t *array,
             const std::size_t length,
             const std::int32_t value)
{
    if (array!=nullptr && length>0)
    {
        for (std::int32_t i = 0; i < length; i++)
        {
            if (array[i] == value) return false;
        }

        return true;
    }

    return false;
}

std::size_t count(const std::int32_t *array,
                  const std::size_t length,
                  const std::int32_t value)
{
    if (array!=nullptr && length>0)
    {
        std::int32_t counttruevalue = 0;
    for (std::int32_t i = 0; i < length; i++)
    {
        if (array[i] == value) counttruevalue++;
    }

    return counttruevalue;
    }

    return 100;
}
