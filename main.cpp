// COMSC-210 | Lab 23 | Ahmad Dharhan

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    int choice = 0;
    list<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    while(choice != 4){

        choice = main_menu();

        if(choice == 1){
            add_goat(trip, names, colors);
        }

        else if(choice == 2){
            delete_goat(trip);
        }

        else if(choice == 3){
            display_trip(trip);
        }

    }

    return 0;

}

//main_menu func displays options
//arguments none
//returns choice by user for menu
int main_menu(){
    int n = 0;
        cout << endl;
        cout << endl;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice ---> ";
        cin >> n;

        cout << endl;
        cout << endl;

        if (n < 1 || n > 4){
            cout << "Invalid Input. View options and try again" << endl;
            cout << "Choice -->";
            cin >> n;
        }

    return n;
}

//Void function
//Checks if empty; if not cout 
//Returns nothing
void display_trip(list<Goat> trip){
    int val = 1;
    if(trip.empty()){
        cout << "List is empty!" << endl;
        return;
    }
   
    for(Goat g: trip){
        cout << "[";
        cout << val;
        cout  << "] ";
        cout << g.get_name();
        cout << " (" << g.get_age() << ", ";
        cout << g.get_color() << ")"<< endl;
        val += 1;
    }

}

//void delete goat that deletes selected goat
//arguments: trip
//reutrns none
void delete_goat(list<Goat> &trip){

    if(trip.empty()){
        cout << "List is empty! Nothing to delete" << endl;
        return;
    }

    //Uses select_goat function to delete goat
    int goat_choice = select_goat(trip);
    int count = 1;

    for(auto it = trip.begin(); it != trip.end(); it++){
        if(count == goat_choice){
            trip.erase(it);
            cout << endl;
            display_trip(trip);
            return;
        }

        count++;
    }

}

//void add_goat function
//arguments: list, string of names and colors to rand select
//returns nothing only updates list
void add_goat(list<Goat> &trip, string names[], string colors[]){
    int age = rand() % (MAX_AGE + 1);
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];

    Goat g(name, age, color);

    trip.push_back(g);

    display_trip(trip);
}

//select goat function
//arguments: list
//returns: goat position
int select_goat(list<Goat> trip){
    int goat_num;

    display_trip(trip);

    cout << "Which goat would you like to select? ";
    cin >> goat_num;

    return goat_num;

}