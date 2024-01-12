#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>

#define DEBUG false

template<typename T>
void print(T x) {
    if (!DEBUG) return;
    std::cout << x << std::endl;
}

template <typename T, typename... Rest>
void print(T x, Rest... rest) {
    if (!DEBUG) return;
    std::cout << x << " ";
    print(rest...);
}

#endif