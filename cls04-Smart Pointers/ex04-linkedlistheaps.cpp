#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* next;

    ~Node() {
        cout << data << " : is destructed!";
    }

    // Node(int data, Node* head) {
    //     this->data=data;
    //     this->next=head;
    // };

};


Node* makeLinkedList() {
    int str=1;
    Node* ptrHead = new Node{str};
    Node* ptrDummyHead = new Node{0};

    ptrDummyHead->next = ptrHead;

    for(int i=1;i<=1000;i++) {
        str=str+1;
        Node* newNode = new Node{str};

        ptrHead->next = newNode;
        ptrHead = ptrHead-> next;

    }
    return ptrDummyHead->next;

};
// - for the above funciton, - how many sys calls will this make
// - means, memory access, how many times it calls the kernel, 1000
//are any of these nodes destructed?, no coz heap memory we need to manage, 
//when ever program is done, then this is removed, 
//but the better way is to clear it at run-time only, 

/*
-accr to our assumption mmap was supposed to call 1000 times, but it called only 18 times,
- added new arrays to see teh mmap calls, refer cls, notes  


*/

int main() {

    Node* head = makeLinkedList();

    while(head->next!=nullptr) {
        cout << "node value is : " << head->data << endl;
        head = head->next;
    }
}

//- RVO and NRVO 
//- return value optimization, 

//- boxes are of size 10,5,17,7,
//- now i have objects to keep in, 
//- objects are 2,5,4,1,7, now how can we assing the objects to this boxes they have id's1,2,3,4,5
//- after sometime, id no, of 1 no longer wants to take space 0, Iid:,1 size=0 
//- how we will asigner objects, 

//- malloc or new,  get the size rwquired, now even for the above example malloc allots and take care of it
//- it's called memory fragmentation, if we say we need 40 bytes, in memeoy we have 10, 30 ,20 divided it gets in that way, 
//- let's say i ask the malloc 4 bytes it might ge tht 50bytes theres an algo which has been used by malloc, 
// - malloc and free both have their own alg,


//----------------------------------
// let;s say in my progrtamm
/*

1. i want 1gb malloc gets
2. i call free 1gb
3. after some code, i want 500mb


- in the second case it wont free instead keep it and give 500mb to third point
- now this is how the malloc works, i less sys call prev if gb cleared it made 3 calls
- hft;s don't use malloc
- in hft we use specialized malloc, jc malloc, google has its own algo


- let' say we are working with miultiple threads, nboth asks 1 new mb, both will give cotrol to kernel
- malloc is a centralized prgoram, 
*/