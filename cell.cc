#include <iostream>
#include "cell.h"
using namespace std;

// Default constructor
Cell::Cell() {
   isAlive = false;
   numNeighbours = 0;
   numAlive = 0;
   for(int i = 0; i < maxNeighbours; i++) {
      neighbours[i] = NULL;
   }
}

// Destructor
Cell::~Cell() {
}

// Explicitly sets me to living.
void Cell::setLiving() {
   isAlive = true;
}

// Adds a pointer to one of my neighbours to my array.
void Cell::addNeighbour(Cell *neighbour) {
   neighbours[numNeighbours] = neighbour;
   numNeighbours++;
}

// My neighbours will call this, to let me know they're alive.
void Cell::neighbourIsAlive() {
   numAlive++;
}

// Tell all of my neighbours that I am alive (if I'm alive).
void Cell::alertNeighbours() {
   if(isAlive) {
      for(int i = 0; i < numNeighbours; i++)
         neighbours[i]->neighbourIsAlive();
   }
}

// Reassess my living-or-dead status, based on info from neighbours.
void Cell::recalculate() {
   if(isAlive) { //If I'm alive
      if((numAlive < 2) || (numAlive > 3)) //If there's less than 2 or more than 3 neighbours alive, I'm dead
         isAlive = false;
   }
   else { //Else if I'm dead
      if(numAlive == 3) //If there's exactly 3 neighbours alive, I revive
         isAlive = true;
   }
   numAlive = 0; //Resets the number of neighbours alive counter
}

ostream &operator<<(ostream &out, const Cell &c) {
   if(c.isAlive)
      out<<'X';
   else
      out<<'_';
   return out;
}
