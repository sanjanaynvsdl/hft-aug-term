#include<iostream>
using namespace std;

//we know linked list in java, wt about 
/*
- in cpp 

1 --> 2 --> 3

class Node {
    int data
    Node next;
}

- in cpp if i make Node next, it creates a deep copy of 3 and adds

1 --> 2 --> 3

3 -> threee present but still while adding it creates the deep copy
- instead we can just simply store the address in the 
struct Node {
    int data;
    Node* next;
}
*/



/*
create a struct of order books,
-arrays of bids and asks, 
- if a order is matched then remove those certain values, 
*/

struct OrderBook{
    int bids[3];
    int asks[3];
};

void match(OrderBook ob) {

    //pass by value so above obj will be copied and then
    // we maniupulate that copy

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(ob.asks[i]==ob.bids[j]) {
                ob.asks[i]=0;
                ob.bids[j]=0;
            }
        }
    } 
}

//pointers we access the memebrs of pointers using
// ob->
void matchByPointers(OrderBook *ob) {
    for(int i=0;i<3;i++) {
        if(ob->asks[i]==ob->bids[i]) {
            ob->asks[i]=0;
            ob->bids[i]=0;
        }
    }
}

//match by ref, &ob is nothing but our direct orderbook 
//behind the scenes it's just pointers operations only, 
//Ampersand operator ( & )
void matchByref(OrderBook &ob) {
    for(int i=0;i<3;i++) {
        if(ob.asks[i]==ob.bids[i]) {
            ob.asks[i]=0;
            ob.bids[i]=0;
        }
    }
}


int main() {

    OrderBook orderBook = {{10,8,6},{10,8,14}};
    match(orderBook);

    cout << " main orderbook array values are : " << endl;
    for(int i=0;i<3;i++) {
        cout << orderBook.asks[i]  << " ";
    };

    

    //the output will be still the same because, cpp is pass by value
    //this makes the entier object copy and manipulates it, 

    //to pass the pointer we use & and de-refernce it, 
    // matchByPointers(&orderBook);
    matchByref(orderBook);
    cout << " passed by ref,orderbook array values are : " << endl;
    for(int i=0;i<3;i++) {
        cout << orderBook.asks[i]  << " ";
        cout << orderBook.bids[i] << endl;
    };

    //now the actual obj is being manipulated, 
    //this is just like hell, so to make the life easier we got the ref
    //instead we just the take the input as same in the func(&ob)





}