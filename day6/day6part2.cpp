
//checking the number of squares that a person will hit before leaving the board. if they hit an object (#) then they rotate right 90 degrees and then walk straight
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void printing(vector<char> prints);
void findLocation(int& row, int& col, vector<vector<char>> currBoard);
void move(int& row, int& col, int& direction, vector<vector<char>>& currBoard);
bool leavingBoard(int row, int col, int direction, vector<vector<char>>& currBoard);
int totalTraveled();
void resetBoard(vector<vector<char>>& currBoard);
bool hasSeen(vector<vector<int>>& visited, int row, int col, int direction);

vector<vector<char>> board;
vector<vector<char>> solutionBoard;
vector<vector<char>> tempBoard;

int main(int argc, char* argv[]){

    ifstream myfile;
    //myfile.open("sampleinput.txt");
    myfile.open("day6input.txt");
    string line;

    while(!myfile.eof()){
        getline(myfile, line);
        
        vector<char> currLine;
        for(int i=0; i<line.length();i++){
            currLine.push_back(line[i]);
        }
        board.push_back(currLine);     
    }

    resetBoard(solutionBoard);
    //traverse through
    int row = 0;
    int col = 0;
    findLocation(row, col, solutionBoard);
    int direction = 0;
    
    while(!leavingBoard(row, col, direction, solutionBoard)){
        move(row, col, direction, solutionBoard);
        //findLocation(row, col, solutionBoard);
    }
    
    
    resetBoard(tempBoard);
    int objlocals = 0;  //number of places where an object placement will cause an infiniteloop
    int numRows = board.size();
    int numCols = board[0].size();

    for(int objrow =0; objrow<numRows; objrow++){
        for(int objcol=0; objcol<numCols; objcol++){
            
            //only place objects in the original path of the guard
            if(solutionBoard[objrow][objcol] == 'X'){
                tempBoard[objrow][objcol] = 'O';
                
                int row = 0;
                int col = 0;
                findLocation(row, col, tempBoard);
                int direction = 0;

                //check to see if the guard escapes
                bool infinite = true;
                vector<vector<int>> visited;
                while(!leavingBoard(row, col, direction, tempBoard) && !hasSeen(visited, row, col, direction)){//!hasSeen(visited, row, col, direction)){
                    move(row, col, direction, tempBoard);
                }
                if(hasSeen(visited, row, col, direction)){
                    objlocals++;
                    cout << " objLocal:" << objrow << " " << objcol << endl;
                }
                resetBoard(tempBoard);
                visited.clear(); //clears all objects in visited (doesn't need to loop through)
                visited.shrink_to_fit(); //updates it's memory bounds
            } 

        }
    }

    cout << objlocals << endl;
    
    return 1;
}

//print out the vector
void printing(vector<char> prints){
    for(int i=0; i<prints.size(); i++){
        cout << prints[i] << " ";
    }
}

//find the person's location
void findLocation(int& row, int& col, vector<vector<char>> currBoard){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(currBoard[i][j] == '^'){
                row = i;
                col = j;
                return;
            }
        }
    }
    return;
}

//move the person
void move(int& row, int& col, int& direction, vector<vector<char>>& currBoard){
    switch(direction){
        case 0:
            if(currBoard[row-1][col] == '#' || currBoard[row-1][col] == 'O'){
                direction++;
            }
            else{
                currBoard[row][col] = 'X';
                currBoard[row-1][col] = '^';
                row--;
            }
            break;
        case 1:
            if(currBoard[row][col+1] == '#' || currBoard[row][col+1] == 'O'){
                direction++;
            }
            else{
                currBoard[row][col] = 'X';
                currBoard[row][col+1] = '^';
                col++;
            }
            break;
        case 2:
            if(currBoard[row+1][col] == '#' || currBoard[row+1][col] == 'O'){
                direction++;
            }
            else{
                currBoard[row][col] = 'X';
                currBoard[row+1][col] = '^';
                row++;
            }
            break;
        case 3:
            if(currBoard[row][col-1] == '#' || currBoard[row][col-1] == 'O'){
                direction++;
            }
            else{
                currBoard[row][col] = 'X';
                currBoard[row][col-1] = '^';
                col--;
            }
            break;
    }
    direction = direction % 4;
}

//determine if the person is leaving the board
bool leavingBoard(int row, int col, int direction, vector<vector<char>>& currBoard){

    if(row == 0 && direction == 0){
        currBoard[row][col] = 'X';
        return true;
    }
    else if(col == board[0].size()-1 && direction == 1){
        currBoard[row][col] = 'X';
        return true;
    }
    else if(row == board.size()-1 && direction == 2){
        currBoard[row][col] = 'X';
        return true;
    }
    else if(col == 0 && direction == 3){
        currBoard[row][col] = 'X';
        return true;
    }
    return false;
}

//determine the number of tiles traveled on
int totalTraveled(){
    int total = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(tempBoard[i][j] == 'X'){
                total++;
            }
        }
    }
    return total;
}

//resets the input board to the default board
void resetBoard(vector<vector<char>>& currBoard){
    //for(int i=0; i<currBoard.size();i++){
    //    currBoard[i].clear();
    //}
    currBoard.clear();
    currBoard.shrink_to_fit();

    for(int i=0; i<board.size(); i++){
        vector<char> currLine;
        for(int j=0; j<board[i].size(); j++){
            currLine.push_back(board[i][j]);
        }
        currBoard.push_back(currLine);
    }
}

//checks to see if we have been to the current location from the input direction
bool hasSeen(vector<vector<int>>& visited, int row, int col, int direction){

    for(int i=0; i<visited.size(); i++){
        if(visited[i][0] == row && visited[i][1] == col && visited[i][2] == direction){
            return true;
        }
    }
    vector<int> currLocal;
    currLocal.push_back(row);
    currLocal.push_back(col);
    currLocal.push_back(direction);
    visited.push_back(currLocal);
    return false;
}