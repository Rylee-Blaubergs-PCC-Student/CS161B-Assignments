//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 2
// Date:             1/24/26
// Description:      Makes an encoded file name for the user
// Input:            users last and first name, if the assignment was late or not, 
//                   student ID, file name, time of submission in military time
// Output:           The encoded file name based on previous user input
// Sources:          Assignment instructions, Sample Code, Previous assignment
//                   
//                   
//******************************************************************************
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);


int main() {
// declare inputs
char choice = ' ';
// declare outputs
char encodeFileName[51];

// place functions 
welcome();
displayMenu();

readOption(choice);


return 0;
}

// start welcome message
void welcome() {
    cout << "Welcome to my fileName encoding program!!" << endl;
}

// start of display menu function
void displayMenu() {
    cout << "Please pick an option below:" << endl;
    cout << setw(24) << right << "(e) Encode a file name" << endl;
    cout << setw(10) << right << "(q) Quit" << endl;
} 

// start readOption
void readOption(char &option) {

// prompt user input 
 cout << ">> ";
 cin >> option;

// validate whether user picked a valid choice or not 
while (option !=  'q' && option != 'e' && option !=  'Q' && option != 'E') {
cout << "Invalid Option! Please choose y/n!" << endl;
cout << ">> ";
cin >> option;
}
cin.ignore();
    
}

void encode(char encodeFileName[]) {
   // declare local values
   char fName[];
   char lName[];
   char parsedID[];
   char fileName[];
   bool late = false;
       
   //start reading inputs
   readInput(fName, lName, late);
   strcat(encodeFileName, lName);
   
   if (late) {
       
   }   
   readInput(parsedID[], fileName);   



}


void readInput(char fName[], char lName[], bool &lateFlag) {
// declare local value
char yesNo = ' '; 

//prompt user for their first and last name
cout << "Enter your last name: ";
cin.getline(lName, 51);
cout << "Enter your first name: ";
cin.getline(fName, 51);

// was the assignment late?
cout << "Was your assignment Late (y/n)?  "
cin >> yesNo;
while (yesNo !=  'y' && yesNo != 'n' && yesNo !=  'Y' && yesNo != 'N') {
cout << "Invalid Answer! Please choose y/n!" << endl;
cout << ">> ";
cin >> yesNo;
}
cin.ignore();
    
}

}

void readInput(char parsedID[], char fileName[]) {



}




