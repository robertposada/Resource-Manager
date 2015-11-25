/*
Name(s): Kevin Nguyen & Robert Posada
Date: 11/20/2015
Project #3
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

class Record {
public:
    int time; //MAKE GETTERS FOR ALL OF THESE
    string name;
    int games; // number of games they want to play
    int rank; // priority
    // public methods for Record class
};

void read(vector <Record>& records) {
>>>>>>> upstream/master
    ifstream infile;
    string filename, fline;
    
    cout << "Name of file: ";
    getline(cin, filename);
    infile.open(filename);
    
    if (infile) { // check if file is "good"/not corrupted
        while (getline(infile, fline)) { // alternative to eof flag.
            Record temp;
            stringstream(fline) >> temp.time >> temp.name >> temp.games >> temp.rank;
            records.push_back(temp);
        }
    }
    else {
        cout << "ERROR: Cannot open file." << endl;
    }
    infile.close();
    return;
}

int main() {
    vector <Record> records;
    read(records);
    for (Record r : records) {
        cout << r.time << ' ' << r.name << ' ' << r.games << ' ' << r.rank << endl;
    }
    return 0;
}
