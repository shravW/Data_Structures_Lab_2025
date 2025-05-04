//Menu-driven program to implement List ADT using Singly Linked List
#include "qn2_listadt_sll_header.h"
#include <iostream>
using namespace std;

int main() {
    List list1, list2;
    int choice, value;
    //Menu of the program
    do {
        cout << "\nMenu:";
        cout << "\n1. Insert in Ascending Order";
        cout << "\n2. Merge with another list";
        cout << "\n3. Display List";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list1.insertAscending(value);
            break;
        case 2:
            cout << "Enter values for second list (end with -1): ";
            while (true) {
                cin >> value;
                if (value == -1) break;
                list2.insertAscending(value);
            }
            list1.merge(list2);
            cout << "Lists merged successfully!" << endl;
            break;
        case 3:
            list1.display();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
