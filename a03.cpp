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

using namespace std;

// function prototypes
void welcome();
void goodbye();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
bool validNum(string prompt, double &tempNum);
void calcGrade(double scores[], char grade[], int count);

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

// fill array
readScores(scores, totalEntries);
calcGrade(scores, grades, totalEntries);

printArray(scores, grades, totalEntries);


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
    string prompt = ">>";
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


void calcGrade(double scores[], char grade[], int count) {
 for (int i = 0; i < count; i++) {
    if (scores[i] > 3.3 && scores[i] <= 4.0) {
     grade[i] = 'A';   
    } else if (scores[i] > 2.7 && scores[i] <= 3.3) {
    grade[i] = 'B';
   } else if (scores[i] > 1.9 && scores[i] <= 2.7) {
    grade[i] = 'C';
   } else if (scores[i] > 1.1 && scores[i] <= 1.9) {
    grade[i] = 'D';
   } else if (scores[i] > 0.0 && scores[i] <= 1.1) {
    grade[i] = 'F';
   }
  }
}

void printArray(double scores[], char grades[], int size) {
    for (int i = 0; i < size; i++) {
      cout << scores[i] << ", " << grades[i] << endl;
    }
}

