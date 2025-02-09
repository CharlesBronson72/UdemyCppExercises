#include <cstddef>

#include "lib.h"

/** START PREV FUNCS **/

bool is_upper_case(const char character)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return true;
    }

    return false;
}

bool is_lower_case(const char character)
{
    if ((character >= 'a') && (character <= 'z'))
    {
        return true;
    }

    return false;
}

bool is_numeric(const char character)
{
    if ((character >= '0') && (character <= '9'))
    {
        return true;
    }

    return false;
}

bool is_alpha(const char character)
{
    if (is_upper_case(character) || is_lower_case(character))
    {
        return true;
    }

    return false;
}

bool is_alpha_numeric(const char character)
{
    return is_numeric(character) || is_alpha(character);
}

char to_upper_case(const char character)
{
    if (is_lower_case(character))
    {
        return character - 32;
    }

    return character;
}

char to_lower_case(const char character)
{
    if (is_upper_case(character))
    {
        return character + 32;
    }

    return character;
}


/** END PREV FUNCS **/

char *to_upper_case(char *text)
{
    if (text == nullptr)
    {
        return nullptr;
    }

    auto *currenttext = new char[static_cast<unsigned long>(string_length(text))];

    int length = 0;
    while (*(text + length) != '\0')
    {
        *(currenttext + length) = *(text + length);
        length++;
    }

    length = 0;
    while (*(currenttext + length) != '\0')
    {
        if (is_lower_case(*(currenttext + length)))
        {
            *(currenttext + length) = to_upper_case(*(currenttext + length));
        }
        length++;
    }

    return currenttext;
}

char *to_lower_case(char *text)
{
    if (text == nullptr)
    {
        return nullptr;
    }

    auto *currenttext = new char[static_cast<unsigned long>(string_length(text))];

    int length = 0;
    while (*(text + length) != '\0')
    {
        *(currenttext + length) = *(text + length);
        length++;
    }

    length = 0;
    while (*(currenttext + length) != '\0')
    {
        if (is_upper_case(*(currenttext + length)))
        {
            *(currenttext + length) = to_lower_case(*(currenttext + length));
        }
        length++;
    }


    return currenttext;
}

std::size_t string_length(const char *text)
{
    if (text == nullptr)
    {
        return 0;
    }
    std::size_t counter = 0;
    while (*text != '\0')
    {
        text++;
        counter++;
    }
    return counter;
}

bool string_equal(const char *string1, const char *string2)
{
    if (string1 == nullptr || string2 == nullptr)
    {
        return false;
    }
    while (*string1 != '\0' || *string2 != '\0')
    {
        if (*string1 != *string2)
        {
            return false;
        }
        string1++;
        string2++;
    }
    return true;
}
