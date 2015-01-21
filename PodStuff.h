#pragma once

#include <cstring>
#include <type_traits>

/// Makes an operator== only for POD-Types
template <typename T>
typename std::enable_if<std::is_pod<T>::value, bool>::type
operator==(const T& a, const T& b)
{
    bool result = memcmp(&a, &b, sizeof(T)) == 0;
    return result;
}


namespace std
{
    template<typename T>
    class hash {
    public:
        typename std::enable_if<std::is_pod<T>::value, size_t>::type
        operator()(const T& x) const
        {
            // Probably sub-par, but should do for now...

            size_t result = 0;
            char* ptr = (char*)(&x);

            for (unsigned int index = 0; index < sizeof(T); ++index)
            {
                result ^= (ptr[index] << (index % 24));
            }

            return result;
        }
    };
}
