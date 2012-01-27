#include <iostream>
#include "cell.h"
#include "grid.h"
using namespace std;

int main() {
   string command = "";
   int n = 0;
   int i = 0;
   int x;
   int y;
   Grid G;
   while(1) {
      cin >> command;
      if (cin.eof()) //Ends program
      {
         break;
      }
      if(command == "new") { //Executes "new n" commands
         cin >> n;
         G.init(n);
      }
      else if(command == "init") { //Executes "init" commands
         cin >> x;
         cin >> y;
         while(x != -1 && y != -1) { //Breaks when user enters -1 -1
            G.turnOn(x, y);
            cin >> x;
            cin >> y;
         }
         x = 0;
         y = 0;
      }
      else if(command == "step") //Executes "step" commands
         G.tick();
      else if(command == "steps") { //Executes "steps" commands
         cin >> i;
         for(int j = 0; j < i; j++)
            G.tick();
      }
      else if(command == "print") //Executes "print" commands
         cout<<G;
      else
         cout << "Invalid command" << endl;
   }
}
