#include <iostream>
#include "cell.h"
#include "grid.h"
using namespace std;

//Constructor
Grid::Grid() {
   theGrid = NULL;
   gridSize = 0;
}

//Destructor
Grid::~Grid() {
   clearGrid();
}

// Frees the grid.
void Grid::clearGrid() {
   for(int i = 0; i < gridSize; i++) {
      delete [] theGrid[i];
   }
}

// Sets up an n x n grid.  Clears old grid, if necessary.
// Initializes every cell in the grid, and tells each
// cell who its neighbours are.
void Grid::init(int n) {
   if(gridSize > 0)
      clearGrid();
   gridSize = n;
   int i;
   int j;
   theGrid = new Cell*[n]; //Creates n x n grid
   for(i = 0; i < n; i++) { 
      theGrid[i] = new Cell[n];
   }

   for(i = 0; i < n; i++) { //Adds neighbours with conditions
      for(j = 0; j < n; j++) {
         if(i > 0 && j > 0)
            theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]); //top left
         
         if(i > 0)
            theGrid[i][j].addNeighbour(&theGrid[i-1][j]); //top
         
         if(i > 0 && j < n - 1)
            theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]); //top right
         
         if(j > 0)
            theGrid[i][j].addNeighbour(&theGrid[i][j-1]); //left
         
         if(j < n - 1)
            theGrid[i][j].addNeighbour(&theGrid[i][j+1]); //right
         
         if(i < n - 1 && j > 0)
            theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]); //bottom left
         
         if(i < n - 1)
            theGrid[i][j].addNeighbour(&theGrid[i+1][j]); //bottom
         
         if(i < n - 1 && j < n - 1)
            theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]); //bottom right
         }
      }
}

// Runs one iteration of the simulation.
// Tells each cell to alert its neighbours, and then
// tells each cell to recalculate.
void Grid::tick() {
   int i;
   int j;
   for(i = 0; i < gridSize; i++) { //Each cell calls alertNeighbours
      for(j = 0; j < gridSize; j++) {
         theGrid[i][j].alertNeighbours();
      }
   }
   for(i = 0; i < gridSize; i++) { //Each cell calls recalculate
      for(j = 0; j < gridSize; j++) {
         theGrid[i][j].recalculate();
      }
   }
}
// Sets cell at i, j to living.
void Grid::turnOn(int i, int j) {
   theGrid[i][j].setLiving();
}

ostream &operator<<(ostream &out, const Grid &g) { //Deals with the output of the grid
   for(int j = 0; j < g.gridSize; j++) {
      for(int i = 0; i < g.gridSize; i++) {
         out<<g.theGrid[i][j];
      }
      out << endl;
   }
   return out;
}
