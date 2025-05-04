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

int main(){
    Stack stack;
    char val;
    int choice;
    int res;
    do{
        //Menu of the program
        cout<<"\nMenu\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Which function to do : ";
        cin>>choice;
        cout<<"\n";
        switch(choice){
            case 1:
                //Pushing an element into the stack
                cout<<"Element to push : ";
                cin>>val;
                cout<<"\n";
                res=stack.Push(val);
                if (res!=1){
                    cout<<"Stack overflow!\n";
                }
                else{
                    cout<<"Element pushed into stack\n";
                }
                break;
            case 2:
                //Popping an element from the stack
                cout<<"Pop element\n";
                res=stack.Pop();
                if (res!=1){
                    cout<<"Stack has no elements!\n";
                }
                else{
                    cout<<"Element popped from the stack\n";
                }
                break;
            case 3:
                //Peeking into the stack (Displaying the top-most element in the stack)
                cout<<"Peek into the stack\n";
                val=stack.Peek();
                if (val==NULL){
                    cout<<"\nStack has no elements\n";
                }
                else{
                    cout<<"\nThe top element is "<<val<<"\n";
                }
                break;
            case 4:
                //Exiting the program
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid input\n";
        }
    }while(choice!=4);
}

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