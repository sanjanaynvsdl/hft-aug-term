#include<iostream>
using namespace std;

//things to learn, write constructor, copy ocnstructor, destrctor, move constructor
struct Vec{
    int* ptr;
    int size;
    

    // constructor
    Vec(int size) {
        this->size=size;
        this->ptr=new int[size];

    }
    //copy constructor,  -> this is a read only obj so we use this, 
    Vec(const Vec& other) {
        this->size = other.size;
        this->ptr= new int[size];
        for(int i=0;i<size;i++) {
            ptr[i]=other.ptr[i];
        }
    }


    //copy assingment, 
    Vec& operator = (const Vec& other) {
        delete this->ptr;
        size=other.size;

        for(int i=0;i<size;i++) {
            ptr[i]=other.ptr[i];
        }

        //or we can use this, 
        // *this  = Vec(other);
        return *this;
    }


    //move constructor, 
    Vec(Vec&& other) {
        this->size=other.size;
        this->ptr = other.ptr;

        other.size=0;
        other.ptr=nullptr;
    }


    //move assingment, 
    //synthetic r-values, 
    Vec& operator = (Vec &&other) {
        delete this->ptr;
        size=other.size;

        ptr=other.ptr;

        other.size=0;
        other.ptr=nullptr;
        return *this;
    }

    ~Vec() {
        delete ptr;
    }

    //rule of five, if u wriete any constructo rmannually, then you have to write all, 
    //cpp by default gives eveyrhting but if we write one things we writea ll
};


//write move constructor, move destructor

int main() {
    cout << "hell00o" << endl;

    Vec vector(15);
    cout << vector.ptr[0] << endl;


    Vec v2(10);
    // v2 = getVector();

    //solve this using move asingment, necasue this again creates create as first v-> 15 bytes but hen 
    //r-value of getVectore created somehgin due to v2 = getVector now copies to main and points v2-? {}1,2,,3,


    //let;s i want to send a few values as r-value to afucntion

    //Vec bids
    //Vec asks,
    //since i defined it will be a l-value now
    //so sned to a fn, i do
    //caluclate(std::move(a),std((move(asks))) -.this is systentic r-value,

    /*
    calcualte(Vec && a, Vec && b)
    std;;move runtime or compile time?, it's jsut nothing but static_cast<Vec&&> 
    */
}