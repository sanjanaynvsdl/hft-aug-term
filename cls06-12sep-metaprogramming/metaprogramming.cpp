#include<iostream>
using namespace std;

// ============================================================================
// TEMPLATE METAPROGRAMMING
// ============================================================================
// Metaprogramming: Code that generates/manipulates code at COMPILE TIME
// Benefits: Zero runtime overhead, perfect for HFT
// ============================================================================

// ----------------------------------------------------------------------------
// FACTORIAL: N! = N * (N-1) * ... * 2 * 1
// ----------------------------------------------------------------------------
template<int N>
struct Factorial {
    static constexpr int value = Factorial<N-1>::value * N;  // Recursive case
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;  // Base case: 0! = 1
};

// How it works for Factorial<5>::value:
// Factorial<5> = Factorial<4> * 5
// Factorial<4> = Factorial<3> * 4
// ...continues until Factorial<0> = 1
// Result: 1 * 2 * 3 * 4 * 5 = 120 (computed at compile time!)

// ----------------------------------------------------------------------------
// FIBONACCI: F(N) = F(N-1) + F(N-2)
// ----------------------------------------------------------------------------
template<int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0> {
    static constexpr int value = 0;  // Base case 1
};

template<>
struct Fibonacci<1> {
    static constexpr int value = 1;  // Base case 2
};

// Fibonacci<4> = Fibonacci<3> + Fibonacci<2>
//              = (Fibonacci<2> + Fibonacci<1>) + (Fibonacci<1> + Fibonacci<0>)
//              = (1 + 1) + (1 + 0) = 3

// ----------------------------------------------------------------------------
// ALTERNATIVE FACTORIAL (base case at 1 instead of 0)
// ----------------------------------------------------------------------------
template<int N>
struct Fact {
    static constexpr int value = Fact<N-1>::value * N;
};

template<>
struct Fact<1> {
    static constexpr int value = 1;  // Base case: 1! = 1
};

// ----------------------------------------------------------------------------
// GCD: Greatest Common Divisor using Euclidean algorithm
// ----------------------------------------------------------------------------
template<int A, int B>
struct GCD {
    constexpr static int value = GCD<B, A % B>::value;  // GCD(A,B) = GCD(B, A%B)
};

template<int A>
struct GCD<A, 0> {
    constexpr static int value = A;  // Base case: GCD(A, 0) = A
};

// Example: GCD<12, 8>
// GCD(12, 8) -> GCD(8, 4) -> GCD(4, 0) -> 4

int main() {
    // constexpr: Forces compile-time evaluation (not runtime)
    constexpr int N = 5;  // Compile-time constant (in binary, not on stack)

    cout << "Factorial(" << N << ") = " << Fact<N>::value << endl;
    // Output: 120 (computed at compile time, embedded as constant)

    // Template instantiation process:
    // 1. Compiler creates Fact<5>, Fact<4>, Fact<3>, Fact<2>, Fact<1>
    // 2. Substitutes values: 1 * 2 * 3 * 4 * 5 = 120
    // 3. Replaces Fact<5>::value with 120 in binary
    // See all templates at: https://cppinsights.io

    cout << "Fibonacci(4) = " << Fibonacci<4>::value << endl;  // Output: 3

    cout << "GCD(10, 12) = " << GCD<10, 12>::value << endl;  // Output: 2

    // ========================================================================
    // WHY static constexpr?
    // ========================================================================
    // static: Value belongs to TYPE, not objects - access as Fact<5>::value
    // constexpr: Computed at compile time, not runtime
    // Together: Compile-time constant associated with template type

    // ========================================================================
    // HFT PERFORMANCE IMPLICATIONS
    // ========================================================================
    // Runtime factorial(5): ~10-20 nanoseconds (function call + computation)
    // Compile-time Fact<5>::value: 0 nanoseconds (it's just the number 120)
    //
    // Trade-offs:
    // + Zero runtime cost
    // + Results embedded as constants
    // + Type safe
    // - Slower compilation
    // - Larger binaries
    // - Only works with compile-time known values

    return 0;
}

// ============================================================================
// KEY TAKEAWAYS
// ============================================================================
// 1. Template metaprogramming = compile-time computation
// 2. Uses recursive templates + specialization for base cases
// 3. constexpr ensures compile-time evaluation
// 4. static makes values accessible without instantiation
// 5. Perfect for HFT - zero runtime cost
// 6. Modern C++20: use constexpr functions instead (cleaner syntax)
