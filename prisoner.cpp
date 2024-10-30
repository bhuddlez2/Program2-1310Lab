#include "prisoner.h"


    // Constructors
Prisoner::Prisoner(const string& id, const string& firstName, const string& lastName, const string& sentenceYears, const string& lastMeal)
    : id(id), firstName(firstName), lastName(lastName), sentenceYears(sentenceYears), lastMeal(lastMeal) {}

// Getters
string Prisoner::getID() const {
    return id;
}

string Prisoner::getFirstName() const {
    return firstName;
}

string Prisoner::getLastName() const {
    return lastName;
}

string Prisoner::getSentenceYears() const {
    return sentenceYears;
}

string Prisoner::getLastMeal() const {
    return lastMeal;
}

    // Setters
    void Prisoner::setID(string newID){
        id = newID;
    }

    void Prisoner::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Prisoner::setLastName(string newLastName) {
    lastName = newLastName;
}

    void Prisoner::setSentenceYears(string years){
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
       << ", First Name: " << prisoner.firstName
       << ", Last Name: " << prisoner.lastName
       << ", Sentence: " << prisoner.sentenceYears << " years"
       << ", What is the Prisoner's Last Meal? " << prisoner.lastMeal;
    return os;
}
