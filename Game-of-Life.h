// Declares classes for a Game-of-Life program to be used in a CPS 222
// lab on Git and GitHub.
//
// Author : Adam Princiotta
// Authors : John Zhu


// Instructor's note: the #ifndef/define/endif GAMEOFLIFE_H_ statements are
// a "header guard".  Together, they make it safe to #include this file
// anywhere it's needed: extra #includes will be ignored.
#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <iostream>
using std::istream;

enum class Organism {NONE, GESTATING, LIVING, DYING};

// Stores and manipulates the board and state of Game-of-Life game.

class GameBoard{
public:
	Organism get(unsigned row, unsigned col);
	void set(unsigned row, unsigned col, Organism status);
	
	//set initial board for game.
	void initialBoard();
	//Print out the initial board.
	void makeBoard();
	// Update and print out the new board.
	void updateBoard(int countGen);
	// check neigbors to set organsim to new status.
	void checkNeigbors();


private:
	//Row and Col for board. 
	static const int activeRows = 18;
	static const int activeCols = 50;
	static const int totalRows = activeRows + 2;
	static const int totalCols = activeCols + 2;
	Organism board_[totalRows][totalCols];

};

#endif //GAMEOFLIFE_H_
