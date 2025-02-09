#include <cstddef>
#include <cstdint>
#include <iostream>

#include "lib.h"

void remove_duplicates(std::int32_t *array, std::size_t &length)
{
    if (array == nullptr || length < 2)
    {
        return;
    }

    for (std::size_t i = 0; i < length; i++) //äußere Schleife, äußeres Schleifenelement welches gerade verglichen wird
    {
        for (std::size_t j = i + 1; j < length;
             j++) //innere Schleife, Elemente werden mit aüßerem Schleifenelement verglichen
        {
            if (array[i] == array[j]) //wenn Elemente gleich, dann length-- und alle nach links verschieben
            {
                length--;
                for (std::size_t k = j; k < length; k++)
                {
                    array[k] = array[k + 1];
                }
            }
        }
    }
}

void rotate_left(std::int32_t *array, std::size_t length)
{
    if (array == nullptr || length < 2)
    {
        return;
    }
    auto memory = array[0];
    for (std::size_t i = 0; i < length - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[length - 1] = memory;
}

void rotate_right(std::int32_t *array, std::size_t length)
{
    if (array == nullptr || length < 2)
    {
        return;
    }
    auto memory = array[length - 1];
    for (std::size_t i = length - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = memory;
}
