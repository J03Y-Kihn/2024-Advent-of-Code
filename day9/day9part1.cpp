
//checking if a series of numbers are valid equations to get their result (before the :) by adding in + or *. Part 2 allows in string concatenation instead of + or * in the equation
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void printing(vector<char> prints);
long long int checkSum();
void compact();
void writeFile();

vector<char> mem;


int main(int argc, char* argv[]){

    ifstream myfile;
    myfile.open("day9input.txt");
    //myfile.open("sample.txt");
    string line;

    long long int total = 0;
    while(!myfile.eof()){
        getline(myfile, line);
        
        bool free = false;
        long long int counter =0;
        for(int i=0; i<line.length();i++){
            if(free){
                for(int j=0; j<line[i] -'0'; j++){
                    mem.push_back('.');
                }
                free = !free;
            }
            else{
                for(int j=0; j<line[i] -'0'; j++){
                    mem.push_back(counter);
                }
                counter++;
                free = !free;
            }
        }  
    }

    //1499791314 too low
    //printing(mem);
    compact();
    cout << checkSum() << endl;
    writeFile();
    return 1;
}

void printing(vector<char> prints){
    for(int i=0; i<prints.size(); i++){
        cout << int(prints[i]) << " ";
    }
    cout << endl;
    return;
}

long long int checkSum(){
    long long int total = 0;
    for(int i=0; i<mem.size(); i++){
        total += i * mem[i];
    }
    return total;
}

void compact(){
    for(int i=0; i< mem.size(); i++){
        if(mem[i] == '.'){
            mem[i] = mem.back();
            mem.pop_back();
            i--;
        }
    }
    return;
}

void writeFile(){

    ofstream outFile("output.txt");
    for(int i=0; i<mem.size(); i++){
        if(mem[i] != '.'){
            outFile << mem[i] << " ";
        }
        else{
            outFile << mem[i] << " ";
        }
    }
    outFile.close();
    return;
}