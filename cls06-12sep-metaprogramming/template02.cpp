#include<iostream>
using namespace std;

struct Student{
    string id;
    string name;
};

struct Order{
    string id;
    string food;
};


template<typename T>
void appendHello(T&& obj) {
    obj.id+="hello";
};

template<typename T>
void appendHello(T* obj) {
    obj->id += "hello";
}



int main() {
    //now, we have seen the templates, with the three types, &, &&
    //l-values and r-values
    //what if we want to work with the pointers
    //what if someone passes the pointer

    Student s1{"s1","student"};
    appendHello(&s1); //didn't work, as I passed the address
    //{error: request for member 'id' in 'obj', which is of pointer type 'Student*' (maybe you meant to use '->' ?)}
    //when I comment the obj.id it works and the compiler tries to create a template with the Student*
    //checkout {cppinsights.io}


    //now this template should handle obj.id, obj->id
    //we make use of template specialization

    cout << "this used template with the pointer " << s1.id << endl;
    cout << "----------------------------------------" << endl;

    //Q: there can be any struct or data type which might not have .id
    //as in our function we used obj.id, what happens if we pass char

    char ch='h';
    appendHello(ch); //error: as char does not have id
    //in this cases we can write another template of it, which supports char
    //refer metaprogramming.cpp file

}
