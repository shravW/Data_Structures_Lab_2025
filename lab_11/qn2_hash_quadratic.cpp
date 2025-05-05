// Program to implement Hash ADT with Quadratic Probing
#include <iostream>
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;

class QuadraticProbing {
public:
    int current = 0;
    int max = 7;
    int hashtable[7];

    int hashFunction(int key);
    void initialize();
    int insert(int num);
    int del(int num);
    int search(int num);
    void display();
};

void menu();

int main() {
    QuadraticProbing hash;
    int choice, result, num;
    hash.initialize();

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

// Menu display function
void menu() {
    cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
    cout << "Enter Your Choice: ";
}

// Initialize hash table with EMPTY (-1)
void QuadraticProbing::initialize() {
    for (int i = 0; i < max; i++) {
        hashtable[i] = EMPTY;
    }
}

// Hash function
int QuadraticProbing::hashFunction(int key) {
    return key % max;
}

// Insert with quadratic probing
int QuadraticProbing::insert(int num) {
    if (current >= max) return -2;

    int key = hashFunction(num);
    int i = 0;

    while (i < max) {
        int index = (key + i * i) % max;
        if (hashtable[index] == EMPTY || hashtable[index] == DELETED) {
            hashtable[index] = num;
            current++;
            return 1;
        }
        i++;
    }

    return -2; // Hash table full
}

// Delete an element
int QuadraticProbing::del(int num) {
    int key = hashFunction(num);
    int i = 0;

    while (i < max) {
        int index = (key + i * i) % max;
        if (hashtable[index] == EMPTY) return -1;
        if (hashtable[index] == num) {
            hashtable[index] = DELETED;
            current--;
            return 1;
        }
        i++;
    }

    return -1;
}

// Search for an element
int QuadraticProbing::search(int num) {
    int key = hashFunction(num);
    int i = 0;

    while (i < max) {
        int index = (key + i * i) % max;
        if (hashtable[index] == EMPTY) return -1;
        if (hashtable[index] == num) return index;
        i++;
    }

    return -1;
}

// Display the hash table
void QuadraticProbing::display() {
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
