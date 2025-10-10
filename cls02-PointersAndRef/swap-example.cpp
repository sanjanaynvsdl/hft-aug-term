// ===========================
// CLASSIC SWAP FUNCTION WITH POINTERS
// ===========================
// Demonstrates the canonical use case for pass-by-reference:
// swapping two values requires modifying the original variables

#include<iostream>
using namespace std;

// ===========================
// EXAMPLE 1: SWAP FUNCTION
// ===========================
// Swaps the values of two integers using pointers
// This is the ONLY way to implement swap in C (before C++ references were added)

void swap(int *x, int *y) {
    // Store the original value of x in a temporary variable
    int prevX = *x;

    // Assign the value of y to x (dereference both pointers)
    *x = *y;

    // Assign the saved value of x to y
    *y = prevX;

    // Result: The values at the memory locations pointed to by x and y are swapped
};

// ===========================
// EXAMPLE 2: ORDER STRUCT WITH POINTERS
// ===========================
// Demonstrates pointer usage with structs and the arrow operator

struct Order {
    // Note: int32_t is a fixed-width integer type from <cstdint>
    // int32_t orderId;  // Requires #include <cstdint>
    int orderId;         // Standard int (platform-dependent size)
};

int main() {
    // ===========================
    // TEST SWAP FUNCTION
    // ===========================
    int x = 10;
    int y = 20;

    cout << "Values before swap - x: " << x << " y: " << y << endl;

    // Pass addresses of x and y to swap function
    // '&x' and '&y' get the memory addresses of these variables
    swap(&x, &y);

    // After swap, x and y have exchanged values
    cout << "Values after swap - x: " << x << " y: " << y << endl;
    // Output: x: 20  y: 10

    // ===========================
    // TEST POINTER WITH STRUCT
    // ===========================
    Order od1{1};           // Create an Order with orderId = 1
    Order* ptrO = &od1;     // Create a pointer to the Order

    // Access struct member through pointer using arrow operator
    cout << ptrO->orderId << endl;  // Output: 1

    // Alternative syntax (equivalent but more verbose):
    // cout << (*ptrO).orderId << endl;

    // ===========================
    // KEY TAKEAWAYS:
    // ===========================
    // 1. SWAP REQUIRES POINTERS:
    //    - Cannot swap with pass-by-value (would only swap copies)
    //    - Must use pointers (or C++ references) to modify originals
    //
    // 2. POINTER OPERATIONS:
    //    - '&variable' gets the address of a variable
    //    - '*pointer' dereferences to access/modify the value
    //    - 'pointer->member' accesses struct member through pointer
    //
    // 3. PRACTICAL USE IN HFT:
    //    - Modifying order book structures efficiently
    //    - Updating order states without copying entire structs
    //    - Essential for low-latency, high-performance systems

}

