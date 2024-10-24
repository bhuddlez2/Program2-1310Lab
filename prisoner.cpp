#include "prisoner.h"


    // Constructors
Prisoner::Prisoner(int id, string name, int sentenceYears, string lastMeal)
    : id(id), name(name), sentenceYears(sentenceYears), lastMeal(lastMeal) {}

    // Setters
    void Prisoner::setID(int newID){
        id = newID;
    }

    void Prisoner::setName(string newName){
        name = newName;
    }

    void Prisoner::setSentenceYears(int years){
        sentenceYears = years;
    }

    void Prisoner::setLastMeal(string meal){
        lastMeal = meal;
    }


// Overload operators
bool Prisoner::operator<(const Prisoner& other) const {
    return id < other.id;
}

bool Prisoner::operator>(const Prisoner& other) const {
    return id > other.id;
}

bool Prisoner::operator==(const Prisoner& other) const {
    return id == other.id;
}

// Stream operator overload and prints out stuff
ostream& operator<<(ostream& os, const Prisoner& prisoner) {
    os << "ID: " << prisoner.id
       << ", Name: " << prisoner.name
       << ", Sentence: " << prisoner.sentenceYears << " years"
       << ", What is the Prisoner's Last Meal? " << prisoner.lastMeal;
    return os;
}
