//CSC 1310 LAB PROGRAM 02
//PRIVATELY OWNED PRISON
// GROUP PA2-7
#include "LinkedList.h"
#include "prisoner.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    LinkedList linkedList;
    int choice;
    string id, firstName, lastName, sentenceYears, lastMeal;
    Prisoner newPrisoner(id, firstName, lastName, sentenceYears, lastMeal);

    linkedList.loadPrisoners();

    do
    {
        cout << "\nMenu: ";
        cout << "\n1. Send someone to prison";
        cout << "\n2. Inspect prisoners";
        cout << "\n3. Send prisoner to the guillotine";
        cout << "\n4. End Program";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Sentence Years: ";
                cin >> sentenceYears;
                cout << "Enter Last Meal: ";
                cin >> lastMeal;
                linkedList.appendNode(newPrisoner);
                cout << "Prisoner added successfully.\n";
                break;
            case 2:
                cout << "Sort by:\n";
                cout << "1. Last Name\n";
                cout << "2. Sentence Years\n";
                cout << "3. ID\n";
                int sortChoice;
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        //linkedList.sortByLastName();
                        break;
                    case 2:
                        //linkedList.sortByYears(); // You'll need to implement this
                        break;
                    case 3:
                        //linkedList.sortByID();
                        break;
                    default:
                    cout << "Invalid choice.\n";

        // Display the list after sorting
            linkedList.displayList();
            break;
    }
                break;
            case 3:
                cout << "Enter ID of prisoner to delete: ";
                cin >> id;
    // Check if the prisoner with the given ID exists
                if (linkedList.IDCheck(id)) {
                    linkedList.deleteNode(id);
                    cout << "Prisoner with ID " << id << " has been deleted.\n";
                } else {
                    cout << "Prisoner with ID " << id << " not found.\n";
                }
                break;
            case 4:
                cout << "\nGood Day Sir.";
                break;
            default:
                if (cin.fail()) 
                {
                    cout << "\nYou entered something other than a number \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }    
                else 
                {
                    cout << "Invalid choice. Please try again.\n";
                }

        }

    } while (choice != 4);
    





    return 0;
}




