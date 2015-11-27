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

const string LOGFILE = "log.txt";

class Record {
private:
    int time;
    string name;
    int games; // number of games they want to play
    int rank; // priority
public:
    // public methods for Record class
    // getters
    int get_time();
    string get_name();
    int get_games();
    int get_rank();
    
    // friends
    friend void read(vector <Record>& records);
    friend void printR(Record rec);
};

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

class Manager {
private:
    Qlist<Record> gold, silver, bronze;
    vector <Record> team1, team2;
    int clock, gameStart, gameEnd;
public:
    // constructor
    Manager(Qlist<Record> g, Qlist<Record> s, Qlist<Record> b);
    
    // getters
    int get_clock();
    int get_gametime();
    
    // methods
    void make_teams();
    void write(Record rec, int option);
};

Manager::Manager(Qlist<Record> g,Qlist<Record> s, Qlist<Record> b) {
    clock = 0;
    gold = g;
    silver = s;
    bronze = b;
}

int Manager::get_clock() {
    return clock;
}

void Manager::make_teams() {
    team1.push_back(gold[0]);
    team2.push_back(gold[1]);
    team1.push_back(gold[2]);
    team2.push_back(silver[0]);
    team2.push_back(silver[1]);
    team1.push_back(bronze[0]);
    vector<Record> teams = team1;
    teams.insert(teams.end(), team2.begin(), team2.end());
    for (int i = 0; i < teams.size() - 1; i++) {
        for (int j = 1; j < teams.size(); j++) {
            if (teams.at(j).get_time() < teams.at(j - 1).get_time()) {
                Record temp = teams.at(j);
                teams.at(j) = teams.at(j - 1);
                teams.at(j - 1) = temp;
            }
        }
    }
    clock = gameStart = teams.at(teams.size()-1).get_time();
    gameEnd = gameStart + 10;
    for (Record r: teams) {
        write(r, 1);
    }
    for (Record r : team1) {
        write(r, 2);
    }
    for (Record r : team2) {
        write(r, 2);
    }
    for (Record r : team1) {
        write(r, 3);
    }
    for (Record r : team2) {
        write(r, 3);
    }
}

void Manager::write(Record rec, int option) {
    ofstream outfile;
    string fline;
    outfile.open(LOGFILE, ios::app);
    if (outfile) {
        switch (option) {
            case 1:
                outfile << rec.get_name() << " entered queue for " << rec.get_games() << " games at " << rec.get_time() << endl;
                break;
            case 2:
                outfile << rec.get_name() << " started game at " << gameStart << endl;
                break;
            case 3:
                outfile << rec.get_name() << " ended game at " << gameEnd << endl;
                break;
        }
    }
    else {
        cout << "ERROR: Cannot open file." << endl;
    }
    outfile.close();
    return;
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

void assignQ(vector <Record>& records, Qlist<Record>& g, Qlist<Record>& s, Qlist<Record>& b) {
    //assigning players to respective queue
    for (Record r : records) {
        if (r.get_rank() == 1)
            g.push_back(r);
        else if (r.get_rank() == 2)
            s.push_back(r);
        else
            b.push_back(r);
    }
}

int main() {
    vector <Record> records;
    Qlist<Record> gold, silver, bronze;
    read(records);
    assignQ(records, gold, silver, bronze);
    Manager rito = Manager(gold, silver, bronze);
    rito.make_teams();
    
    return 0;
}
