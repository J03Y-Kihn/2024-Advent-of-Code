
//checking the number of squares that a person will hit before leaving the board. if they hit an object (#) then they rotate right 90 degrees and then walk straight
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void printing(vector<char> prints);
void findLocation(int& row, int& col);
void move(int row, int col, int& direction);
bool leavingBoard(int row, int col, int direction);
int totalTraveled();

vector<vector<char>> board;

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
        //printing(currLine);
        //cout << endl;   
        board.push_back(currLine);     
    }

    //traverse through
    int row = 0;
    int col = 0;
    findLocation(row, col);
    int direction = 0;
    while(!leavingBoard(row, col, direction)){
        move(row, col, direction);
        findLocation(row, col);
    }

    
    int total = totalTraveled();
    cout << total << endl;
    return 1;
}

//print out the vector
void printing(vector<char> prints){
    for(int i=0; i<prints.size(); i++){
        cout << prints[i] << " ";
    }
}

//find the person's location
void findLocation(int& row, int& col){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == '^'){
                row = i;
                col = j;
                return;
            }
        }
    }
    return;
}

//move the person
void move(int row, int col, int& direction){
    switch(direction){
        case 0:
            if(board[row-1][col] == '#'){
                direction++;
            }
            else{
                board[row][col] = 'X';
                board[row-1][col] = '^';
            }
            break;
        case 1:
            if(board[row][col+1] == '#'){
                direction++;
            }
            else{
                board[row][col] = 'X';
                board[row][col+1] = '^';
            }
            break;
        case 2:
            if(board[row+1][col] == '#'){
                direction++;
            }
            else{
                board[row][col] = 'X';
                board[row+1][col] = '^';
            }
            break;
        case 3:
            if(board[row][col-1] == '#'){
                direction++;
            }
            else{
                board[row][col] = 'X';
                board[row][col-1] = '^';
            }
            break;
    }
    direction = direction % 4;
}

//determine if the person is leaving the board
bool leavingBoard(int row, int col, int direction){

    if(row == 0 && direction == 0){
        board[row][col] = 'X';
        return true;
    }
    else if(col == board[0].size()-1 && direction == 1){
        board[row][col] = 'X';
        return true;
    }
    else if(row == board.size()-1 && direction == 2){
        board[row][col] = 'X';
        return true;
    }
    else if(col == 0 && direction == 3){
        board[row][col] = 'X';
        return true;
    }
    return false;
}

//determine the number of tiles traveled on
int totalTraveled(){
    int total = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'X'){
                total++;
            }
        }
    }
    return total;
}