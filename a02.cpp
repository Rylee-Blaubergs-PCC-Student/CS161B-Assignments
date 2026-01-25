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
#include <string>
using namespace std;

void welcome();
void displayMenu();
void readOption(char &option);


int main() {
// declare inputs
char choice = ' ';
// declare outputs

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