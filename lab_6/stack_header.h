//Menu-driven program to implement Stack ADT using Singly Linked List
#include <iostream>
using namespace std;

//LIFO - Last in First out
//Creating classes
class Stack{
    //Private members
    private:
    struct Node{
        char data;
        Node* next;
    };
    Node* top;
    //Public members
    public:
    Stack() {top=nullptr;};
    int Push(char);
    int Pop();
    char Peek();
};

//Pushing an element into the stack
int Stack::Push(char val){
    Node* newnode=new Node;
    //The element is pushed to the top as stack follows LIFO
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    return 1;
}

int Stack::Pop(){
    if (top==nullptr){
        //If the stack has no elements, nothing can be popped from the stack
        return -1;
    }
    //Otherwise the element at the top is popped as stack follows LIFO
    top=top->next;
    return 1;
}

char Stack::Peek(){
    if (top==nullptr){
        //If the stack has no elements, there is nothing there to peek at
        return 0;
    }
    //Otherwise the top element is looked at and displayed
    return top->data;
}