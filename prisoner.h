#ifndef PRISONER_H
#define PRISONER_H

#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

class Prisoner {

private:
    // Stuff that's not easily accessible
    string id, sentenceYears, firstName, lastName, lastMeal; 

public:
    //Stuff that is easily accessible
    Prisoner();
    Prisoner(const string& id, const string& firstName, const string& lastName, const string& sentenceYears, const string& lastMeal);

    // Getters
    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getSentenceYears() const;
    string getLastMeal() const;

    // Setters

    void setID(string newID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setSentenceYears(string years);
    void setLastMeal(string meal);

    // Operator overloads for comparison
    bool operator<(const Prisoner& other) const;
    bool operator>(const Prisoner& other) const;
    bool operator==(const Prisoner& other) const;

    // Stream operator overload
    friend ostream& operator<<(ostream& os, const Prisoner& prisoner);
};

#endif
