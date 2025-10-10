#include<iostream>
using namespace std;

//Q1: write a function whatever it takes it prints it
template<typename T>
void Print(T obj) {
    cout << obj << endl;
}


//Q2: make a generic function accepts any class obj, and appends hello to it
template<typename T>
 void appendHello(T obj) {
    obj.id+="hello";
};

template<typename T>
 void appendHelloRef(T& obj) {
    obj.id+="hello";
};

template<typename T>
 void appendHelloConst(const T& obj) {
    // obj.id+="hello";
    cout << obj.id << endl;
    //since this is only read only we can't modify
    //so i've just printed
};

template<typename T>
 void appendHelloUniversalRef(T&& obj) {
    obj.id+="hello";
};

//T -> Ignores CV qualifiers, creates a copy
//T& -> doesn't ignore anything, but the issue with lvalue rvalue
//T&& -> universal reference


struct Student{
    string id;
    string name;
};

struct Order{
    string id;
    string item;
};




int main() {

    Print<int>(1);
    Print<double>(1.0);
    Print<char>('a');
    Print<string>("xyz");
    Print("sanjana");
    //compiler creates the functions with this specified data type via the templates

    cout << "------------" << endl;
    Student s1{"1","student"};
    Order o1{"order01","roll"};


    appendHello(s1);
    appendHello(o1);
    cout << s1.id << endl; //still prints 1, does not append hello
    //as this is a pass by value

    //Key points in templates
    //CV
    //C means const
    //V means volatile

    const Student s2{"2","std2"};
    const Order o2{"order02","food"};

    //even making this const, the cpp still creates a copy
    //when T is alone it ignores all the CV qualifiers
    //now, in the second func, I added the ampersand this takes the ref
    appendHelloRef(s1);
    cout << s1.id << endl;
    // appendHelloRef(s2); //compile error: as I passed with the ref of the const


    //creating the obj while passing it to func
    //error: {cannot bind non-const lvalue reference of type 'Student&' to an rvalue of type 'Student'}
    // appendHelloRef(Student{"s3","std3"});


    //lvalue, rvalue
    //the Student obj we creating while passing that wasn't on stack, it was there for very less time
    //by the time we reach the semicolon, it got destroyed, and we are passing the ref of that obj

    //understand the flow, and the timeline for this
    //1. appendHelloRef already made, we call it
    //2. according to arguments, it gets constructed
    //3. we passed this to newly constructed, fn()
    //4. object dies
    //5. function call appendHelloRef starts (starts on another stack frame)

    //lvalue -> is something we have a name to
    //any variable we have a name to -> can be called a lvalue
    //rvalue -> it doesn't have a name to


    /*
    void fn(string st);

    int x = "xyz"
    fn(x); //this is lvalue, coz it has a name
    fn("xyz"); //rvalue it doesn't have a name

    int y=15;
    f(&y); //even this is a rvalue, as it passed an address, not a stored name etc.

    //--more on lvalue rvalue
    string x = "hello";
    string& y=x; //lvalue
    string&& z=x; //this has name but still its an rvalue as it has 2-ampersand

    */

    //back to main fn
    //now, my fn has method signature as const
    //this worked, because this temporary is not in a stack memory or RAM
    //but somewhere in a particular register -> read memory space

    appendHelloConst(Student{"2","hi"});

    //------------------------------------------------
    //our goal was to design the function/generic in such a way that it accepts
    //lvalue, rvalue, anything, without throwing an issues
    //how can we do this? //universal ref modify fn, T&&
    //the below line creates a new type of template resolution called r-value ref
    cout << "------Universal ref example : " << endl;
    appendHelloUniversalRef(Student{"s03","iamstudent"});

    Student && s04{"04","student"};
    //1. this seems like a l-value as it has a name
    //2. but we are defining with && so we are explicitly saying that it's rvalue
    //3. so single & function appendHelloRef(T& obj) throws error
    // appendHelloRef(move(s04)); //ignore move

    //----so we make a template that accepts both l-values and r-values

}
