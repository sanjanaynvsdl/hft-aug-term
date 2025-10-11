#include<iostream>
#include<vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


/*
1. create a animal class
2. child classes-> Tiger, Duck, 
3. interface fn's makeSound() eat(),
*/


class Animal{
    public:
        string name;
        virtual void makeSound() =0;
        virtual void eat() = 0;
};

class Tiger:public Animal {
    public:
        void makeSound() override {
            cout << "[TIGER]-> arhhh!" << endl;
        }
        void eat() override {
            cout << "[TIGER] eatss DEER!" << endl;
        }

};

class Duck : public Animal {
    public:
        void makeSound() override {
            cout << "[DUCK]-> quack quack!" << endl;
        }
        void eat() override {
            cout << "[DUCK]-> is eatingg." << endl;
        }
};

int main() {
    
    auto start = high_resolution_clock::now();

    vector<Animal> animals;

    for(int i=0;i<100;i++) {
        Animal* animal = new Tiger();

        animal->makeSound();
        animal->eat();

        Animal* ducks = new Duck();

        ducks->makeSound();
        ducks->eat();



    }

    auto end = high_resolution_clock::now();

    // Compute duration in microseconds
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    //when the functions were defined as virtual 
    //it took 137460
    //as i remove the virtual keyword, it TOOK vrey less time,
    

}