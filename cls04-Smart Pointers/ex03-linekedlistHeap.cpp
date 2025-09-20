#include<iostream>
using namespace std;

/*
1. Struct Node
2. constructor, destructor
3. create 1000 nodes connect them,
4. use heap memory
5. return head in main
6. print them, 
*/

struct Node{
    int data{0};
    Node* next{nullptr};

    ~Node() {
        cout << data << " is getting destructed!" << endl;
    }

};

/*
-> is used when you have a pointer to a struct/class and want to access a member.
. is used when you have the actual object*/

Node makeLL() {
    int str=1;
    Node* head = new Node{str};
    Node* headPtr = new Node{0};

    headPtr->next=head; 
    
    for(int i=0;i<1000;i++) {
        str=str+1;
        Node* newNode = new Node{str};

        // *head.next=newNode;
        head->next=newNode;
        head = head->next; 
    }
    return *headPtr;
}

int main() {
    Node head = makeLL();

    while(head.next!=nullptr) {
        cout << " Node value is " << head.data << endl;
        head = *head.next;
    }

}