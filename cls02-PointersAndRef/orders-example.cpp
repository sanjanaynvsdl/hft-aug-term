#include<iostream>
#include<math.h>
using namespace std;

// ===========================
// ORDER MATCHING SYSTEM - Complete Implementation
// ===========================
// This demonstrates a working order matching function that:
// 1. Validates orders are on opposite sides (buy vs sell)
// 2. Checks price compatibility
// 3. Returns the matched quantity

struct Order {
    int orderId;    // Unique identifier for the order
    bool isBid;     // true = buy order (bid), false = sell order (ask)
    int price;      // Price at which to buy/sell
    int qty;        // Quantity to trade
};

struct Response {
    int qtyFilled;  // Number of units successfully matched/filled
};

// MATCH FUNCTION: Returns quantity filled if orders can match
Response match(Order od1, Order od2) {
    // Rule 1: Orders must be on opposite sides (one buy, one sell)
    if(od1.isBid == od2.isBid) {
        return Response{0};  // Both are buy or both are sell - no match
    }

    // Rule 2: If od1 is a buy order, its price must be >= sell price
    else if((od1.isBid) && (od1.price >= od2.price)) {
        return Response{min(od1.qty, od2.qty)};  // Match the smaller quantity
    }

    // Rule 3: If od2 is a buy order, its price must be >= sell price
    else if((od2.isBid) && (od2.price >= od1.price)) {
        return Response{min(od1.qty, od2.qty)};  // Match the smaller quantity
    }

    return Response{0};  // No match if price conditions not met
};


// ===========================
// PASS-BY-VALUE PROBLEM DEMONSTRATION
// ===========================
// Q3: Instead of returning Response, directly modify the Order objects
// PROBLEM: This function receives copies of orders (pass-by-value)
// Any modifications made here will NOT affect the original orders in main()

void postMatch(Order od1, Order od2) {
    // Same matching logic, but trying to modify quantities directly
    if(od1.isBid == od2.isBid) {
        // No match - both are same side
    }
    else if((od1.isBid) && (od1.price >= od2.price)) {
        // cout << "od1 is a buyer (bid)!" << endl;
        // cout << "Before match: od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;

        // Update quantities based on which order is fully filled
        if(od1.qty <= od2.qty) {
            od1.qty = 0;                    // od1 fully filled
            od2.qty = od2.qty - od1.qty;    // od2 partially filled
        } else {
            od1.qty = od1.qty - od2.qty;    // od1 partially filled
            od2.qty = 0;                     // od2 fully filled
        }

        // cout << "After match: od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;
    }
    else if((od2.isBid) && (od2.price >= od1.price)) {
        // Update quantities when od2 is the buyer
        if(od2.qty <= od1.qty) {
            od2.qty = 0;                    // od2 fully filled
            od1.qty = od1.qty - od2.qty;    // od1 partially filled
        } else {
            od2.qty = od2.qty - od1.qty;    // od2 partially filled
            od1.qty = 0;                     // od1 fully filled
        }
    }

    // CRITICAL ISSUE: Changes to od1 and od2 only affect local copies!
    // The original Order objects in main() remain unchanged.
    // This is the "pass-by-value" problem in C++.
};

// Alternative implementation of matchOrders (also pass-by-value)
void matchOrders(Order a, Order b) {
    if (a.isBid == b.isBid) {
        // No match - both orders on same side
    }
    else {
        // Check if prices are compatible for a match
        if (!a.isBid && a.price <= b.price || !b.isBid && b.price <= a.price) {
            int qty = min(a.qty, b.qty);  // Calculate matched quantity
            a.qty = a.qty - qty;          // Reduce order A quantity
            b.qty = b.qty - qty;          // Reduce order B quantity

            // SAME PROBLEM: These changes won't persist outside this function!
        }
    }
};


int main() {
    // Test orders for matching
    Order od1{1, true, 500, 10};   // Buy order: 10 units at 500
    Order od2{2, false, 500, 5};   // Sell order: 5 units at 500

    Order od3{3, true, 600, 10};   // Buy order: 10 units at 600
    Order od4{4, false, 400, 5};   // Sell order: 5 units at 400

    // Test the match() function that returns Response
    // Response res = match(od1, od2);
    // Response res2 = match(od3, od4);
    // cout << "Qty matched: " << res.qtyFilled << endl;
    // cout << "New example: " << res2.qtyFilled << endl;

    // ===========================
    // DEMONSTRATING THE PASS-BY-VALUE PROBLEM
    // ===========================
    cout << "od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;

    // Call postMatch - this function tries to modify order quantities
    postMatch(od1, od2);

    // OBSERVE: Quantities remain unchanged!
    // Output will still show: od1 qty: 10  od2 qty: 5
    cout << "od1 qty: " << od1.qty << " od2 qty: " << od2.qty << endl;

    // WHY? Because C++ uses pass-by-value by default
    // - postMatch received COPIES of od1 and od2
    // - It modified the copies, not the originals
    // - When the function returns, the copies are destroyed
    // - Original orders remain unchanged

    // ===========================
    // KEY CONCEPTS DEMONSTRATED:
    // ===========================
    // 1. PASS-BY-VALUE: Everything is deep copied when passed to functions
    //    - Safe: Original data cannot be accidentally modified
    //    - Expensive: Copying large structs is slow (critical in HFT!)
    //    - Ineffective: Cannot modify original data when needed
    //
    // 2. SOLUTION: Pass-by-reference using pointers (see pointers-order.cpp)
    //    - Efficient: No copying, just pass memory address
    //    - Effective: Can modify original data
    //    - Fast: Critical for low-latency trading systems
}