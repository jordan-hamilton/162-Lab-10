/***********************************************************************************************
** Program name: Lab 10
** Author: Jordan Hamilton
** Date: 11/29/2018
** Description: This program provides the user with a menu asking them if they'd like to find a
** Fibonacci number with or without using recurson. The user is then prompted to enter an
** integer, then the appropriate method for calculating the Fibonacci number is displayed and
** timed using clock().
***********************************************************************************************/

#include <ctime>
#include <iomanip>
#include <iostream>
#include <memory>

#include "Menu.hpp"
#include "fibonacci.hpp"

using std::cout;
using std::endl;
using std::fixed;
using std::unique_ptr;

void populateMenu(unique_ptr<Menu> &menu);

/***********************************************************************************************
** Description: This program can be run via the lab10 executable generated by make.
***********************************************************************************************/
int main() {

  clock_t clockTicks;


  int choice, number;
  unique_ptr<Menu> mainMenu( new Menu("Select from the following options:") );

  populateMenu(mainMenu);

  do {

    choice = mainMenu->getIntFromPrompt(1, mainMenu->getMenuChoices(), true);

    switch (choice)  {

      case 1 : number = mainMenu->getIntFromPrompt("What Fibonacci number would you like to know?", 1, 50, false);
               clockTicks = clock();
               cout << "Fibonacci number F" << number << ": " << fibonacciNonRecursive(number) << endl;
               clockTicks = clock() - clockTicks;
               cout << fixed << "Clock time for this calculation was "
                    << static_cast<float>(clockTicks) / CLOCKS_PER_SEC << endl;
               break;

      case 2 : number = mainMenu->getIntFromPrompt("What Fibonacci number would you like to know?", 1, 50, false);
               clockTicks = clock();
               cout << "Fibonacci number F" << number << ": " << fibonacciRecursive(number) << endl;
               clockTicks = clock() - clockTicks;
               cout << fixed << "Clock time for this calculation was "
                    << static_cast<float>(clockTicks) / CLOCKS_PER_SEC << endl;
               break;

      default : {}

    }

    cout << endl;

  } while (choice != 3);

  return 0;

}


/***********************************************************************************************
** Description: This function takes a pointer to a Menu object, then calls the addMenuItem
** method to add the approprate menu options to the program's menu.
***********************************************************************************************/
void populateMenu(unique_ptr<Menu> &menu) {

  menu->addMenuItem("Determine a Fibonacci number without recursion");
  menu->addMenuItem("Determine a Fibonacci number recursively");
  menu->addMenuItem("Exit");

}
