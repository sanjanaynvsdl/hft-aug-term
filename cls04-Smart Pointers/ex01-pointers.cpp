#include<iostream>
using namespace std;

int main() {

    int* arr= new int[15]; //this is stored in heap memory
    //where ever we use the new | malloc thats from heap 

    int arr2[15]; //-> stack memeory

    //matrix -> array of arrays
    //whats this in terms of memory
    // matrix -> pointers to array of pointers 


    //Q- write a code for M X N matrix, 
    int M,N;
    cin >> M;
    cin >> N;
    int* row = new int[M];  //-> asrray of integers
    int* row2 = new int[M];

    //this is we declare arrays in cpp,
    int** matrix = new int*[N]; //-> array of pointers,
    for(int i=0;i<N;i++) {
        matrix[i]=new int[M];
    }


    //heap matrix print the diagonal of it, 
    int** matrix2 = new int*[N];

    for(int i=0;i<N;i++) {
        matrix2[i]=new int[M];
    }

    cout << "Enter elements:\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> matrix2[i][j];
        }
    }

    cout << "diagonal is " << endl;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(i==j) {
                cout << matrix2[i][j];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    //Q declare a linkedlist, return the head of linkedlist, 








     




}