//Program to implement Hash ADT with linear probing
#include <iostream>
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;

class LinearProbing {
public:
    int current = 0;
    int max = 7;
    int hashtable[7];

    int hashfunction(int key) {
        return key % max;
    }

    void update();
    int insert(int num);
    int del(int num);
    int search(int num);
    void display();
};

void menu() {
    cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
    cout << "Enter Your Choice: ";
}

int main() {
    LinearProbing hash;
    int choice, result, num;
    hash.update();

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> num;
                result = hash.insert(num);
                if (result == -2)
                    cout << "The Hash Table is Full.\n";
                else
                    cout << "Inserted Successfully.\n";
                break;

            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> num;
                result = hash.del(num);
                if (result == -1)
                    cout << "Element not found or already deleted.\n";
                else
                    cout << "Deleted successfully.\n";
                break;

            case 3:
                cout << "Enter number to search: ";
                cin >> num;
                result = hash.search(num);
                if (result == -1)
                    cout << "Element not found.\n";
                else
                    cout << "Element found at index: " << result << endl;
                break;

            case 4:
                hash.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Input\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to set all elements to -1
void LinearProbing::update() {
    for (int i = 0; i < max; i++) {
        hashtable[i] = EMPTY;
    }
}
//Function to Insert into table
int LinearProbing::insert(int num) {
    if (current >= max) return -2;

    int key = hashfunction(num);
    for (int i = 0; i < max; i++) {
        int index = (key + i) % max;
        if (hashtable[index] == EMPTY || hashtable[index] == DELETED) {
            hashtable[index] = num;
            current++;
            return 1;
        }
    }
    return -2;
}
//Function to Delete from hash table
int LinearProbing::del(int num) {
    int key = hashfunction(num);
    for (int i = 0; i < max; i++) {
        int index = (key + i) % max;
        if (hashtable[index] == EMPTY) return -1;
        if (hashtable[index] == num) {
            hashtable[index] = DELETED;
            current--;
            return 1;
        }
    }
    return -1;
}
//Function to Search in the table
int LinearProbing::search(int num) {
    int key = hashfunction(num);
    for (int i = 0; i < max; i++) {
        int index = (key + i) % max;
        if (hashtable[index] == EMPTY) return -1;
        if (hashtable[index] == num) return index;
    }
    return -1;
}

void LinearProbing::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < max; i++) {
        if (hashtable[i] == EMPTY)
            cout << i << " : EMPTY\n";
        else if (hashtable[i] == DELETED)
            cout << i << " : DELETED\n";
        else
            cout << i << " : " << hashtable[i] << endl;
    }
}
