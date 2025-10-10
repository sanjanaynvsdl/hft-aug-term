#include<iostream>
#include<cmath>
using namespace std;

// BASIC RECAP: Simple I/O operations
// int main() {
//     int a = 1;
//     int b = 2;
//     cout << a + b << endl;
//
//     int num;
//     cin >> num;
//     cout << num << endl;
// }

// ===========================
// EXERCISE 1: DISTANCE CALCULATION
// ===========================
// Calculate the Euclidean distance between two points using the distance formula:
// distance = sqrt((x2-x1)² + (y2-y1)²)

struct Point {
    int x, y;
};

double getDistance(Point a, Point b) {
    // Step 1: Calculate the squared differences
    // Note: Variable name should be 'squaredDistance', not 'manhattanDistance'
    // Manhattan distance is |x2-x1| + |y2-y1|, which is different from what we're calculating
    double squaredDistance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

    // Step 2: Take square root to get Euclidean distance
    double euclideanDistance = sqrt(squaredDistance);

    return euclideanDistance;
}

// ===========================
// EXERCISE 2: ORDER MATCHING SYSTEM
// ===========================
// Trading system simulation: Match buy (bid) and sell (ask) orders
// In real HFT systems, this logic is critical for order execution

struct Order {
    int orderId;    // Unique identifier for the order
    bool isBid;     // true = buy order (bid), false = sell order (ask)
    int price;      // Price at which to buy/sell
    int qty;        // Quantity to trade
};

struct Response {
    int qtyFilled;  // Number of units successfully matched/filled
};

Response match(Order od1, Order od2) {
    // COMMENTED OUT: Various attempts at matching logic with edge cases
    // Kept for reference to show the evolution of the algorithm

    // Attempt 1: Check if od2 is bid
    // if(od2.isBid) {
    //     if((od2.price == od1.price) && (od1.qty >= od2.qty)) {
    //         return Response{od2.qty};
    //     } else {
    //         return Response{0};
    //     }
    // } else {
    //     cout << "Entered second else" << endl;
    //     cout << "Order1 qty is " << od1.qty << " order2 qty is " << od2.qty << endl;
    //     if(od1.price == od2.price) {
    //         return Response{od1.qty};
    //     } else {
    //         return Response{0};
    //     }
    // }
    // return Response{0};

    // Attempt 2: Simplified price matching
    // if(od1.price == od2.price) {
    //     // If od1 is bid and qty <= od2 qty, return od1 qty, else od2 qty
    //     if(od1.isBid && od1.qty <= od2.qty) {
    //         return Response{od1.qty};
    //     } else {
    //         return Response{od2.qty};
    //     }
    //     // TODO: Need to handle where od1 is ask
    // }
    // return Response{0};

    // NOTE: All above implementations missed edge cases
    // A complete implementation would check:
    // 1. Orders must be on opposite sides (one bid, one ask)
    // 2. Prices must match or cross
    // 3. Return minimum of the two quantities

    return Response{0};  // Placeholder - function not fully implemented
};

int main() {
    // Test Exercise 1: Distance calculation
    // Creates two points: (0,0) and (3,4)
    // Expected distance: 5 (it's a 3-4-5 right triangle)
    Point obj1{0, 0};
    Point obj2{3, 4};
    cout << getDistance(obj1, obj2) << endl;  // Output: 5

    // Test Exercise 2: Order matching
    // od1: Buy order (bid=true) for 10 units at price 500
    // od2: Sell order (bid=false) for 5 units at price 500
    Order od1{1, true, 500, 10};
    Order od2{2, false, 500, 5};

    Response res = match(od1, od2);
    cout << res.qtyFilled << endl;  // Should print matched quantity

}


