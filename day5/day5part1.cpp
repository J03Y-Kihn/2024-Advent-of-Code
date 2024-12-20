
//checking if a series of numbers are in the correct order, given the rules that specify which any numbers that have to be behind other numbers
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void printing(vector<int> prints);
int finds(vector<int> serach, int value);
vector<int> fixLine(vector<int> wrongLine);
bool validOrder(vector<int> order);

vector<vector<int>> orderings;


int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day5input.txt");
    string line;

    int total = 0;
    int fixedtotal = 0;
    while(!myfile.eof()){
        getline(myfile, line);
        
        if(line.length() > 2 && line[2] == '|'){
            vector<int> currOrder;

            currOrder.push_back(stoi(line.substr(0,2)));
            currOrder.push_back(stoi(line.substr(3,4)));
            orderings.push_back(currOrder);
        }
        else{
            vector<int> currLine;
            for(int i=0; i<line.length(); i++){
                currLine.push_back(stoi(line.substr(i,i+2)));
                i+=2;
            }
            bool correct = validOrder(currLine);
            if(correct && currLine.size() > 0){
                total += currLine[currLine.size()/2];
            }
            if(!correct && currLine.size() > 0){
                vector<int> newLine = fixLine(currLine);
                fixedtotal += newLine[newLine.size()/2];
            }
        }
    }

    cout << total << endl;
    cout << fixedtotal << endl;
    return 1;
}
//checks if the order is valid
bool validOrder(vector<int> order){
    for(int i=0; i<orderings.size(); i++){
        int first = finds(order, orderings[i][0]);
        int second = finds(order, orderings[i][1]);
        if(first > second && second != -1){
            return false;
        }
    }
    return true;
}
//prints the values in the vector
void printing(vector<int> prints){
    for(int i=0; i<prints.size(); i++){
        cout << prints[i] << " ";
    }
    cout << "Middle: ";
}

//see if value is in search. Return its index or -1 on a fail
int finds(vector<int> search, int value){

    for(int i=0; i<search.size(); i++){
        if(search[i] == value){
            return i;
        }
    }
    return -1;
}

//fixes an incorrect order to a correct order and returns correct order
vector<int> fixLine(vector<int> wrongLine){
    do{
        for(int i=0; i<orderings.size(); i++){
            int first = finds(wrongLine, orderings[i][0]);
            int second = finds(wrongLine, orderings[i][1]);
            if(first > second && second != -1){
                vector<int> currLine;
                for(int i=0; i< wrongLine.size(); i++){

                    if(i == second){
                        currLine.push_back(wrongLine[first]);
                        currLine.push_back(wrongLine[second]);
                    }
                    else if(i != first){
                        currLine.push_back(wrongLine[i]);
                    }
                }
                wrongLine = currLine;
            }
        }
    }while(!validOrder(wrongLine));

    return wrongLine;
}