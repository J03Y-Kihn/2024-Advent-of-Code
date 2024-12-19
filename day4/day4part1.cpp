
//checking if a grid of letters spell out XMAS, in any direction, including diagonals
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

bool up(int row, int col);
bool down(int row, int col);
bool right(int row, int col);
bool left(int row, int col);
bool upright(int row, int col);
bool upleft(int row, int col);
bool downright(int row, int col);
bool downleft(int row, int col);

string board[140][140];


int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day4input.txt");
    string line;

    vector<vector<int>> reports;

    int row = 0;
    while(!myfile.eof()){
        getline(myfile, line);
        
        for(int i=0; i<line.length(); i++){
            board[row][i] = line[i];
        }
        row++;
    }
    
    int total = 0;
    for(int i=0; i<140;i++){
        for(int j=0; j< 140; j++){
            if(up(i,j)){
                total++;
            }
            if(down(i,j)){
                total++;
            }
            if(right(i,j)){
                total++;
            }
            if(left(i,j)){
                total++;
            }
            if(upright(i,j)){
                total++;
            }
            if(upleft(i,j)){
                total++;
            }
            if(downright(i,j)){
                total++;
            }
            if(downleft(i,j)){
                total++;
            }
        }
    }
  
    //between 2143 and 2544
    cout << total << endl;
    return 1;
}

bool up(int row, int col){
    if(row < 3){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row-1][col] == "M"){
                if(board[row-2][col] == "A"){
                    if(board[row-3][col] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool down(int row, int col){
    if(row > 136){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row+1][col] == "M"){
                if(board[row+2][col] == "A"){
                    if(board[row+3][col] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool right(int row, int col){
    if(col > 136){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row][col+1] == "M"){
                if(board[row][col+2] == "A"){
                    if(board[row][col+3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool left(int row, int col){
    if(col < 3){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row][col-1] == "M"){
                if(board[row][col-2] == "A"){
                    if(board[row][col-3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool upright(int row, int col){
    if(col > 136 || row < 3){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row-1][col+1] == "M"){
                if(board[row-2][col+2] == "A"){
                    if(board[row-3][col+3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool upleft(int row, int col){
    if(col < 3 || row < 3){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row-1][col-1] == "M"){
                if(board[row-2][col-2] == "A"){
                    if(board[row-3][col-3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool downright(int row, int col){
    if(row > 136 || col > 136){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row+1][col+1] == "M"){
                if(board[row+2][col+2] == "A"){
                    if(board[row+3][col+3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool downleft(int row, int col){
    if(row > 136 || col < 3){
        return false;
    }
    else{
        if(board[row][col] == "X"){
            if(board[row+1][col-1] == "M"){
                if(board[row+2][col-2] == "A"){
                    if(board[row+3][col-3] == "S"){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}