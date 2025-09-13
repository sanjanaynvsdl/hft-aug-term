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

Response match(Order od1, Order od2) {
    if(od1.isBid==od2.isBid) {
        return Response{0};

    } else if((od1.isBid) && (od1.price>=od2.price)) {
        return Response{min(od1.qty,od2.qty)};

    } else if((od2.isBid) && (od2.price>=od1.price)) {
        return Response{min(od1.qty,od2.qty)};
    }
    return Response{0};
};


//Q3 : Instead of returning res, correct the final Orders object modify it!
//after the post, 
void postMatch(Order od1, Order od2) {
    if(od1.isBid==od2.isBid) {
        // return Response{0};

    } else if((od1.isBid) && (od1.price>=od2.price)) {
        // return Response{min(od1.qty,od2.qty)};
        // cout << "od1 is a buyer he is bid !" << endl;
        // cout << "Before match : od1 qty : " << od1.qty << " od2 qty : "<< od2.qty << endl;
        if(od1.qty<=od2.qty) {
            od1.qty=0;
            od2.qty=od2.qty-od1.qty;
        } else {
            od1.qty=od1.qty-od2.qty;
            od2.qty=0;
        }
        // cout << "After match : od1 qty : " << od1.qty << " od2 qty : "<< od2.qty << endl;



    } else if((od2.isBid) && (od2.price>=od1.price)) {
        // return Response{min(od1.qty,od2.qty)};

        //od2 qty > , < 
        if(od2.qty<=od1.qty) {
            od2.qty=0;
            od1.qty=od1.qty-od2.qty;
        } else {
            od2.qty= od2.qty-od1.qty;
            od1.qty=0;
        }



    }
    // return Response{0};
};

void matchOrders(Order a, Order b) {
    if (a.isBid == b.isBid)
    {
        //
    }
    else {
        if (!a.isBid && a.price <= b.price or !b.isBid && b.price <= a.price)
        {
            int qty = min(a.qty, b.qty);
            a.qty = a.qty - qty;
            b.qty = b.qty - qty;
        }
    } 
};


int main() {

    Order od1{1, true, 500, 10};
    Order od2{2, false, 500, 5};

    Order od3{3, true, 600, 10};
    Order od4{4, false, 400, 5};

      // Response res = match(od1,od2);
      // Response res2 = match(od3,od4);

    cout << "od1 qty : " << od1.qty << "od2 qty : " << od2.qty << endl;
    postMatch(od1, od2);
    cout << "od1 qty : " << od1.qty << "od2 qty : " << od2.qty << endl;


    // cout << "Qty matched " << res.qtyFilled <<endl;
    // cout << "New example : " << res2.qtyFilled <<endl;


    //----------------------------------------------------------------------------
    //1. passed by value so eevething is deep copy,
    //2. now, we'll understand how to pass by ref, 
}