//Header file
#ifndef LIST_H
#define LIST_H
#include <iostream>

//creating class
class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    } *head;

public:
    List();
    ~List();
    void insertAscending(int val);  // Inserts in ascending order
    void merge(List& other);        // Merges two sorted lists
    void display() const;           // Displays the list
};

#endif // LIST_H
// Implementation of List class

List::List() : head(nullptr) {}//initialising

//destructing
List::~List() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//Inserts in ascending order
void List::insertAscending(int val) {
    Node* newNode = new Node(val);
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Merging two lists which are sorted
void List::merge(List& other) {
    Node* dummy = new Node(0);
    Node* tail = dummy;
    Node* p1 = head;
    Node* p2 = other.head;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    tail->next = p1 ? p1 : p2;
    head = dummy->next;
    delete dummy;
}

//Displaying the list
void List::display() const {
    if (!head) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
