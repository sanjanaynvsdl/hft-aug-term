#include<iostream>
#include<cstdint>
#include <vector>
using namespace std;

// ============================================================================
// INHERITANCE IN C++
// ============================================================================
// Demonstrates: Inheritance, Object Slicing, Upcasting/Downcasting
// ============================================================================

// Base class representing a generic order


class Order {
    public:
        int32_t id;  // 4 bytes

        // Non-virtual function - always calls Order version when through pointer
        bool cancelOrder() {
            cout << "Order::cancelOrder() - no idea" << endl;
            return false;
        }

        // Virtual destructor ensures proper cleanup of derived classes
        // virtual ~Order() = default;
};

// Derived class: Good Till Cancelled order
class GTC: public Order {  // Size: 8 bytes (4 from parent id + 4 orderTime)
    public:
        int orderTime;  // 4 bytes

        // Shadows base class function (not virtual override)
        bool cancelOrder() {
            cout << "GTC::cancelOrder() - yes" << endl;
            return true;
        }
};

// Derived class: Immediate Or Cancel order
class IOC: public Order {  // Size: 8 bytes (4 from parent id + 4 cancelTime)
    public:
        int cancelTime;  // 4 bytes

        bool cancelOrder() {
            cout << "IOC::cancelOrder() - Not cancellable" << endl;
            return false;
        }
};

// Memory layout visual: GTC object
// Bytes: 0-3: id (inherited) | 4-7: orderTime | Total: 8 bytes

int main() {
    GTC gtc{10};
    IOC ioc{100};

    // ========================================================================
    // PROBLEM 1: OBJECT SLICING
    // ========================================================================
    // Uncommenting below causes object slicing:
    // vector<Order> orders = {gtc, ioc};
    //
    // What happens:
    // - GTC is 8 bytes, Order is 4 bytes
    // - Copying GTC to Order only copies first 4 bytes (id)
    // - Last 4 bytes (orderTime) are LOST - this is "slicing"
    // - Derived class behavior is also lost

    // Order o = gtc;  // WRONG! Object slicing - orderTime lost

    // ========================================================================
    // SOLUTION: USE POINTERS
    // ========================================================================
    Order *o = &gtc;  // UPCASTING: GTC* -> Order* (safe, implicit)

    // PROBLEM 2: Non-virtual function behavior
    o->cancelOrder();  // Calls Order::cancelOrder() - prints "no idea"

    // Why? Static binding based on pointer type (Order*), not object type (GTC)
    // Internally: cancelOrder(o) where o is Order*

    // ========================================================================
    // DOWNCASTING WITH reinterpret_cast
    // ========================================================================
    GTC* ptr = reinterpret_cast<GTC*>(o);  // DOWNCASTING: Order* -> GTC*

    cout << "-----------" << endl;
    cout << "ptr->id = " << ptr->id << endl;
    cout << ptr->cancelOrder() << endl;  // Now calls GTC::cancelOrder() - prints "yes"

    // This works because ptr is GTC*, so compiler uses GTC::cancelOrder()
    // WARNING: reinterpret_cast is unsafe - use dynamic_cast with virtual functions

    // ========================================================================
    // BETTER SOLUTION: Virtual Functions (next lecture)
    // ========================================================================
    // Declare cancelOrder() as virtual in base class:
    //   virtual bool cancelOrder() { ... }
    // This enables runtime polymorphism (dynamic binding via vtable)

    return 0;
}

// ============================================================================
// KEY CONCEPTS
// ============================================================================

// CLASS vs STRUCT:
// - class: members private by default
// - struct: members public by default

// HOW MEMBER FUNCTIONS WORK:
// Order a, b, c;  // Three objects
// a.cancelOrder();  // Translates to: cancelOrder(&a)
// Functions receive hidden 'this' pointer - only ONE function copy in memory

// UPCASTING vs DOWNCASTING:
// Upcasting (Derived* -> Base*): Safe, implicit
// Downcasting (Base* -> Derived*): Unsafe, explicit (use dynamic_cast)

// OBJECT SLICING:
// Assigning derived to base copies only base portion - derived data lost
// Always use pointers/references for polymorphism

// FOR HFT:
// - Virtual functions add small overhead (vtable lookup)
// - Object slicing causes bugs in order handling
// - Use templates for static polymorphism when possible
