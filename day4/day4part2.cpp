
//checking if a grid of letters make an X consisting of the letters MAS, so they will cross on the A
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

bool upm(int row, int col); //both ms are at the bottom
bool downm(int row, int col); //both ms are at the top
bool rightm(int row, int col); //both ms are at the left
bool leftm(int row, int col); //both ms are at the right

string board[140][140];


int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day4part2input.txt");
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
            if(upm(i,j)){
                total++;
            }
            if(downm(i,j)){
                total++;
            }
            if(rightm(i,j)){
                total++;
            }
            if(leftm(i,j)){
                total++;
            }
        }
    }

    cout << total << endl;
    return 1;
}

bool upm(int row, int col){
    if(row < 2 || col > 137){
        return false;
    }
    else{
        if(board[row][col] == "M" && board[row][col+2] == "M"){
            if(board[row-1][col+1] == "A"){
                if(board[row-2][col] == "S" && board[row-2][col+2] == "S"){
                    return true;
                }
            }
        }
    }
    return false;
}
bool downm(int row, int col){
    if(row > 137 || col > 137){
        return false;
    }
    else{
        if(board[row][col] == "M" && board[row][col+2] == "M"){
            if(board[row+1][col+1] == "A"){
                if(board[row+2][col] == "S" && board[row+2][col+2] == "S"){
                    return true;
                }
            }
        }
    }
    return false;
}
bool rightm(int row, int col){
    if(col > 137 || row > 137){
        return false;
    }
    else{
        if(board[row][col] == "M" && board[row+2][col] == "M"){
            if(board[row+1][col+1] == "A"){
                if(board[row+2][col+2] == "S" && board[row][col+2] == "S"){
                    return true;
                }
            }
        }
    }
    return false;
}
bool leftm(int row, int col){
    if(col < 2 || row > 137){
        return false;
    }
    else{
        if(board[row][col] == "M" && board[row+2][col] == "M"){
            if(board[row+1][col-1] == "A"){
                if(board[row+2][col-2] == "S" && board[row][col-2] == "S"){
                    return true;
                }
            }
        }
    }
    return false;
}