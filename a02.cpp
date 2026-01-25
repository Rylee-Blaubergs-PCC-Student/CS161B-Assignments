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
#include <cctype>
using namespace std;

void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void makeLower(char fName[], char lName[]);
void readTime(char strTime[]);
void clearArray(char encodeFileName[]);

int main() {
// declare inputs
char choice = ' ';
// declare outputs
char encodeFileName[51];

// place functions 
welcome();
displayMenu();

readOption(choice);
while (choice == 'e' || choice == 'E') {
cout << "This program will ask you a few questions and generate an encoded" << endl
     << "fileName based on your answers." << endl << endl;

// start encoding
encode(encodeFileName);

//display encoded fileName
cout << "Your encoded file name is: " << encodeFileName << endl;

// clear encoded file name array
clearArray(encodeFileName);

//check if user wants to make another file name
displayMenu();
readOption(choice);
}


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
   char fName[51];
   char lName[51];
   char parsedID[51];
   char fileName[51];
   char strTime[51];
   bool late = false;
       
   // read first set of inputs
   readInput(fName, lName, late);
   // concatenate information from the first readInput
   strcat(encodeFileName, lName);
   strcat(encodeFileName, "_");
   strcat(encodeFileName, fName);
   strcat(encodeFileName, "_");
   //check if assignment is late
   if (late) {
   strcat(encodeFileName, "LATE");
   strcat(encodeFileName, "_"); 
   }  
   
   // read second set of inputs
   readInput(parsedID, fileName);   
   // concatenate parsedID
   strcat(encodeFileName, parsedID);
   strcat(encodeFileName, "_");
   
   // read time (in military)
   readTime(strTime);
   
   //concatenate time
   strcat(encodeFileName, strTime);
   strcat(encodeFileName, "_");
   
   // concatenate fileName
   strcat(encodeFileName, fileName);

}


void readInput(char fName[], char lName[], bool &lateFlag) {
// declare local value
char yesNo = ' '; 

//prompt user for their first and last name
cout << "Enter your last name: ";
cin.getline(lName, 51);
cout << endl << "Enter your first name: ";
cin.getline(fName, 51);

//make first and last name all lowercase
makeLower(fName, lName);

// was the assignment late?
cout << endl << "Was your assignment Late (y/n)?  ";
cin >> yesNo;
while (yesNo !=  'y' && yesNo != 'n' && yesNo !=  'Y' && yesNo != 'N') {
cout << "Invalid Answer! Please choose y/n!" << endl;
cout << ">> ";
cin >> yesNo;
}
cin.ignore();

if (yesNo == 'y' || yesNo == 'Y') {
 lateFlag = true;   
}

}

// start makeLower
void makeLower(char fName[], char lName[]) {
// make all characters in first name array lowercase    
for (int i = 0; i <= strlen(fName); i++) {
fName[i] = tolower(fName[i]);
}
// make all characters in last name array lowercase 
for (int i = 0; i <= strlen(lName); i++) {
lName[i] = tolower(lName[i]);
}
}


void readInput(char parsedID[], char fileName[]) {
//declare local variable
char stdID[51];

//prompt user for student id
cout << endl << "Enter your Student-ID (format: 222-22-2222): ";
cin.getline(stdID, 51);
// put the last four numbers of the id into parsedID
strncpy(parsedID, stdID + 7, 4);

//prompt user for file name
cout << endl << "Enter the file name: ";
cin.getline(fileName, 51);

}

void readTime(char strTime[]) {
    // declare local variables
    int hour = 0;
    int min = 0;
    char discard;
    
    // prompt user for time
    cout << endl << "Enter the time submitted (military time - ex: 18:24 for 6:24pm):" << endl;
    cin >> hour >> discard >> min;
    // validate input
    while(!cin || discard != ':' || hour < 0 || hour > 24 || min < 0 || min > 60)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }   
  

  
  //when data is all good, come out and ignore the newline
  cin.ignore(100,'\n');
  
  //convert hour from int to string then to cstring and copy to timeStr
  strncpy(strTime, to_string(hour).c_str(),10);
  //convert min from int to string and then cstring and concatenate to timeStr
  strcat(strTime, to_string(min).c_str());
  
}

void clearArray(char encodeFileName[]) {
// make each character in the encoded file name a empty character
for (int i = 0; i <= strlen(encodeFileName); i++) {
encodeFileName[i] = '\0';
}
}



