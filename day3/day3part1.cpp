
//checking if a sets of data points are constantly increasing/decreasing and by no more than 3 more than the last number
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

bool increasing(vector<int> reports);
bool decreasing(vector<int> reports);

int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day3input.txt");
    string line;
    string mulstart = "mul(";

    int total = 0;
    while(!myfile.eof()){
        getline(myfile, line);

        string templine = line;
        for(int i=0; i<line.length(); i++){

            int start = line.find(mulstart); //gets the index at where the next mul( starts
            string currMul = line.substr(start, 12);

            //cout << currMul << endl;


            currMul = currMul.substr(4);

            int firstIndex = currMul.find(",");
            if(firstIndex != -1 && firstIndex < 4){
                string firstNum = currMul.substr(0,firstIndex);
                currMul = currMul.substr(firstIndex+1);
                
                
                
                int secondIndex = currMul.find(")");
                if(secondIndex != -1){
                    string secondNum = currMul.substr(0,secondIndex);
                    cout << firstNum << "end";
                    cout << secondNum << "end2" << endl;

                    total += stoi(firstNum) * stoi(secondNum);
                }

                //cout << currMul << endl;
            }
            line = line.substr(start+1);
        }
    }
    
    cout << total << endl;
    return 1;
}