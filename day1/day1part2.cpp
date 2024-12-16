
//Code by Joseph Kihn
//Day 1 part 2 of 2024 advent of coding
//Determine the similarity between 2 data sets, by sorting the two lists then multiplying the number from the first data set by the number of times it is in the second data set
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int find(int number, vector<vector<int>> dict);
int main(int agrc, char* agrv[]){

    string line;
    ifstream myfile;
    myfile.open("day1input.txt");

    vector<vector<int>> dictionary;

    map<char, int> dict;

    //get one data set to start our dictionary
    while(getline(myfile, line)){
        vector<int> currNum;
        currNum.push_back(stoi(line.substr(0,5)));
        currNum.push_back(0);
        dictionary.push_back(currNum);
    }

    //loop through second data set to determine the copies
    ifstream myfile2;
    myfile2.open("day1input.txt");
    int temp;
    while(getline(myfile2, line)){
        temp = find(stoi(line.substr(7,14)), dictionary);
        if(temp != -1){
            dictionary[temp][1] += 1;
        }
    }

    //compute the similarity
    int total = 0;
    for(int i=0; i< dictionary.size(); i++){
        total += dictionary[i][0] * dictionary[i][1];
        //cout << dictionary[i][0] << dictionary[i][1] <<endl;

    }

    cout << total << endl;

    return 1;
}

//helper function to determine if a given number is in our dictionary
int find(int number, vector<vector<int>> dict){

    for(int i=0; i< dict.size(); i++){
        if(dict[i][0] == number){
            return i;
        }
    }

    return -1;
}