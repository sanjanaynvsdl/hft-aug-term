#include<iostream>
#include<math.h>
using namespace std;

//Q2 - create a struct for orders a buy and a sell order
// a match funciton if the price matches return correct qty,

struct Order {
    int orderId;
    bool isBid;
    int price;
    int qty;
};

struct Response {
    int qtyFilled;
};

// void matchOrders(Order *a, Order *b) {
//     if (*a.isBid == *b.isBid)
//     {
//         //
//     }
//     else {
//         if (!*a.isBid && *a.price <= *b.price or !*b.isBid && *b.price <= *a.price)
//         {
//             int qty = min(*a.qty, *b.qty);
//             *a.qty = *a.qty - qty;
//             *b.qty = *b.qty - qty;
//         }
//     } 
// };

//now we can use -> instead of astric (*)

void matchOrders(Order *a, Order *b) {
    if (a->isBid == b->isBid)
    {
        //
    }
    else {
        if (!a->isBid && a->price <= b->price or !b->isBid && b->price <= a->price)
        {
            int qty = min(a->qty, b->qty);
            a->qty = a->qty - qty;
            b->qty = b->qty - qty;
        }
    } 
};

int main() {
     Order od1{1,true,500,10};
    Order od2{2,false,500,5};

    
    cout << "od1 qty : " << od1.qty << "od2 qty : " << od2.qty << endl;
    matchOrders(&od1,&od2); //now we passed ref,
    cout << "od1 qty : " << od1.qty << "od2 qty : " << od2.qty << endl;

    //we used * but what's the issue with them? too many stare
    // - so used -> now , if we run the output both share the same ref,

    //-------------------------------------------
    //what does c++ does behind the scenes?
    //behind the scenes this are just integers, 
    //which has purpose of storing the address, 


}