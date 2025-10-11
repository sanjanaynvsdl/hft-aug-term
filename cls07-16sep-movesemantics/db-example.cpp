#include<iostream>
#include<vector>
using namespace std;


struct DbConnection{
    int id{1};
    string connectionName{"db"};

    //constructor
    DbConnection() {
        this->connectionName="DEFAULT COnsstructor!";
    }; 
    //copy constructor
    DbConnection(const DbConnection& other) {
        this->connectionName="COPY constructor";

    }
};

//when this fn invoked as it creates db, before desctrying
//it makes a copy into the stack of the main, 
DbConnection getDbConnection() {
    DbConnection db;
    return db;
}


int main() {
    vector<int> arr= {1,2,3,3,4}; //bts-> since this along is r-value creates a copy  and uses it in arr
    DbConnection db = getDbConnection(); //how many copies are being made?,
    //seems like a simple fucntion, but the copies that it creates
    //in stack/ ram, or temporary memory is what makes cpp go crrawzy
    //if cpp doesn't have the compiler stuff, how do we do ourseleves the copies? or optimix=zing them 
    //with move semantics-


    //-----------example, of copy constuvtion
    DbConnection d; //calls default one this is a l-value
    DbConnection copy = d; //this calls the copy constructor as im calling with d, 
    cout << d.connectionName << endl;
    cout << copy.connectionName << endl;

    DbConnection xyz; //calls the default constructor
    xyz=d; //this is not a copy consturcoit but a copy assingment, 

    cout << xyz.connectionName << endl;

    
}