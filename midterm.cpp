#include <iostream>

using namespace std;

// function prototypes:
void welcome();
void readOption();
int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int val);
void printQueue(int queue[], int size);

const int MAX = 3; // maximum size of queue

int main() {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue
    char option = ' ';

    welcome();
    

    while (option != 'q') {
     
     // check if we should run enqueue or dequeue
     if (option == '+') {
         
         
     } else if (option == '-') {
     
     
     }
     // this happens if neither are entered
     cout << "Invalid Option." << endl << endl;
     readOption();
        
    }

    
    return 0;
}

void welcome() {
    cout << "Welcome to the FIFO Queue Program!" << endl << endl;
}

// Returns 0 on success, 1 on overflow (queue is full, cannot add)

int enqueue(int queue[], int &size, int val){
  
// add your code here
    
}

// Returns 0 on success, 1 on underflow (queue is empty, no values to dequeue), 2 if integer is not in the queue.

int dequeue(int queue[], int &size, int &val){

// add your code here
}

// Call this function to print the queue
void printQueue(int queue[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << queue[i];
        
        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}

