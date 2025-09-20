- revision
- if i pass the pointer and dereference and change value, it will change 
- Return Value Optimization (RVO) is a compiler optimization technique in C++ that eliminates unnecessary copying of objects when they are returned from functions. The main purpose of RVO is to improve performance by reducing the number of copy operations.

Here's how it works:

Without RVO:
A function creates an object
The object is copied to a temporary location
The temporary object is then copied to the destination (e.g., a variable in the calling function)
With RVO:
The compiler optimizes the code to construct the object directly in the memory location where it will be used
This eliminates the need for intermediate copies
Use of RVO:

Improves performance by reducing unnecessary copy operations
Reduces memory usage
Makes code more efficient without changing its visible behavior
Example:

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {
        cout << "Node constructed" << endl;
    }

    ~Node() {
        cout << "Node destructed" << endl;
    }

    Node(const Node& other) : data(other.data), next(other.next) {
        cout << "Node copied" << endl;
    }
};

Node makeNode() {
    Node n(10);
    return n;
}

int main() {
    Node result = makeNode();
    cout << "Node data: " << result.data << endl;
    return 0;
}
Without RVO, you might expect this code to:

Construct a Node in makeNode()
Copy it when returning from makeNode()
Copy it again when assigning to result
However, with RVO, the compiler optimizes this process. It constructs the Node directly in the memory location of result, eliminating the need for any copies.

When you run this code with RVO (which is typically enabled by default in modern compilers), you'll see:

Node constructed
Node data: 10
Node destructed
Notice that there are no "Node copied" messages, indicating that RVO has eliminated the copy operations.

The instructor mentioned that you can disable this optimization using a compiler flag (-fno-elide-constructors in GCC), which would then show the copy operations:

Node constructed
Node copied
Node destructed
Node copied
Node destructed
Node data: 10
Node destructed
In summary, RVO is a powerful optimization technique that improves performance by eliminating unnecessary copy operations when returning objects from functions. It's typically enabled by default in modern C++ compilers, and developers can rely on it to write efficient code without worrying about the overhead of returning large objects by value.

- NRVO

- brk()
- mmap() -> memory map, region, 
- according to the memory needs the break point of stack and heap are managed, 
- brk(), mmap, we will use make memory sys calls

https://drive.google.com/file/d/1NXkNZXf0jYT_mkMe9kBFjsQknW07v8X9/view

gmeet recorded elcture, 
