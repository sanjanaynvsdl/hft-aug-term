#include<iostream>
#include<cstdint>
using namespace std;


//CRPT -> a basic example 
// inheritanc with templates
//checkout TYPE ERASURE 

template<typename Derived>
class Order{
    public:
        int32_t id;
        void cancelOrder() {
            static_cast<Derived*>(this)->cancelOrder();
        } 
};

class GTC:public Order<GTC>{
    public:
        int timeStamp;
        void cancelOrder() {
            cout <<"GTC::cancelOrder" << endl;
        }
};



int main() {
    cout << "hello" << endl;
    Order<GTC> o;
    o.cancelOrder(); //this works and invokes the gtc cancelorder

    //but, what's the main use of inheritacne 
    //the Order spcifically needs Order<GTC> etc,
    //we can't store the vector of Orders

}