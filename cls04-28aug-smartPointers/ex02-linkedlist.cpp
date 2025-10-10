#include<iostream>
using namespace std;

/*
 * Exercise 2: Stack-Based Linked List (Demonstrates Memory Issues)
 * 
 * This program shows why stack-based linked lists don't work properly:
 * 1. Stack memory gets destroyed when function returns
 * 2. Only the first node is accessible after function completion
 * 3. Demonstrates the need for heap-based linked lists
 */

struct Node {
    int data{0};
    Node* next{nullptr};

    ~Node() {
        cout << data << " this node is getting destroyed!" << endl;
    }
};

/*
 * Problem: Stack-based linked list creation
 * Why doesn't this delete node 10?
 * 
 * Output explanation:
 * 12 this node is getting destroyed!
 * 11 this node is getting destroyed!
 * 10
 * 0 this node is getting destroyed! -> This is head node 10, but value was overridden in loop
 */
Node makeLinkedList() {
    Node head;
    head.data = 10;

    Node next;
    next.data = 11;

    Node third;
    third.data = 12;

    head.next = &next;
    next.next = &third;

    return head;  // Only returns first node, others are lost
}

int main() {
    Node h = makeLinkedList();
    
    // Expected: h -> (10,next) -> (11,next) -> (12,next) -> nullptr
    // Reality: Only first node accessible, others destroyed
    
    // Memory explanation:
    // 1. Stack memory created: main() -> makeLinkedList()
    // 2. All memory vanishes when makeLinkedList() completes execution
    // 3. Only the first node is copied to 'h', rest are lost
    
    cout << "Traversing linked list:" << endl;
    while(h.next != nullptr) {
        cout << h.data << endl;
        h = *h.next;  // Dereference pointer to get next node
    }
    cout << h.data << endl;  // Print last node
    
    // Heap Memory Introduction
    cout << "\n=== Heap Memory Example ===" << endl;
    
    // Stack vs Heap Memory Comparison:
    /*
     * Stack Memory:
     * - Limited size
     * - Fast access (no system calls)
     * - Automatic cleanup
     * - Preferred in HFT systems
     * 
     * Heap Memory:
     * - Larger size available
     * - Slower access (requires kernel calls)
     * - Manual management required
     * - Context switching overhead
     */
    
    // HFT Design Pattern:
    /*
     * Instead of multiple small heap allocations:
     * 1. Get a big chunk of memory at start
     * 2. Manage it manually
     * 3. Reduce system calls
     */
    
    // Heap allocation example
    Node* ptrNode = new Node{10};
    cout << "Heap-allocated node data: " << ptrNode->data << endl;
    
    // Important: Clean up heap memory
    delete ptrNode;
    
    return 0;
}

/*
 * Key Learning Points:
 * 1. Stack-based linked lists don't work for returning multiple nodes
 * 2. Stack memory is destroyed when function scope ends
 * 3. Heap memory persists until manually freed
 * 4. HFT systems prefer stack memory for speed
 * 5. Always clean up heap-allocated memory
 * 6. Context switching makes heap operations slower
 */