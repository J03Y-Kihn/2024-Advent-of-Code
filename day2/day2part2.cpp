
//checking if a sets of data points are constantly increasing/decreasing and by no more than 3 more than the last number, but 1 number from each dataset can be removed
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

bool removeLevels(vector<int> reports);
bool increasing(vector<int> reports);
bool decreasing(vector<int> reports);

int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day2part1input.txt");
    string line;

    vector<vector<int>> reports;
    int safe = 0;
    while(!myfile.eof()){
        getline(myfile, line);
        
        stringstream currLine(line);
        vector<int> subreport;
        string currNum;
        while(currLine >> currNum){
            subreport.push_back(stoi(currNum));

        }
        reports.push_back(subreport);
    }
    
    cout << reports.size() << endl;
    for(int i=0; i<reports.size(); i++){
        if(reports[i][0] < reports[i][1]){
            if(increasing(reports[i])){
                safe++;
            }
            else if(removeLevels(reports[i])){
                safe++;
            }
        }
        else{
            if(decreasing(reports[i])){
                safe++;
            }
            else if(removeLevels(reports[i])){
                safe++;
            }
        }
    }
    
    cout << safe << endl;
    
    return 1;
}

bool removeLevels(vector<int> reports){
    //the level to skip
    for(int k=0; k<reports.size(); k++){
        //creating the new report then testing it
        vector<int> newreport;
        for(int j=0; j< reports.size();j++){
            if(k != j){
                newreport.push_back(reports[j]);
            }
        }

        if(increasing(newreport) || decreasing(newreport)){
            return true;
        }
    }
    return false;
}

bool increasing(vector<int> reports){
    for(int i=0; i<reports.size()-1;i++){
        if(reports[i] == reports[i+1] || reports[i]+3 < reports[i+1] || reports[i] > reports[i+1]){
            return false;
        }
    }
    return true;
}
bool decreasing(vector<int> reports){
    for(int i=0; i<reports.size()-1;i++){
        if(reports[i] == reports[i+1] || reports[i] > reports[i+1]+3 || reports[i] < reports[i+1]){
            return false;
        }
    }
    return true;
}