#pragma once

#include <cstring>
#include <type_traits>

/// Makes an operator== for all POD-Types
template <typename T>
typename std::enable_if<std::is_pod<T>::value, bool>::type
operator==(const T& a, const T& b) {
    return memcmp(&a, &b, sizeof(T)) == 0;
}

namespace std {
    template<typename T>
    class hash {
    public:
        typename std::enable_if<std::is_pod<T>::value, size_t>::type
        operator()(const T& x) const {
            // Probably sub-par, but should do for now...
            size_t result = 0;
            char* ptr = (char*)(&x);
            for (unsigned int index = 0; index < sizeof(T); ++index) {
                result ^= (ptr[index] << (index % 24));
            }
            return result;
        }
    };
}

template<typename T, typename U>
struct member_comparator {
    U T::*member_ptr;

    bool operator()(const T& lhs, const T& rhs) {
        return lhs.*member_ptr < rhs.*member_ptr;
    }
};

template<typename T, typename U>
member_comparator<T,U> by(U T::*member_ptr) {
    return {member_ptr};
}
