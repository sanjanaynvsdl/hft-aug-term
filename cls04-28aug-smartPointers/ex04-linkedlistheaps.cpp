#include<iostream>
using namespace std;

/*
 * Exercise 4: Advanced Heap-Based Linked List with Memory Analysis
 * 
 * This program demonstrates:
 * 1. Optimized heap-based linked list creation
 * 2. Memory system call analysis
 * 3. RVO (Return Value Optimization) concepts
 * 4. Memory fragmentation and malloc optimization
 * 5. Thread safety considerations
 */

struct Node {
    int data;
    Node* next;

    ~Node() {
        cout << data << " : is destructed!" << endl;
    }

    // Alternative constructor (commented out)
    // Node(int data, Node* head) {
    //     this->data = data;
    //     this->next = head;
    // }
};

/*
 * Optimized Linked List Creation
 * Returns pointer to head instead of copying entire structure
 */
Node* makeLinkedList() {
    int start = 1;
    Node* ptrHead = new Node{start};      // First real node
    Node* ptrDummyHead = new Node{0};     // Dummy head for easier management
    
    ptrDummyHead->next = ptrHead;        // Connect dummy to first node
    
    // Create 1000 nodes efficiently
    for(int i = 1; i <= 1000; i++) {
        start = start + 1;
        Node* newNode = new Node{start};
        
        ptrHead->next = newNode;          // Connect current node to new node
        ptrHead = ptrHead->next;          // Move pointer forward
    }
    
    return ptrDummyHead->next;  // Return pointer to first real node
}

int main() {
    Node* head = makeLinkedList();
    
    cout << "Traversing optimized linked list:" << endl;
    int count = 0;
    
    // Traverse using pointer notation
    while(head->next != nullptr) {
        cout << "Node value is: " << head->data << endl;
        head = head->next;  // Move to next node
        count++;
        
        // Limit output for readability
        if(count >= 10) {
            cout << "... (showing first 10 nodes only)" << endl;
            break;
        }
    }
    
    cout << "\n=== Memory Analysis ===" << endl;
    
    /*
     * System Call Analysis:
     * Question: How many system calls will this function make?
     * Expected: 1000 calls (one for each new Node)
     * Reality: Approximately 18 calls due to malloc optimization
     * 
     * Explanation:
     * - malloc() doesn't make a system call for every allocation
     * - It uses memory pools and pre-allocated chunks
     * - Reduces kernel context switching overhead
     */
    
    cout << "Expected system calls: 1000" << endl;
    cout << "Actual system calls: ~18 (due to malloc optimization)" << endl;
    
    /*
     * Memory Fragmentation Example:
     * 
     * Scenario: Memory boxes of different sizes
     * Boxes: [10][5][17][7] bytes
     * Objects: [2][5][4][1][7] bytes
     * 
     * After freeing object of size 5:
     * Memory: [10][0][17][7] bytes
     * 
     * Problem: Fragmented memory space
     * Solution: Memory pools in HFT systems
     */
    
    cout << "\n=== Memory Fragmentation Demo ===" << endl;
    cout << "Initial memory: [10][5][17][7] bytes" << endl;
    cout << "Objects to allocate: [2][5][4][1][7] bytes" << endl;
    cout << "After freeing size 5: [10][0][17][7] bytes" << endl;
    cout << "Result: Fragmented memory space" << endl;
    
    /*
     * malloc() Optimization Example:
     * 
     * Instead of:
     * 1. malloc(1GB)  -> System call 1
     * 2. free(1GB)    -> System call 2  
     * 3. malloc(500MB) -> System call 3
     * 
     * malloc() keeps freed memory for reuse:
     * 1. malloc(1GB)  -> System call 1
     * 2. free(1GB)     -> System call 2
     * 3. malloc(500MB) -> No system call (reuses freed memory)
     * 
     * Result: Reduced from 3 to 2 system calls
     */
    
    cout << "\n=== malloc() Optimization ===" << endl;
    cout << "Traditional approach: 3 system calls" << endl;
    cout << "Optimized approach: 2 system calls" << endl;
    cout << "HFT alternative: Specialized allocators (jemalloc, tcmalloc)" << endl;
    
    /*
     * Thread Safety Issues:
     * 
     * Problem: Multiple threads requesting memory simultaneously
     * - Both threads call malloc() at same time
     * - malloc() is centralized program
     * - Causes contention and performance issues
     * 
     * Solutions:
     * 1. Thread-local storage
     * 2. Lock-free allocators
     * 3. Memory pools per thread
     */
    
    cout << "\n=== Thread Safety ===" << endl;
    cout << "Problem: Multiple threads -> malloc() contention" << endl;
    cout << "Solutions: Thread-local storage, lock-free allocators" << endl;
    
    // Note: In real applications, you would clean up memory here
    // For demonstration purposes, we're leaving it allocated
    
    return 0;
}

/*
 * Key Learning Points:
 * 
 * 1. System Calls:
 *    - malloc() optimization reduces kernel calls
 *    - Memory pools improve allocation efficiency
 *    - HFT systems use specialized allocators
 * 
 * 2. Memory Fragmentation:
 *    - Occurs with variable-size allocations
 *    - Solved by memory pools and fixed-size blocks
 *    - Critical consideration in HFT systems
 * 
 * 3. Thread Safety:
 *    - malloc() is not thread-safe for high-frequency operations
 *    - Requires specialized solutions for multi-threaded environments
 * 
 * 4. Performance Optimization:
 *    - Minimize system calls
 *    - Use memory pools
 *    - Consider specialized allocators
 *    - Balance between memory usage and performance
 * 
 * 5. RVO and NRVO:
 *    - Return Value Optimization eliminates unnecessary copies
 *    - Named Return Value Optimization for named objects
 *    - Compiler optimizations improve performance
 */