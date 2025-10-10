#include<iostream>
using namespace std;

/*
 * Exercise 1: Dynamic Memory Allocation and Matrix Operations
 * 
 * This program demonstrates:
 * 1. Heap vs Stack memory allocation
 * 2. Dynamic matrix creation using pointers
 * 3. Diagonal element extraction from a matrix
 */

int main() {
    // Heap Memory Allocation
    int* arr = new int[15];  // Allocated on heap memory
    // Note: Whenever we use 'new' or 'malloc', memory comes from heap
    
    // Stack Memory Allocation
    int arr2[15];  // Allocated on stack memory
    
    // Matrix Concept: Array of Arrays
    // In memory terms: Matrix = Pointers to array of pointers
    
    // Exercise: Create M x N matrix dynamically
    int M, N;
    cout << "Enter matrix dimensions (M x N): ";
    cin >> M >> N;
    
    // Single row allocation (not used in final solution)
    int* row = new int[M];   // Array of integers
    int* row2 = new int[M];
    
    // Dynamic Matrix Allocation
    // Step 1: Create array of pointers (rows)
    int** matrix = new int*[N];  // Array of pointers
    
    // Step 2: Allocate memory for each row
    for(int i = 0; i < N; i++) {
        matrix[i] = new int[M];  // Each row gets M integers
    }
    
    // Alternative matrix for diagonal demonstration
    int** matrix2 = new int*[N];
    for(int i = 0; i < N; i++) {
        matrix2[i] = new int[M];
    }
    
    // Input matrix elements
    cout << "Enter " << N << "x" << M << " matrix elements:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    // Print diagonal elements
    cout << "Diagonal elements:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == j) {
                cout << matrix2[i][j] << " ";
            } else {
                cout << "  ";  // Space for non-diagonal elements
            }
        }
        cout << endl;
    }
    
    
}

/*
 * Key Learning Points:
 * 1. Heap memory requires manual management (new/delete)
 * 2. Stack memory is automatically managed
 * 3. Dynamic matrices require two-step allocation
 * 4. Always clean up heap memory to prevent leaks
 * 5. Matrix[i][j] access pattern for 2D arrays
 */