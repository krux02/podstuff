
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
