#include <iostream>
#include <string>
#include "Game-of-Life.h"
using std::cout;
using std::cin;
using std::endl;

static const char ESC = 27; 

//Returns the value from a specific row and column taken from parameters
Organism GameBoard::get(unsigned row, unsigned col){
	return board_[row][col];
}
	
//Sets the value for a specific row and column taken from parameters
void GameBoard::set(unsigned row, unsigned col, Organism status){
	board_[row][col]=status;
}
	
//Creats the initial board, setting all values in the board to NONE
void GameBoard::initialBoard(){
	for(int i = 0; i < totalRows; i++){
		for(int j = 0; j < totalCols; j++){
			set(i,j, Organism::NONE);
		}
	}
}

//Makes the initial organisms and displays the first board
void GameBoard::makeBoard(){
	cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
				 
	for(int i = 1; i < totalRows - 1; i++){
		cout << "\n|";
		for(int j = 1; j < totalCols - 1; j++){
			if(board_[i][j] == Organism::LIVING)
				cout << "*";
			else
				cout << " ";
		}
		cout << "|";
	} 
	cout << endl;
	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
	cout << endl;
}

//Checks the number of neighbors for each space on the board. If a LIVING organism has 2 or 
//3 LIVING neighbiors, it will continue to live, otherwise it will die. If a NONE space has 
//exactly 3 organisms, it will become GESTATING
void GameBoard::checkNeigbors(){
	int neighbors = 0;
	for(int i = 1; i < totalRows - 1; i++){
		for(int j = 1; j < totalCols - 1; j++){				
			
			if(get(i-1, j-1) == Organism::LIVING || get(i-1, j-1) == Organism::DYING)
				neighbors++;

			if(get(i, j-1) == Organism::LIVING || get(i, j-1) == Organism::DYING)
				neighbors++;
			
			if(get(i+1, j-1) == Organism::LIVING || get(i+1, j-1) == Organism::DYING)
				neighbors++;
			
			if(get(i-1, j) == Organism::LIVING || get(i-1, j) == Organism::DYING)
				neighbors++;
			
			if(get(i-1, j+1) == Organism::LIVING || get(i-1, j+1) == Organism::DYING)
				neighbors++;
			
			if(get(i+1, j) == Organism::LIVING || get(i+1, j) == Organism::DYING)
				neighbors++;

			if(get(i, j+1) == Organism::LIVING || get(i, j+1) == Organism::DYING)
				neighbors++;
			
			if(get(i+1, j+1) == Organism::LIVING || get(i+1, j+1) == Organism::DYING)
				neighbors++;

			if ((neighbors < 2 || neighbors > 3) && (get(i, j) == Organism::LIVING))
				set(i, j, Organism::DYING);
			
			else if (neighbors == 3 && get(i, j) == Organism::NONE)
				set(i, j, Organism::GESTATING);
				
			neighbors = 0;
			
		}
			
	}		
		
}

//Updates the board. GESTATING become LIVING and DYING become NONE
void GameBoard::updateBoard(int countGen){
	cout << ESC << "[H" << "Generation " << countGen << ":" << endl;

	for(int i = 1; i < totalRows - 1; i++){
		for(int j = 1; j < totalCols - 1; j++){
			if(get(i, j) == Organism::GESTATING)
				set(i, j, Organism::LIVING);
	
			else if (get(i, j) == Organism::DYING)
				set(i, j, Organism::NONE);
		}
	
	}

	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
					 
	for(int i = 1; i < totalRows - 1; i++){
		cout << "\n|";
		for(int j = 1; j < totalCols - 1; j++){
			if(get(i, j) == Organism::LIVING)
				cout << "*";
			else
				cout << " ";
		}
		cout << "|";
	} 
	
	cout << endl;
	
	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
	
	cout << endl;
		
}

//Gets the amount of initial organisms and their locations
//Calls the methods to play the Game of Life
int main(){
	
	GameBoard Gboard;
	Gboard.initialBoard();

	int initOrg;
	int generations;
	int countGen = 1;
	int x;
	int y;

	cout << "How many organisms intitally?: ";
	cin >> initOrg;
	cout << endl;

	cout << "Locations?: ";
	
	for(int i = 0; i < initOrg; i++){
		cin >> x >> y;
		cout << x << " " << y << endl;
		Gboard.set(x,y,Organism::LIVING);
	}
	
	cout << "Generations?: ";
	cin >> generations;
	cout << endl;

	Gboard.makeBoard();
	
	cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
	while (cin.get() != '\n') {            
		//intentionally empty loop body
	 }

	while(countGen <= generations){
		cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
		while (cin.get() != '\n') {            
			//intentionally empty loop body
	 	}	
		Gboard.checkNeigbors();
		Gboard.updateBoard(countGen);
		countGen++;
	}

return 0;
}
