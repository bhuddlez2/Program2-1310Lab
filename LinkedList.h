#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Prisoner.h" 

class LinkedList {
private:
    // Declare a structure for the list
    struct ListNode {
        Prisoner value;            
        ListNode *next;           // To point to the next node
        ListNode *previous;       // To point to the previous node
    };

    ListNode *head;              // List head pointer
    ListNode *tail;              // List tail pointer 
    int size;                    // Optional: To track the size of the list

public:
    // Constructor
    LinkedList() : head(NULL), tail(NULL), size(0) {}

    // Destructor
    ~LinkedList(); 

    // Linked list operations
    bool isEmpty() const { return head == NULL; }
    int getLength() const { return size; }
    Prisoner getNodeValue(int index); // Return a Prisoner at index
    void appendNode(const Prisoner &prisoner); // Accepts a Prisoner object
    void insertNode(int index, const Prisoner &prisoner);
    void deleteNode(int id); // Deletes based on unique prisoner ID
    void displayList() const; // Displays the list of prisoners
    //still need sorting functiona
};



#endif