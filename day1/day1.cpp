
//Code by Joseph Kihn
//Day 1 part 1 of 2024 advent of coding
//Determine the difference between 2 data sets, by sorting the two lists then summing the difference
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int main(int agrc, char* agrv[]){

    string line;
    ifstream myfile;
    myfile.open("day1input.txt");

    vector<int> leftcol, rightcol;

    //get input data
    while(getline(myfile, line)){

        leftcol.push_back(stoi(line.substr(0,5)));
        rightcol.push_back(stoi(line.substr(7,14)));
    }

    //sort data
    sort(leftcol.begin(), leftcol.end());
    sort(rightcol.begin(), rightcol.end());
    //cout << rightcol.front() << "end1" << rightcol.back() << "end2" << endl;

    //determine the difference of the data
    int difference =0;
    int temp;
    for(int i=0; i<rightcol.size(); i++){
        temp = leftcol.at(i) - rightcol.at(i);
        if(temp > 0){
            difference += temp;
        }
        else{
            difference += temp*-1;
        }
    }
    //output the difference
    cout << difference << endl;
    return 1;
}