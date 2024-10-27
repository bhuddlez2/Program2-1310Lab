#ifndef PRISONER_H
#define PRISONER_H

#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

class Prisoner {

private:
    // Stuff that's not easily accessible
    int id, sentenceYears;
    string name, lastMeal; 

public:
    //Stuff that is easily accessible
    Prisoner();
    Prisoner(int id, string name, int sentenceYears, string lastMeal);

    // Getters
    int getID() const;
    string getName() const;
    int getSentenceYears() const;
    string getLastMeal() const;

    // Setters

    void setID(int newID);
    void setName(string newName);
    void setSentenceYears(int years);
    void setLastMeal(string meal);
     int getID() const;

    // Operator overloads for comparison
    bool operator<(const Prisoner& other) const;
    bool operator>(const Prisoner& other) const;
    bool operator==(const Prisoner& other) const;

    // Stream operator overload
    friend ostream& operator<<(ostream& os, const Prisoner& prisoner);
};

#endif
