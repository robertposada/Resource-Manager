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
private:
    int time; //MAKE GETTERS FOR ALL OF THESE
    string name;
    int games; // number of games they want to play
    int rank; // priority
public:
    // public methods for Record class
    //GETTERS
    int get_time();
    string get_name();
    int get_games();
    int get_rank();
    //friends
    friend void read(vector <Record>& records);
    friend void printR(Record rec);
};

class Manager {
private:
    Qlist<Record> gold, silver, bronze;
    vector <Record> team1, team2;
    int clock;
public:
    //constructor
    Manager(Qlist<Record> g, Qlist<Record> s, Qlist<Record> b);
    //methods
    void make_teams();
};

Manager::Manager(Qlist<Record> g,Qlist<Record> s, Qlist<Record> b) {
    clock = 0;
    gold = g;
    silver = s;
    bronze = b;
}

void make_teams() {
    
    
}

int Record::get_time() {
    return time;
}

string Record::get_name() {
    return name;
}

int Record::get_games() {
    return games;
}

int Record::get_rank() {
    return rank;
}

void read(vector <Record>& records) {
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

void printR(Record rec) {
    cout << "Name: " << rec.name << endl << "Rank: ";
    if (rec.rank == 1)
        cout << "Gold";
    else if (rec.rank == 2)
        cout << "Silver";
    else
        cout << "Bronze";
    cout << endl << "Games: " << rec.games << endl;
}

void assignQ(vector <Record>& records, Qlist<Record>& g, Qlist<Record>& s, Qlist<Record>& b) {
    //assigning players to respective queue
    for (Record r : records) {
        if (r.get_rank() == 1)
            g.push_front(r);
        else if (r.get_rank() == 2)
            s.push_front(r);
        else
            b.push_front(r);
    }
}

int main() {
    vector <Record> records;
    Qlist<Record> gold, silver, bronze;
    read(records);
    assignQ(records, gold, silver, bronze);
    for (int i = 0; i < gold.getSize(); i++) {
        printR(gold[i]);
    }
    return 0;
}
