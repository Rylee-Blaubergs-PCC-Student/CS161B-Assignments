//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 1
// Date:             1/13/26
// Description:      Make a food cart shopping program
// Input:            dish name as string, price amount as double, 
// Output:           recipt of all items
// Sources:          Assignment instructions and Sample Code
//                   
//                   
//******************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void welcome();
void displayMenu();
void readOption(int& option); 

void placeOrder(double &cost); 
void readInt(string prompt, int &num);


int main() {

    //input
    int userChoice = 0;


    //output



    //anything inbetween
    

//welcome message
welcome();
//diplay menu
displayMenu();
readOption(userChoice);

// start do while
do {

//did user want to quit?
if (userChoice == 2) {
break;
}





// ask if user wants to add more to their order
readOption(userChoice);

//do while condition (need to fix)
} while(userChoice == 1);


//end of main
return 0;
}



// start welcome message
void welcome() {
    cout << "Welcome to my Food Cart Program!" << endl;
}

// start of display menu function
void displayMenu() {
    cout << "What would you like to do?" << endl;
    cout << setw(20) << right << "1. Place an order" << endl;
    cout << setw(10) << right << "2. Quit" << endl;
}

//start readOption
void readOption(int &option) {
bool valid;

// start do while
do {
// read user input
readInt(">>", option);

//check if option is one or two
if (option == 1 || option == 2) {
 valid = true;   
} else {    
cout << "Invalid input. try again." << endl;
}
//loop while valid is false
} while(!valid);
}


// start readInt
void readInt(string prompt, int &num) {
//Output prompt
  cout << prompt;
  cin >> num;
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> num;
  }
  cin.ignore(10, '\n');
}
