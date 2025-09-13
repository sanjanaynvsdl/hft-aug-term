#include<iostream>
#include<cmath>
using namespace std;


//recap
// int main() {
//     int a=1;
//     int b=2;

//     cout <<a+b <<endl;
//     int num;

//     cin>>num;
//     cout <<num <<endl;
// }

//Q1 : calculate the distance between two points, 
struct Point{
    int x,y;
};

double getDistance(Point a, Point b) { 
   double manhtanDistance = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
   double euclideanDistance = sqrt(manhtanDistance);
   return euclideanDistance;
}


//Q2: create a order struct,

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
    // if(od2.isBid) {
    //     if((od2.price == od1.price) && (od1.qty>=od2.qty)) {
    //         return Response{od2.qty};
    //    } else {
    //     return Response{0};
    //    }
    // } else {
    //     cout << "entered second else " << endl;
    //     cout << "Order1 qty is " << od1.qty << "order2 qty is "<< od2.qty << endl;
    //     if(od1.price==od2.price) {

            
    //         return Response{od1.qty};
    //     } else {
    //         return Response{0};
    //     }
    // }
    // return Response{0};
    
    //----- 
    // if(od1.price==od2.price) {
    //     //od1 is bid and qty = 5 then return od1 qty else od2 qty
    //     if(od1.isBid && od1.qty<=od2.qty) {
    //         return Response{od1.qty};
    //     }  
    //     else {
    //         return Response{od2.qty};
    //     }

    //     //--ned to handle wwhere od1 is ask
    // } 
    // return Response{0};

    //-------------------missed edge cases above below the working code
    
};

int main() {
    Point obj1{0,0};
    Point obj2{3,4};
    cout << getDistance(obj1,obj2) << endl;

    //Q2-----

    Order od1{1,true,500,10};
    Order od2{2,false,500,5};

    Response res = match(od1,od2);

    cout << res.qtyFilled <<endl;

}


