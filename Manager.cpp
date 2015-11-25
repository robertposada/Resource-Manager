/*
Name(s): Kevin Nguyen & Robert Posada
Date: 11/20/2015
Project #3
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

class Record {
private:
    int time; //MAKE GETTERS FOR ALL OF THESE BITCHES
    string name;
    int games; // number of games they want to play
    int rank; // priority
public:
    // public methods for Record class
};

//make three queues and add the bitches in by rank into corresponding queue

void read(Record arr[]) {
    ifstream infile;
    string filename, fline;
    int i = 0;
    
    cout << "Name of file: ";
    getline(cin, filename);
    infile.open(filename);
    
    if (infile) { // check if file is "good"/not corrupted
        while (getline(infile, fline)) { // alternative to eof flag.
            Record temp;
            stringstream(fline) >> temp.time >> temp.name >> temp.games >> temp.rank;
            arr[i] = temp;
            i++;
        }
    }
    else {
        cout << "ERROR: Cannot open file." << endl;
    }
    infile.close();
    return;
}

int main() {
    
    return 0;
}
