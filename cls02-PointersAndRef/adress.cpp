#include<iostream>
using namespace std;

int main() {
    // BASIC POINTER SYNTAX
    // int x = 10;
    // int y = &x;  // ERROR: Cannot assign address (pointer) to an integer
    //
    // We need a pointer type to store an address:
    // int* y = &x;  // Correct: 'y' is a pointer to int, stores address of 'x'

    // INTEGER EXAMPLE: Basic pointer operations
    int x = 10;
    int* ptrX = &x;  // ptrX stores the memory address of x

    cout << "X value is: " << x << endl;           // Prints the value: 10
    cout << "Address of X is: " << ptrX << endl;   // Prints memory address (hex format)
    cout << "Dereferenced value: " << *ptrX << endl;  // '*' operator: dereferences pointer to get value at address

    // CHAR EXAMPLE: Important corner case for printing
    // Note: cout treats char* as a C-string, not as an address
    char a = 'b';
    char* ptrA = &a;
    cout << "Value of a is: " << a << endl;
    cout << "Address of char is: " << ptrA << endl;  // May print garbage as cout expects null-terminated string
    cout << "Value from address: " << *ptrA << endl; // Dereference to get the actual char value

    // DOUBLE EXAMPLE: Pointer with floating-point type
    double num = 34.5;
    double* ptrNum = &num;  // Pointer to double
    cout << "Double example -> " << num << " address -> " << ptrNum << endl;
    cout << "Dereferenced value is: " << *ptrNum << endl;

    // KEY TAKEAWAYS:
    // 1. Pointers store memory addresses
    // 2. '&' operator gets the address of a variable
    // 3. '*' operator dereferences a pointer (gets value at that address)
    // 4. Pointer type must match the variable type (int*, char*, double*, etc.)

}