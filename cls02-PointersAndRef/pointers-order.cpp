#include<iostream>
#include<math.h>
using namespace std;

// ===========================
// PASS-BY-REFERENCE SOLUTION USING POINTERS
// ===========================
// This demonstrates how to use pointers to modify original Order objects
// Key difference from orders-example.cpp: Uses Order* (pointers) instead of Order (values)

struct Order {
    int orderId;    // Unique identifier for the order
    bool isBid;     // true = buy order (bid), false = sell order (ask)
    int price;      // Price at which to buy/sell
    int qty;        // Quantity to trade
};

struct Response {
    int qtyFilled;  // Number of units successfully matched/filled
};

// ===========================
// INCORRECT POINTER SYNTAX (commented out)
// ===========================
// This shows a COMMON MISTAKE when first learning pointers
//
// void matchOrders(Order *a, Order *b) {
//     if (*a.isBid == *b.isBid)  // ERROR: Wrong syntax!
//     {                           // '*a.isBid' tries to dereference 'a.isBid', not 'a'
//         //                      // Operator precedence: '.' binds tighter than '*'
//     }
//     else {
//         if (!*a.isBid && *a.price <= *b.price || !*b.isBid && *b.price <= *a.price)
//         {
//             int qty = min(*a.qty, *b.qty);
//             *a.qty = *a.qty - qty;  // Correct: Dereference the whole pointer first
//             *b.qty = *b.qty - qty;  // But this syntax is cumbersome and error-prone
//         }
//     }
// };

// ===========================
// CORRECT SYNTAX: ARROW OPERATOR (->)
// ===========================
// The arrow operator (->) is syntactic sugar for (*ptr).member
// It makes code more readable and less error-prone

void matchOrders(Order *a, Order *b) {
    // Check if both orders are on the same side (no match possible)
    if (a->isBid == b->isBid) {  // 'a->isBid' is equivalent to '(*a).isBid'
        // No match - both are buy or both are sell
    }
    else {
        // Check if prices are compatible for a match
        // For a match: buy price >= sell price
        if (!a->isBid && a->price <= b->price || !b->isBid && b->price <= a->price) {
            int qty = min(a->qty, b->qty);  // Calculate matched quantity

            // CRITICAL: These modifications affect the ORIGINAL orders!
            // Because 'a' and 'b' are pointers to the original Order objects
            a->qty = a->qty - qty;  // Update original order A quantity
            b->qty = b->qty - qty;  // Update original order B quantity
        }
    }
};

int main() {
    // Create two orders for matching
    Order od1{1, true, 500, 10};   // Buy order: 10 units at 500
    Order od2{2, false, 500, 5};   // Sell order: 5 units at 500

    // ===========================
    // DEMONSTRATING PASS-BY-REFERENCE WITH POINTERS
    // ===========================

    // Before matching - original quantities
    cout << "od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;

    // Pass pointers to the orders using '&' (address-of operator)
    // '&od1' gets the memory address of od1
    // matchOrders receives pointers and can modify the originals
    matchOrders(&od1, &od2);

    // After matching - quantities are ACTUALLY changed!
    // Output will show: od1 qty: 5  od2 qty: 0
    // (5 units matched, od2 fully filled, od1 has 5 remaining)
    cout << "od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;

    // ===========================
    // KEY CONCEPTS:
    // ===========================
    // 1. ARROW OPERATOR (->):
    //    - Used to access members through a pointer
    //    - ptr->member is equivalent to (*ptr).member
    //    - Much cleaner than using * and . separately
    //    - Avoids operator precedence issues
    //
    // 2. WHY USE -> INSTEAD OF * AND . ?
    //    - '*' dereference with '.' member access requires parentheses: (*a).isBid
    //    - Without parentheses, *a.isBid is wrong (tries to dereference 'a.isBid')
    //    - Arrow operator (->) handles this automatically and safely
    //
    // 3. WHAT HAPPENS BEHIND THE SCENES?
    //    - Pointers are just integers that store memory addresses
    //    - On 64-bit systems: pointer = 8 bytes (stores a 64-bit address)
    //    - On 32-bit systems: pointer = 4 bytes (stores a 32-bit address)
    //    - The pointer's type (Order*) tells C++ how to interpret the data at that address
    //
    // 4. PASS-BY-REFERENCE WITH POINTERS:
    //    - Function receives memory address, not a copy of the data
    //    - Extremely efficient: only 8 bytes passed (on 64-bit system)
    //    - Can modify original data through the pointer
    //    - Critical for performance in HFT systems

}