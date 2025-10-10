#include<iostream>
using namespace std;

// We know linked list in Java, what about C++?
/*
- In C++

1 --> 2 --> 3

class Node {
    int data
    Node next;
}

- In C++ if I make Node next, it creates a deep copy of 3 and adds

1 --> 2 --> 3

3 is already present but while adding it creates a deep copy
- Instead we can simply store the address
struct Node {
    int data;
    Node* next;
}
*/



/*
Create a struct of order books:
- Arrays of bids and asks
- If an order is matched then remove those values
*/

struct OrderBook{
    int bids[3];
    int asks[3];
};

void match(OrderBook ob) {

    // Pass by value so above obj will be copied and then
    // we manipulate that copy

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(ob.asks[i]==ob.bids[j]) {
                ob.asks[i]=0;
                ob.bids[j]=0;
            }
        }
    } 
}

// Pointers: we access the members of pointers using ob->
void matchByPointers(OrderBook *ob) {
    for(int i=0;i<3;i++) {
        if(ob->asks[i]==ob->bids[i]) {
            ob->asks[i]=0;
            ob->bids[i]=0;
        }
    }
}

// Match by ref: &ob is our direct orderbook
// Behind the scenes it's just pointer operations
// Ampersand operator ( & )
void matchByRef(OrderBook &ob) {
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



    // The output will still be the same because C++ is pass by value
    // This makes the entire object copy and manipulates it

    // To pass the pointer we use & and dereference it
    // matchByPointers(&orderBook);
    matchByRef(orderBook);
    cout << " passed by ref,orderbook array values are : " << endl;
    for(int i=0;i<3;i++) {
        cout << orderBook.asks[i]  << " ";
        cout << orderBook.bids[i] << endl;
    };

    // Now the actual obj is being manipulated
    // Using pointers is complex, so to make life easier we use ref
    // Instead we take the input the same way in the function





}