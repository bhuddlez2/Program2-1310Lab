#ifndef PRISONER_H
#define PRISONER_H

#include <iostream>
#include <string>

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

    // Setters

    void setID(int newID);
    void setName(string newName);
    void setSentenceYears(int years);
    void setLastMeal(string meal);

    // Operator overloads for comparison
    bool operator<(const Prisoner& other) const;
    bool operator>(const Prisoner& other) const;
    bool operator==(const Prisoner& other) const;

    // Stream operator overload
    friend ostream& operator<<(ostream& os, const Prisoner& prisoner);
};

#endif
