#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "prisoner.h" 

using namespace std;
class LinkedList {
private:
    // Declare a structure for the list
    struct ListNode {
        Prisoner value;            
        ListNode *next;           // To point to the next node
        ListNode *previous;       // To point to the previous node

        // Constructor
        ListNode(const Prisoner& prisoner, ListNode* nextNode = nullptr, ListNode* prevNode = nullptr)
        : value(prisoner), next(nextNode), previous(prevNode) {}
    };

    ListNode *head;              // List head pointer
    ListNode *tail;              // List tail pointer 
    int size;                    // Optional: To track the size of the list

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~LinkedList(); 

    // Linked list operations
    bool isEmpty() const;
    int getLength() const;
    Prisoner getNodeValue(int index); // Return a Prisoner at index
    void appendNode(const Prisoner &prisoner); // Accepts a Prisoner object
    void insertNode(int index, const Prisoner &prisoner);
    void deleteNode(std::string id); // Deletes based on unique prisoner ID
    void displayList() const; // Displays the list of prisoners
    void loadPrisoners(); // Loads in the prisoners from the txt file
    bool IDCheck(const string& id) const; // checks if prisoner ID is correct
    void sortByLastName(); // Sort prisoners by last name
    void sortByYears();     // Sort prisoners by sentence years
    void sortByID();        // Sort prisoners by ID
};



#endif