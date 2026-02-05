#include <iostream>

using namespace std;

// function prototypes:
void welcome();
void goodbye();
void readOption(char &option);
int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int val);
void printQueue(int queue[], int size);

const int MAX = 3; // maximum size of queue

int main() {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue
    char option = ' ';

    welcome();
    
    readOption(option);
    
    
     while (option == '+' || option == '-') {
     // check if we should run enqueue, dequeue, or to quit
     if (option == '+') {
         cout << "+ was entered" << endl;
         readOption(option);
         
     } 
     if (option == '-') {
         cout << "- was entered" << endl;
         readOption(option);

     }
     if (option == 'q') {
         goodbye();
         return 0;
     }
     
     // this happens nothing above have been entered
     cout << "Invalid Option." << endl << endl;
     readOption(option);
     }

}

void welcome() {
    cout << "Welcome to the FIFO Queue Program!" << endl << endl;
}

void goodbye() {
    cout << endl << "Goodbye" << endl;
}

void readOption(char &option) {
    cout << "Enter Option: ";
    cin >> option; 
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

