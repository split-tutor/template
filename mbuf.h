// mbuf.h - generic buffer implementation
#include <iostream>
#include <stdlib.h>

template <typename T, typename U>
struct Tuple {
    T fst;
    U snd;

    Tuple() = default;
    Tuple(T t, U u) : fst(t), snd(u) {}
    Tuple(const Tuple<T, U>& t) = default;
    Tuple(Tuple<T, U>&& t) = default;

    Tuple<T, U>& operator=(const Tuple& rhs)
    {
        fst = rhs.fst;
        snd = rhs.snd;
        return *this;
    }
};

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const Tuple<T, U>& t)
{
    os << '(' << t.fst << ", " << t.snd << ')';
}

template <typename T>
struct Buf {
    T* buf;
    size_t cap;
    size_t len;

    static const size_t DEFAULT_CAP = 8;
    Buf(): buf(new T[DEFAULT_CAP]), cap(DEFAULT_CAP), len(0) {}
    explicit Buf(size_t c) : buf(new T[c]), cap(c), len(0) {}
    Buf(const Buf<T>& b) : buf(new T[b.cap]), cap(b.cap), len(b.cap)
    {
        for (size_t i = 0; i < b.cap; i++) {
            buf[i] = b.buf[i];
        }
    }
    ~Buf() { delete[] buf; }

    T& operator[](size_t n);
    const T& operator[](size_t n) const;
};

template <typename T>
T& Buf<T>::operator[](size_t n)
{
    if (n >= cap) {
        std::cout << "Error: Out of Bound";
        exit(EXIT_FAILURE);
    } else if (n >= len) {
        len = n + 1;
        return *(buf + n);
    } else {
        return *(buf + n);
    }
}

template <typename T>
const T& Buf<T>::operator[](size_t n) const
{
    if (n >= cap) {
        std::cout << "Error: Out of Bound";
        exit(EXIT_FAILURE);
    } else if (n >= len) {
        len = n + 1;
        return *(buf + n);
    } else {
        return *(buf + n);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Buf<T>& b)
{
    os << '[';
    for (size_t i = 0; i < b.len - 1; i++) {
        os << b.buf[i] << ", ";
    }
    os << b.buf[b.len - 1] << ']';
    return os;
}