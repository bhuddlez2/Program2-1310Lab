
#include "LinkedList.h"
#include "prisoner.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    LinkedList linkedList;
    int choice;

    linkedList.loadPrisoners();

    do
    {
        cout << "\nMenu: ";
        cout << "\n1. Send someone to prison";
        cout << "\n2. Send prisoner to the guillotine";
        cout << "\n3. Inspect prisoner";
        cout << "\n4. Sort prisoners";
        cout << "\n5. End Program";
        cin >> choice;
        
        switch(choice)
        {
            case 1:


                break;
            case 2:

                break;
            case 3:
                
                break;
            case 4:

                break;
            case 5:
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

    } while (choice != 5);
    





    return 0;
}




