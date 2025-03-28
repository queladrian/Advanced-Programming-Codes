#include <iostream>
#include <type_traits>
#include <concepts>

using namespace std;

// PART 1: BASIC TEMPLATE FUNCTIONS

// Task 1.1: Write a Simple Template Function
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// Task 1.2: Overload a Template Function
template <typename T>
T maxValue2(T a, T b, T c) {
    return maxValue(a, maxValue(b, c));
}

// PART 2: TEMPLATE SPECIALIZATION
// Task 2.1: Template Specialization for String Type

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

// PART 3: VARIADIC TEMPLATES

// Task 3.1: Write a Variadic Template Function
template <typename V>
void printAll(V v) {
    std::cout << v << " ";
}

template <typename V, typename... Args>
void printAll(V v, Args... args) {
    std::cout << v << " ";
    printAll(args...);
}

// Task 3.2: Variadic Template for Summation
template <typename S>
S sum(S s) {
    return s;
}

template <typename S, typename... Args>
S sum(S s, Args... args) {
    return s + sum(args...);
}

// PART 4: TEMPLATE METAPROGRAMMING

// Task 4.1: Compile-Time Factorial Using Templates
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

// Task 4.2: Fibonacci Series Using Template Metaprogramming
template <int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

// TEST
int main() {
    // Test Task 1.1
    std::cout << maxValue(129, 1082) << std::endl;
    std::cout << maxValue(32.56, 12.1002) << std::endl;
    std::cout << maxValue(std::string("computer"), std::string("lion")) << std::endl;

    // Test Task 1.2
    std::cout << maxValue2(12, 67, 31) << std::endl;
    std::cout << maxValue2(3.1416, 12.0009, 8.8888) << std::endl;

    // Test Task 2.1
    std::cout << add(13, 24) << std::endl;
    std::cout << add(2.5, 3.1) << std::endl;

    // Test Task 3.1
    printAll(11, 1.54, "Hello", 'c');
    std::cout << std::endl;

    // Test Task 3.2
    std::cout << sum(11, 42, 23, 94, 25) << std::endl;
    std::cout << sum(4.13, 22.89, 3.3) << std::endl;

    // Test Task 4.1
    constexpr int factorialResult = Factorial<5>::value;
    std::cout << factorialResult << std::endl;

    // Test Task 4.2
    constexpr int fibonacciResult = Fibonacci<10>::value;
    std::cout << fibonacciResult << std::endl;

    return 0;
}
