#include<iostream>
#include<vector>
using namespace std;


struct DbConnection{
    int id;
    string connectionName;
    char* buffer;

    //constructor
    DbConnection() {
        cout << "DEFAULT constructor " << endl;
        id=12;
        connectionName="db";
        buffer=(char*) (malloc(1*1024*1024));
    }; 

    //copy constructor
    DbConnection(const DbConnection& other) {
        cout << "COPY constructor" << endl;
        this->id=other.id;
        this->connectionName=other.connectionName;
        this->buffer=(char*) memcpy(other.buffer, this->buffer, 2*1024*1024);

    };

    //copy assignment
    DbConnection& operator = (const DbConnection& other) {
        cout << "zCOPY assingment" << endl;
        *this =  DbConnection(other);
        return *this;
    }
};


DbConnection getDbConnection() {
    DbConnection db;
    return db;
}


int main() {
   
    DbConnection db = getDbConnection(); 


    
    //add flag -> -fno-elide-construcors,
}