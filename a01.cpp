//******************************************************************************
// Author:           Rylee Blaubergs
// Assignment:       Assignment 1
// Date:             1/13/26
// Description:      Make a food cart shopping program
// Input:            dish name as string, price amount as double, 
// Output:           recipt of all items
// Sources:          Assignment instructions, Sample Code, previous term code(for the string validation) 
//                   
//                   
//******************************************************************************
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function prototypes
void welcome();
void displayMenu();
void readOption(int& option); 
void placeOrder(double &cost); 
void readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
double tipDiscount(double &tip, double &discount, double cost);



int main() {

    //input
    int userChoice = 0;
    double userCost = 0.0;
    double tipAmount = 0.0;
    //output
    double discountAmount = 0.0;
    
//welcome message
welcome();
//diplay menu
displayMenu();
readOption(userChoice);

// start do while
while(userChoice == 1) {

userCost = 0.0;

placeOrder(userCost);

//Format to the second decimal place
cout << fixed << setprecision(2);

// ask if user wants to add more to their order
cout << endl << "Your total cost is $" << userCost << endl << endl;
tipDiscount(tipAmount, discountAmount, userCost);

displayMenu();
readOption(userChoice);

} 
cout << endl << "Thank you for using my program!" << endl;

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

// start do while loop
do {
// read user input
readInt(">> ", option);

//check if option is one or two
if (option < 1 || option > 2) {
cout << "Invalid input. try again." << endl;
}
//loop while valid is false
} while(option != 1 && option != 2);
}

// start placeOrder function
void placeOrder(double &cost) {
char yesNo = 'y';
string foodName = "";
double foodCost = -1;

while (yesNo == 'y' || yesNo == 'Y') {

cout << "Enter the name of your item: ";
getline(cin, foodName);
cout << "Enter the cost of your item $: ";

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

while (yesNo !=  'y' && yesNo != 'n' && yesNo !=  'Y' && yesNo != 'N') {
cout << "Invalid Option! Please choose y/n!" << endl;
cout << ">> ";
cin >> yesNo;
}
cin.ignore();
}
}

//start tipDiscount
double tipDiscount(double &tip, double &discount, double cost) {
cout << "Enter the amount of tip you want to add $: ";
// read tip amount
readDouble("", tip);
while(tip < 0) {
cout << "Invalid input. Try again: ";
readDouble("", tip);
}
cost += tip;
cout << endl << "Your total is: $" << cost << endl;

// check for discounts
if (cost > 50) {
cout << "You get a 10% discount!" << endl;
discount = cost * 0.10;
cost -= discount;
cout << "Your discount is $" << discount << endl;
cout << "Your final cost is: $" << cost << endl << endl;

} else if (cost > 35 && cost < 50) {
cout << "You get a 5% discount!" << endl;
discount = cost * 0.05;
cost -= discount;
cout << "Your discount is $" << discount << endl;
cout << "Your final cost is: $" << cost << endl << endl;
}

return cost;
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

