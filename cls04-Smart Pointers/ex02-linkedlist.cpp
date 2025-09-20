#include<iostream>
using namespace std;


//

struct Node{
    int data{0};
    Node* next{nullptr};

    ~Node() {
        cout << data << " this is node is getting destrcuted!" << endl;
    }
};

//why diid not this delete 10, 
/*
sanjanaynvsdl> ./a.exe
12 this is node is getting destrcuted!
11 this is node is getting destrcuted!
10
0 this is node is getting destrcuted! -> this is head 10 onlyb  but value  overridedn in loop
sanjanaynvsdl> */

Node makeLinkedList() {
    Node head;
    head.data=10;

    Node next;
    next.data=11;

    
    Node third;
    third.data=12;

    head.next=&next;
    next.next=&third;

    return head;
}


int main() {
    // Node n1{3,}
    Node h= makeLinkedList();
    //h-> (10,next) -> (11,next) -> (12,next)-> nullptr, 
    //since all of this memoery is being created in stack memeory, 
    //when we make a first call h made a copy, and it had access, to first value only
    //so , it printed only 10, but not 11, 12 
    
    
    //when we run this, stakc memory created, first main, 
    //then makeLinekdLst() all memory vanished once this completes the execution
    while(h.next!=nullptr) {
        cout << h.data << endl;
        h = *h.next; 
        
    }

    //now, stack heap class, stack memory is limited, heap we create using new | maklloc
    //.we ask emeory n run time to os which also called kernel,
    /*
    - since we ask kernel, now this will be a context switch
    - bcoz of context witch it' will be slow
    - means out program is slow if compared to stack memeory
    - in hft stack memory is preferrable,


    - as desing pettern in hft, 
    - if we want a heap memoery for array, for linkedlist instead of calling thrice
    - we get a big chunk of memoery in start, 
    */

    //using new keyboard it returns the pointer to mnode/arra7
    Node* ptrNode = new Node{10};
    
    

}