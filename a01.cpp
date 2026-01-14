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
void readOption(int &option); 

void placeOrder(double &cost); 
void readInt(string prompt, int &num);
double readDouble(string prompt, double &num);
void calcTotal();
double tipDiscount(double &tip, double &discount, double cost);
void calcFinalTotal();
void goodbye();

int main() {

    //input
    int option = 0;


    //output



    //anything inbetween


//welcome message
welcome();
//diplay menu
displayMenu();
readOption(option);

do {







} while(option == 1);




}

void welcome() {
    cout << "Welcome to my Food Cart Program!" << endl;
}

void displayMenu() {
    cout << "What would you like to do?" << endl;
    cout << setw(20) << right << "1. Place an order" << endl;
    cout << setw(10) << right << "2. Quit" << endl;
}

void readOption(){
int userChoice = readInt(">>", num);

while (userChoice < 1 && userChoice > 2) 
cout << "Invalid input. try again."
userChoice = readInt(">>");

}

void readInt(string prompt, int &num)
{
  int tempVar = 0;
  cout << prompt;
  cin >> tempVar;
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempVar;
  }
  cin.ignore(10, '\n');
  return tempVar;
}
