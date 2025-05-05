// Program to implement Hash ADT with Separate Chaining (Insert at beginning)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val);
};

class SeparateChaining {
public:
    static const int max = 7;
    Node* hashtable[max];

    SeparateChaining();  // Constructor
    int hashFunction(int key);
    void insert(int num);
    bool del(int num);
    int search(int num);
    void display();
};

void menu();


int main() {
    SeparateChaining hash;
    int choice, num, result;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> num;
                hash.insert(num);
                cout << "Inserted Successfully.\n";
                break;

            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> num;
                if (hash.del(num))
                    cout << "Deleted Successfully.\n";
                else
                    cout << "Element not found.\n";
                break;

            case 3:
                cout << "Enter number to search: ";
                cin >> num;
                result = hash.search(num);
                if (result != -1)
                    cout << "Element found at index: " << result << endl;
                else
                    cout << "Element not found.\n";
                break;

            case 4:
                hash.display();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout << "Invalid Input\n";
        }
    } while (choice != 5);

    return 0;
}



void menu() {
    cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
    cout << "Enter Your Choice: ";
}

// Constructor for Node
Node::Node(int val) {
    data = val;
    next = nullptr;
}

// Constructor for SeparateChaining
SeparateChaining::SeparateChaining() {
    for (int i = 0; i < max; i++) {
        hashtable[i] = nullptr;
    }
}

// Hash function
int SeparateChaining::hashFunction(int key) {
    return key % max;
}

// Insert at beginning
void SeparateChaining::insert(int num) {
    int index = hashFunction(num);
    Node* newNode = new Node(num);
    newNode->next = hashtable[index];
    hashtable[index] = newNode;
}

// Delete from hash table
bool SeparateChaining::del(int num) {
    int index = hashFunction(num);
    Node* curr = hashtable[index];
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == num) {
            if (prev == nullptr) {
                hashtable[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

// Search in hash table
int SeparateChaining::search(int num) {
    int index = hashFunction(num);
    Node* curr = hashtable[index];
    while (curr != nullptr) {
        if (curr->data == num)
            return index;
        curr = curr->next;
    }
    return -1;
}

// Display hash table
void SeparateChaining::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < max; i++) {
        cout << i << " : ";
        Node* curr = hashtable[i];
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}
