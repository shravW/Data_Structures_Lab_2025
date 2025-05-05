#include<iostream>
using namespace std;
struct node{
            int data;
            struct node* left;
            struct node* right;
        };

class tree{
    private:
        struct node* root;
    public:
    tree(){
        root=nullptr;
    }
        void setroot(node* n1){
            root=n1;
        }
        node* getroot(){
            return root;
        }
        node* insert(node*,int);
        void inorder(node*);
        void preorder(node*);
        void postorder(node*);
        bool search(node*,int);
};
int main(){
    int ch;
    node* node1=new node();
    class tree t1;
    while (true){
        cout<<"Enter 1 to insert an element"<<endl;
        cout<<"Enter 2 for preorder traversal"<<endl;
        cout<<"Enter 3 for inorder traversal"<<endl;
        cout<<"Enter 4 for postorder"<<endl;
        cout<<"Enter 5 to search for an element"<<endl;
        cout<<"Enter 6 to exit ";
        cin>>ch;
        cout<<endl;
        if (ch==1){
            int val;
            cout<<"Enter the value you want to insert ";
            cin>>val;
            node1=t1.insert(t1.getroot(),val);
            t1.setroot(node1);
        }
        else if (ch==2){
            t1.preorder(t1.getroot());
            cout<<endl;
        }
        else if (ch==3){
            t1.inorder(t1.getroot());
            cout<<endl;
        }
        else if (ch==4){
            t1.postorder(t1.getroot());
            cout<<endl;
        }
        else if (ch==5){
            bool res;
            int target;
            cout<<"Enter the target element ";
            cin>>target;
            res=t1.search(t1.getroot(),target);
            if (res==true){
                cout<<"The target element exists in the bst"<<endl;
            }
            else{
                cout<<"The target element does not exist in the bst"<<endl;
            }
        }
        else if (ch==6){
            break;
        }
        else{
            cout<<"Enter valid choice ";
        }
    }
    return 0;
}
//Function to insert a node in bst
node* tree::insert(node* temp,int val){
    if (temp==nullptr){
        node* newnode=new node();
        newnode->data=val;
        newnode->left=nullptr;
        newnode->right=nullptr;
        temp=newnode;
        return temp;
    }
    if (val<temp->data){
        temp->left=insert(temp->left,val);
    }
    else if (val>temp->data){
        temp->right=insert(temp->right,val);
    }

    return temp;
}
//Function to do preorder traversal in bst
void tree::preorder(node* temp){
    if (root==nullptr){
        cout<<"Empty tree ";
        return;
    }
    if (temp==nullptr){
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
//Function to do inorder traversal in bst
void tree::inorder(node* temp){
    if (root==nullptr){
        cout<<"Empty tree ";
        return;
    }
    if (temp==nullptr){
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
//Function to do postorder traversal in bst
void tree::postorder(node* temp){
    if (root==nullptr){
        cout<<"Empty tree ";
        return;
    }
    if (temp==nullptr){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
//Function to search for an element in the binary search tree
bool tree::search(node* temp,int target){
    if (temp==nullptr){
        return false;
    }
    if (temp->data==target){
        return true;
    }
    else if (temp->data<target){
        search(temp->left,target);
    }
    else if (temp->data>target){
        search(temp->right,target);
    }

    return false;
}