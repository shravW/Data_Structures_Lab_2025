//Implementation of ListAdt using doubly LinkedList
#include<iostream>
using namespace std;

//Creating class
class list{
    private:
        struct node{
            int data;
            struct node* nextptr;
            struct node* prevptr;
        };
        struct node* head;
        struct node* tail;
        int count;
    public:
    list(){
        head=nullptr;
        tail=nullptr;
        count=0;
    }
        int insertbeg(int);
        int insertend(int);
        int insertpos(int,int);
        int deletebeg();
        int display();
        int deleteend();
        int deletepos(int);
        int search(int);
};

int main(){
    class list l1;
    int inf;
    int choice;
    inf=1;
    while (inf==1){
        //menu of the program
        cout<<endl<<"Enter 1 to insert in the beginning"<<endl;
        cout<< "Enter 2 to insert in the end"<<endl;
        cout<<"Enter 3 to insert in a desired position"<<endl;
        cout<<"Enter 4 to delete in beginning"<<endl;
        cout<<"Enter 5 to delete in the end"<<endl;
        cout<<"Enter 6 to delete in position"<<endl;
        cout<<"Enter 7 to search a given data"<<endl;
        cout<<"Enter 8 to display "<<endl;
        cout<<"Enter 9 to exit"<<endl;
        cout<<"Enter your choice ";
        cin>>choice;
        cout<<endl;
        if (choice==1){
            int val;
            cout<<"Enter the value you want to insert ";
            cin>>val;
            l1.insertbeg(val);
        }
        else if (choice==2){
            int val;
            cout<<"Enter the value you want to insert ";
            cin>>val;
            l1.insertend(val);
        }
        else if (choice==3){
            int val;
            cout<<"Enter the value you want to insert ";
            cin>>val;
            int pos;
            cout<<"Enter the position you want to insert in ";
            cin>>pos;
            l1.insertpos(val,pos);
        }
        else if (choice==4){
            l1.deletebeg();
        }
        else if (choice==5){
            l1.deleteend();
        }
        else if (choice==6){
            int pos;
            cout<<"Enter the position you want to delete in ";
            cin>>pos;
            l1.deletepos(pos);
        }
        else if (choice==7){
            int target;
            cout<<"Enter the element you want to search for";
            cin>>target;
            l1.search(target);
        }
        else if (choice==8){
            cout<<"The doubly linked list is "<<endl;
            l1.display();
        }
        else if (choice==9){
            cout<<"Over"<<endl;
            break;
        }
        else{
            cout<<"Enter valid choice"<<endl;
        }
    }
    return 0;
}

//Function to insert a new node in the beginning of the list
int list::insertbeg(int val){
    if (head==nullptr){
        struct node* newnode=new struct node();
        newnode->data=val;
        newnode->nextptr=head;
        newnode->prevptr=nullptr;
        head=newnode;
        tail=newnode;
        count++;
        return 0;
    }
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->nextptr=head;
    newnode->prevptr=nullptr;
    head->prevptr=newnode;
    head=newnode;
    count++;
    return 0;

}

//Function to insert a new node in the end of the list
int list::insertend(int val){
    if (head==nullptr){
        struct node* newnode=new struct node();
        newnode->data=val;
        newnode->nextptr=head;
        newnode->prevptr=nullptr;
        head=newnode;
        tail=newnode;
        count++;
        return 0;
    }
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->nextptr=nullptr;
    newnode->prevptr=tail;
    tail->nextptr=newnode;
    tail=newnode;
    count++;
    return 0;
}

// Function to insert a node in the given position
int list::insertpos(int val,int pos){
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->nextptr=nullptr;
    newnode->prevptr=nullptr;
    struct node* temp=head;
    if (pos==0){
        return insertbeg(val);
    }
    else if (pos==count){
        return insertend(val);
    }
    else if (pos<0 || pos>count){
        return -1;
    }
    else{
        for (int i=0;i<pos-1;i++){
            temp=temp->nextptr;
        }
        newnode->nextptr=temp->nextptr;
        newnode->prevptr=temp;
        temp->nextptr=newnode;
        temp->nextptr->nextptr->prevptr=newnode;
        count++;
        return 0;
    }
}

// Function to delete the beginning of the list
int list::deletebeg(){
    if (head==nullptr){
        cout<<"Empty list "<<endl;
        return -1;
    }
    if (head->nextptr==nullptr){
        struct node* temp=head;
        head=nullptr;
        tail=nullptr;
        count--;
        return temp->data;
    }
    struct node* temp=head;
    head->nextptr->prevptr=nullptr;
    head=head->nextptr;
    count--;
    return temp->data;
}

// Function to delete the end of the list
int list::deleteend(){
    if (head==nullptr){
        cout<<"Empty list "<<endl;
        return -1;
    }
    if (head->nextptr==nullptr){
        struct node* temp=head;
        head=nullptr;
        tail=nullptr;
        count--;
        return temp->data;
    }
    struct node* temp=head;
    tail->prevptr->nextptr=nullptr;
    tail=tail->prevptr;
    count--;
    return temp->data;
}

// Function to delete a node at a given position
int list::deletepos(int pos){
    struct node* temp=head;
    struct node* t1=nullptr;
    if (temp==nullptr){
        cout<<"Empty list"<<endl;
        return -1;
    }
    else if (pos<0 || pos>count){
        return -1;
    }
    for (int i=0;i<pos-1;i++){
        temp=temp->nextptr;
    }
    temp->prevptr->nextptr=temp->nextptr;
    temp->nextptr->prevptr=temp->prevptr;
    count--;
    return temp->data;
}

// Function to search for a node in the list
int list::search(int target){
    struct node* temp=head;
    if (temp==nullptr){
        cout<<"Empty list"<<endl;
        return -1;
    }
    int found;
    found=0;
    int i;
    i=0;
    while (temp!=nullptr){
        if (target==temp->data){
            cout<<"The target element is found in position "<<i<<endl;
            found=1;
            break;
        }
        else{
            temp=temp->nextptr;
            i+=1;
        }
    }
    if (found==0){
        cout<<"The target element is not in the list"<<endl;
    }
    return 0;
}

// Function to display the list
int list::display(){
    struct node* temp=head;
    if (temp==nullptr){
        cout<<"The list is empty";
        return -1;
    }
    while(temp->nextptr!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->nextptr;
    }
    cout<<temp->data<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->prevptr;
    }
    return 0;
}
