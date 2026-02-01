//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 3
// Date:             2/1/26
// Description:      
// Input:            
//                   
// Output:           
// Sources:          Assignment instructions, Sample Code, Previous assignments
//                   
//                   
//******************************************************************************
// int main()
// Declare all variables needed. The 2 arrays (double scores[], and char grades[]) must be declared in main().
// Call readScores() and send scores and count to it. This will fill the scores array from the user. 
// You should call the readDouble() function to read and validate the scores before adding them to the scores array.

// count will have the number of values read.

// Call calcGrade()function that takes the scores array and an empty grades array and fills the grades array with letter grades.
// A is >3.3  <= 4.0
// B is >2.7 <= 3.3
// C is >1.9 <= 2.7
// D is >1.1 <= 1.9
// F is >0.0 <= 1.1

// Call the printList function to print the lists.
// Call the sort function to sort the list based on scores.
// Call the printList function to print the lists.
// Call the median function to find the median and print it in main().

// Assume the arrays will always contain fewer than 20 values. You must not let the user enter more than 20 values.


#include <iostream>
#include <iomanip>

// function prototypes
void welcome();
void goodbye();
void readScores(int scores[], int &count);


int main() {

// declare all variables
double scores[20];
char grades[20];
int totalEntries = 0;

// start placing functions
welcome();

// fill array
readScores(scores[], totalEntries);

printArray(scores[], totalEntries);


}

void welcome() {
    cout << "Welcome to my Parallel Arrays program!" << endl;
}

void goodbye() {
    cout << "Thank you for using my Parallel Arrays program!!" << endl;
}

void readScores(int scores[], int &count) {



}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << ", ";
    }
}

