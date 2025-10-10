#include<iostream>
using namespace std;

/*
 * Exercise 3: Heap-Based Linked List Implementation
 * 
 * This program demonstrates:
 * 1. Proper heap-based linked list creation
 * 2. Creating 1000 nodes using heap memory
 * 3. Returning head pointer from function
 * 4. Memory management concepts
 * 
 * Task Breakdown:
 * 1. Struct Node with constructor and destructor
 * 2. Create 1000 nodes and connect them
 * 3. Use heap memory for persistence
 * 4. Return head pointer to main
 * 5. Print all nodes
 */

struct Node {
    int data{0};
    Node* next{nullptr};

    ~Node() {
        cout << data << " is getting destructed!" << endl;
    }
};

/*
 * Operator Explanation:
 * -> is used when you have a pointer to a struct/class and want to access a member
 * .  is used when you have the actual object
 */

Node makeLL() {
    int start = 1;
    Node* head = new Node{start};      // First node
    Node* headPtr = new Node{0};       // Dummy head for easier management
    
    headPtr->next = head;  // Connect dummy head to first node
    
    // Create 1000 nodes
    for(int i = 0; i < 1000; i++) {
        start = start + 1;
        Node* newNode = new Node{start};
        
        // Connect current head to new node
        head->next = newNode;
        head = head->next;  // Move head pointer forward
    }
    
    return *headPtr;  // Return dummy head (contains pointer to first real node)
}

int main() {
    Node head = makeLL();
    
    cout << "Traversing 1000-node linked list:" << endl;
    int count = 0;
    
    // Traverse the linked list
    while(head.next != nullptr) {
        cout << "Node value is " << head.data << endl;
        head = *head.next;  // Move to next node
        count++;
        
        // Limit output for readability (uncomment to see all 1000 nodes)
        if(count >= 10) {
            cout << "... (showing first 10 nodes only)" << endl;
            break;
        }
    }
    
    cout << "\nTotal nodes created: 1000" << endl;
    cout << "Note: All nodes are heap-allocated and persist until program ends" << endl;
    
    return 0;
}

/*
 * Memory Analysis:
 * 
 * 1. Each Node occupies: sizeof(int) + sizeof(Node*) bytes
 * 2. 1000 nodes = 1000 * (4 + 8) = 12,000 bytes on heap
 * 3. Memory persists until program termination
 * 4. No automatic cleanup (memory leak if not managed properly)
 * 
 * Key Learning Points:
 * 1. Heap memory persists beyond function scope
 * 2. Dummy head pattern simplifies linked list operations
 * 3. Pointer arithmetic: head = head->next moves pointer forward
 * 4. Memory management is crucial for heap-allocated structures
 * 5. Large linked lists require careful memory planning
 */