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
void readDouble(string prompt, double &num);
double tipDiscount(double &tip, double &discount, double cost)



int main() {

    //input
    int userChoice = 0;
    double userCost = 0;

    //output
    


    //anything inbetween
    bool done = false;
    
    
    

//welcome message
welcome();
//diplay menu
displayMenu();
readOption(userChoice);

// start do while
do {

//did user want to quit?
if (userChoice == 2) {
done = true;
break;
}
placeOrder(userCost);

//Format to the second decimal place
cout << fixed << setprecision(2);

// ask if user wants to add more to their order
cout << endl << "Your total cost is $" << userCost << endl << endl;


displayMenu();
readOption(userChoice);

//do while condition (need to fix)
} while(!done);


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

// start do while loop
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

// start placeOrder function
void placeOrder(double &cost) {
char yesNo = 'y';
bool yesNoTF = true; 
string foodName = "";
double foodCost = -1;

while (yesNoTF) {
cout << "Enter the name of your item: ";
cin >> foodName;
cout << "Enter the cost of youe item $: ";

do {
// gets food cost of current iteration
readDouble("", foodCost);

if (foodCost < 0) {
    cout << "Invalid input. try again." << endl;   
}
} while (foodCost < 0);

// update total cost
cost += foodCost;
cout << "Do you want to add another item? (y/n): ";
cin >> yesNo;

if (yesNo == 'n' || yesNo == 'N') {
 yesNoTF = false;   
} else if (yesNo == 'y' || yesNo == 'Y') {
yesNoTF = true;
} else {
  cout << "Invalid input. Try again: ";
  cin >> yesNo;
}
}
}

//start tipDiscount
double tipDiscount(double &tip, double &discount, double cost) {





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

// start readDouble
void readDouble(string prompt, double &num) {
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

