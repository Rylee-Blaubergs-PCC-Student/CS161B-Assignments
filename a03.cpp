//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 3
// Date:             2/1/26
// Description:      Parallel arrays program. will get user input for grades and
//                   scores and print them unsorted and sorted
// Input:            num as a double
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
void calcGrade(double scores[], char grade[], int count);
void sort(double scores[], char grade[], int count);
double median(double scores[], int count);
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
// calculate grades
calcGrade(scores, grades, totalEntries);

// print unsorted array
cout << "Your stats are as below:" << endl << endl;
cout << "The list of scores and their grades are:" << endl;

// set fixed decimal placement to one ex: 2.1, 4.0, 3.5, etc...
cout << fixed << setprecision(1);
printArray(scores, grades, totalEntries);
// formatting
cout << endl;

// sort array
sort(scores, grades, totalEntries);

// print sorted array
cout << "The list sorted by scores in ascending order:" << endl;
printArray(scores, grades, totalEntries);


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

double median(double scores[], int count) {


    
}

void printArray(double scores[], char grades[], int size) {
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " " << grades[i] << endl;
    }
}

