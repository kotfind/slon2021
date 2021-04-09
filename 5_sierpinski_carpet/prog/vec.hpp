#ifndef VEC_H
#define VEC_H

#include <array>
#include <algorithm>
#include <array>
#include <cassert>

template<typename T, std::size_t DIM>
struct vec {
    T data[DIM];
    T &x = data[0];
    T &y = data[1];
    T &z = data[2];
    T &r = data[0];
    T &g = data[1];
    T &b = data[2];

    vec() {
        std::fill(data, data + DIM, T());
    }

    vec(const T &v) {
        std::fill(data, data + DIM, v);
    }

    vec(const vec<T, DIM> &v) {
        std::copy(v.data, v.data + DIM, data);
    }

    vec(const T (&list)[DIM]) {
        std::copy(list, list + DIM, data);
    }

    T& operator[](const size_t i) {
        assert(i < DIM && "Vector index is to big.");
        return data[i];
    }

    T operator[](const size_t i) const {
        assert(i < DIM && "Vector index is to big.");
        return data[i];
    }

    vec<T, DIM> operator=(const vec<T, DIM> &v) {
        std::copy(v.data, v.data + DIM, data);
        return *this;
    }
};

template<typename T, std::size_t DIM>
vec<T, DIM> operator+(const vec<T, DIM> &lhs, const vec<T, DIM> &rhs) {
    vec<T, DIM> ans;
    for (size_t i = 0; i < DIM; ++i) {
        ans[i] = lhs[i] + rhs[i];
    }
    return ans;
}

template<typename T, std::size_t DIM>
vec<T, DIM> operator*(const vec<T, DIM> &lhs, const T rhs) {
    vec<T, DIM> ans;
    for (size_t i = 0; i < DIM; ++i) {
        ans[i] = lhs[i] * rhs;
    }
    return ans;
}

template<typename T, std::size_t DIM>
vec<T, DIM> operator/(const vec<T, DIM> &lhs, const T rhs) {
    vec<T, DIM> ans;
    for (size_t i = 0; i < DIM; ++i) {
        ans[i] = lhs[i] / rhs;
    }
    return ans;
}

#endif
