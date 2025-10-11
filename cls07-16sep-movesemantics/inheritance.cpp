#include<iostream>
#include<cstdint>
#include <vector>
using namespace std;

enum Side{BUY, SELL};

// class Order {
//     public:
//         int32_t id;
//         Side side; //4bytes
//          bool cancelOrder() {
//             cout << "parent cancel order -called" << endl;
//             return false;
//         };
// };


//the above order size is 8bytes id+size
//beloew order is 16 bytes, after adding the virtual keyword, 
//BTS: creates / has a table of pointers to all the virtual functions
//array of fn's called (vtable)
//[pointer to Order::cancelOrder, poitner to other]
//any pointer is 8bytes, 

class Order {
    public:
        int32_t id; //4bytes
        Side side; //4bytes
        //vtable -> 8 bytes 
        virtual bool cancelOrder() {
            cout << "Order::cancelOrder() -> called" << endl;
            return false;
        };
        
};



//GTC goot till cancel,
//vtable for GTc
//[pointer to GTC::cancelOrder, other viratual fns]
class GTC: public Order {
    public:
        // int32_t timeStamp;
        bool cancelOrder() {
            cout << "GTC::cancelOrder() -> yes-cancelled" << endl;
            return true;
        }
};

//IOC immeditate or cancel
class IOC : public Order{
    public:
        bool cancelOrder() {
            cout << "IOC::cancelOrder()-> not cancelled" << endl;
            return false;
        };
};

int main() {
    GTC gtc{};
    IOC ioc{};


    //gtc -> 12bytes
    //id ... side.. timeStamp (memory)

    Order* o = &gtc;
    //this doesn't call the gtc cancelOrder 
    //how can we make it to call the respective fn, 
    //1. by adding the virtual keyword to cancelOrder on parent
    //-> invokes the gtc order
    //nd this doen't get resolved at the compile time,
    o->cancelOrder(); 
    cout << o->cancelOrder() << endl;  


    //2. by typecasting to gtc back 
    GTC* ptr = reinterpret_cast<GTC*>(o);
    cout << ptr->cancelOrder() << endl; //invokes the gtc cancelOrders

    //----------------------------------------
    cout << "-----------------" << endl;
    //more on virtual case
    Order* o1 = new Order();
    o1->cancelOrder();
    //1  2  3  4  5  6   7  8  9 /...16
    //v  v   v  v   ....... v  id ... size
    //memory of a order, 
    //on o->cancl fn, it goes to vtable, 


    Order* o2 = new Order();
    GTC gtc1{};

    //memory of gtc1 [Virtal POinter -8 bytes] [id][size][timestamp]
    //now, even though i assing o2 with the address of gtc as its still pointing
    // gtc vtable it invokes the GTC::cancelOrder,
    o2 = &gtc1; 
    o2->cancelOrder();

    //so, is this inheritance faster or slower? slower 
    //2-extra hops, at runtime, we need to call speicifc pointer , fn
    //CRTP,  a pattern in hft, 




}