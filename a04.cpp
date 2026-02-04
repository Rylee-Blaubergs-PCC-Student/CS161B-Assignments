//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 4
// Date:             2/4/26
// Description:      
//                   
// Input:            
//                   
// Output:           unsorted and sorted scores and grades
// Sources:          Assignment instructions, Sample Code, Previous assignments
//                   
//                   
//******************************************************************************

// Call the median function to find the median and print it in main().

// Assume the arrays will always contain fewer than 20 values. You must not let the user enter more than 20 values.


#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void welcome();
void goodbye();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
bool validNum(string prompt, double &tempNum);

void printArray(double scores[], char grades[], int size);

// declare const
const int MAX_ENTRIES = 20;

int main() {

// declare all variables
double scores[20];
char grades[20];
int totalEntries = 0;


// start placing functions
welcome();



// print goodbye message
goodbye();
return 0;
}



void welcome() {
    cout << "Welcome to my Parallel Arrays program!" << endl;
    cout << "Please enter the list of scores (-1 to end input:)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;
}

void goodbye() {
    cout << "Thank you for using my Parallel Arrays program!!" << endl;
}

void readScores(double scores[], int &count) {
    double num = 0;
    string prompt = ">> ";
    while (num != -1 && count < MAX_ENTRIES){
     // read a double
     readDouble(prompt, num);
     // validate the number
     validNum(prompt, num);
     
     // check if num should be put into the array
     if (num != -1) { 
     
     // add the number to array
     scores[count] = num;
     
     // increment count
     count++;
     }
    }


}
// while condition num < 0 || num > 4.0

void readDouble(string prompt, double &num) {
//Output prompt
  cout << prompt;
  cin >> num;
  while(!cin)
  {  
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

bool validNum(string prompt, double &tempNum) {
    //check if num is -1
    if (tempNum == -1) {
     return true;   
    }
    // validate in range
 while (tempNum < 0 || tempNum > 4.0) {
     cout << "Invalid input! Please try again!!" << endl;
     readDouble(prompt, tempNum);
 }
 return true;
}




void sort(double scores[], char grade[], int count) {
 // declare local variables
 double min = 0.0;
 double tempVar = 0.0;
 char newChar = ' ';
 char oldChar = ' ';
 int swapIndex = 0;
 
 // start sorting
 for (int i = 0; i < count; i++) {
    // set min to the first index of the array and save it with tempVar
    tempVar = scores[i];
    min = scores[i];
    // save grade as well
    oldChar = grade[i];
    
    // start nested for loop
    for (int j = i + 1; j < count; j++) {
        // check for a new smallest element
        if (scores[j] < min) {
           // set new smallest element, save grade letter, and save swapIndex
           min = scores[j];   
           newChar = grade[j];
           swapIndex = j;
        }
    }
    
    // check if a swap is needed
    if (min != scores[i]) {
        // swap scores and grade letter
        scores[i] = min;
        scores[swapIndex] = tempVar; 
        grade[i] = newChar;
        grade[swapIndex] = oldChar;
        
    }  
 }   
}



void printArray(double scores[], char grades[], int size) {
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " " << grades[i] << endl;
    }
}
