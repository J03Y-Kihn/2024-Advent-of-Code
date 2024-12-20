
//checking if a series of numbers are valid equations to get their result (before the :) by adding in + or *. Part 2 allows in string concatenation instead of + or * in the equation
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void printing(vector<int> prints);
bool findResult(vector<int> equation, int index, long long int result, long long int currResult);
bool findResultPart2(vector<int> equation, int index, long long int result, long long int currResult);

vector<vector<int>> orderings;


int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day7input.txt");
    string line;

    long long int total = 0;
    long long int total2 = 0;
    while(!myfile.eof()){
        getline(myfile, line);
        
        vector<int> currLine;
        int colon = line.find(":");
        long long int result = stod(line.substr(0,colon));
        

        line = line.substr(line.find(":")+1, line.length()-colon);
        stringstream ss(line);
        string currNum;
        while(ss >> currNum){
            currLine.push_back(stoi(currNum));
        }

        if(findResult(currLine, 1, result, currLine[0])){
            total += result;
            total2 += result;
        }
        else if(findResultPart2(currLine, 1, result, currLine[0])){
            total2 += result;
        }
        
    }

    cout << total << endl;
    cout << total2 << endl;
    return 1;
}

void printing(vector<int> prints){
    for(int i=0; i<prints.size(); i++){
        cout << prints[i] << " ";
    }
}

bool findResult(vector<int> equation, int index, long long int result, long long int currResult){

    if(index == equation.size()){
        return currResult == result;
    }
    else if(currResult > result){
        return false;
    }
    else{
        if(findResult(equation, index+1, result, currResult+equation[index]) || findResult(equation, index+1, result, currResult*equation[index])){
            return true;
        }
    }
    return false;
}

bool findResultPart2(vector<int> equation, int index, long long int result, long long int currResult){

    if(index == equation.size()){
        return currResult == result;
    }
    else if(currResult > result){
        return false;
    }
    else if(findResultPart2(equation, index+1, result, currResult+equation[index]) || findResultPart2(equation, index+1, result, currResult*equation[index])){
            return true;
    }
    else{
        string s1 = to_string(currResult);
        string s2 = to_string(equation[index]);
        s1 = s1+s2;
        if(findResultPart2(equation, index+1, result, stoll(s1))){
            return true;
        }
    }
    return false;
}