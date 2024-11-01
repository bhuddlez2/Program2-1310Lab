#include "LinkedList.h"
#include "prisoner.h"
#include <iostream>
#include <fstream>

 using namespace std;

 // isEmpty returns true if the list has no nodes and false if it does
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Get the length of the list
int LinkedList::getLength() const {
    return size; // Use the size member variable
}

// Returns the prisoner at a given integer position
Prisoner LinkedList::getNodeValue(int position) {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    if (position < 0 || position >= size) {
        throw std::out_of_range("Index out of range");
    }

    ListNode *nodePtr = head;
    for (int currentPos = 0; currentPos < position; ++currentPos) {
        nodePtr = nodePtr->next;
    }
    return nodePtr->value;
}

// Append a prisoner to the end of the list
void LinkedList::appendNode(const Prisoner &prisoner) {
    ListNode *newNode = new ListNode{prisoner, nullptr, tail};

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Insert a new prisoner at the specified position
void LinkedList::insertNode(int position, const Prisoner &prisoner) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Index out of range");
    }

    ListNode *newNode = new ListNode{prisoner, nullptr, nullptr};

    if (position == 0) {
        newNode->next = head;
        if (head) {
            head->previous = newNode;
        }
        head = newNode;
        if (size == 0) {
            tail = newNode;
        }
    } else {
        ListNode *nodePtr = head;
        for (int nodeCount = 0; nodeCount < position - 1; ++nodeCount) {
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr->next;
        newNode->previous = nodePtr;
        nodePtr->next = newNode;

        if (newNode->next) {
            newNode->next->previous = newNode;
        } else {
            tail = newNode; // If we inserted at the end, update the tail
        }
    }
    size++;
}

// Display the list of prisoners
void LinkedList::displayList() const {
    ListNode *nodePtr = head;

    while (nodePtr) {
        cout << nodePtr->value << endl; // Using the overloaded operator<< for Prisoner
        nodePtr = nodePtr->next;
    }
}

// Delete a prisoner by ID
void LinkedList::deleteNode(string id) {
    if (!head) return; // List is empty

    ListNode *nodePtr = head;

    // Check if the first node is the one to be deleted
    if (head->value.getID() == id) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        if (head) {
            head->previous = nullptr;
        } else {
            tail = nullptr; // List is now empty
        }
        size--;
        return;
    }

    // Traverse the list to find the node
    while (nodePtr && nodePtr->value.getID() != id) {
        nodePtr = nodePtr->next;
    }

    // If nodePtr is found, delete it
    if (nodePtr) {
        if (nodePtr == tail) {
            tail = nodePtr->previous; // Update tail if necessary
        } else {
            nodePtr->next->previous = nodePtr->previous; // Update the next node's previous pointer
        }

        nodePtr->previous->next = nodePtr->next; // Update the previous node's next pointer
        delete nodePtr;
        size--;
    } else {
        cout << "Prisoner with ID " << id << " not found.\n";
    }
}

// Destructor
LinkedList::~LinkedList() {
    ListNode *nodePtr = head;
    while (nodePtr) {
        ListNode *nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void LinkedList::loadPrisoners()
{
    int i=0;
    ifstream inputFile("prisoner.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file: " << "prisoner.txt" << endl;
        return;
    }
    
    string ID, firstName, lastName, years, meal;
    while (inputFile >> ID >> firstName >> lastName >> years >> meal)
    {
        Prisoner* prisoner = new Prisoner(ID, firstName, lastName, years, meal);
        insertNode(i, *prisoner);
    }
}

bool LinkedList::IDCheck(const string& id) const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        if (nodePtr->value.getID() == id) {
            return true; // ID found
        }
        nodePtr = nodePtr->next;
    }
    return false; // ID not found
}

