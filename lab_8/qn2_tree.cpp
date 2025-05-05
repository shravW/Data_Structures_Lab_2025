#include<iostream>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};
class tree{
        
    public:
    node* root;
    tree(){
        root=nullptr;
    }
        node* insert(node*,char);
        void inorder(node*);
        void preorder(node*);
        void postorder(node*);
        bool search(node*,char);
};
int main(){
    class tree t1;
    int inf;
    inf=1;
    int ch;
    while (inf==1){
        cout<<"Enter 1 to insert "<<endl;
        cout<<"Enter 2 to traverse inorder"<<endl;
        cout<<"Enter 3 to traverse preorder"<<endl;
        cout<<"Enter 4 to traverse postorder"<<endl;
        cout<<"Enter 5 to search"<<endl;
        cout<<"Enter 6 to exit"<<endl;
        cin>>ch;
        if (ch==1){
            char a;
            cout<<"Enter the character ";
            cin>>a;
            t1.root=t1.insert(t1.root,a);
            cout<<t1.root<<" ";
        }
        else if (ch==2){
            t1.inorder(t1.root);
            cout<<endl;
        }
        else if(ch==3){
            t1.preorder(t1.root);
            cout<<endl;
        }
        else if(ch==4){
            t1.postorder(t1.root);
            cout<<endl;
        }
        else if (ch==5){
            char tar;
            cout<<"Enter the target element"<<" ";
            cin>>tar;
            bool res;
            res=t1.search(t1.root,tar);
            if (res==true){
                cout<<"Element is there"<<endl;
            }
            else{
                cout<<"Element is not there"<<endl;
            }

        }
        else if (ch==6){
            break;
        }
        else{
            cout<<"Enter Valid Choice"<<endl;
        }
    }
    
    return 0;
}

node* tree::insert(node* node1,char a){
    if (node1==nullptr){
        node* newnode=new node();
        newnode->data=a;
        newnode->left=nullptr;
        newnode->right=nullptr;
        return newnode;
    }

    char ch;
    cout<<"Enter Left or right of "<<node1->data<<" ";
    cin>>ch;
    if (ch=='l'){
        node1->left=insert(node1->left,a);
    }
    else if (ch=='r'){
        node1->right=insert(node1->right,a);
    }
    
}

void tree::inorder(node* node1){
    if (root==nullptr){
        cout<<"Empty tree";
    }
    if (node1==nullptr){
        return;
    }
    inorder(node1->left);
    cout<<node1->data<<" ";
    inorder(node1->right);
}

void tree::preorder(node* node1){
    if (root==nullptr){
        cout<<"Empty tree";
    }
    if (node1==nullptr){
        return;
    }
    cout<<node1->data<<" ";
    preorder(node1->left);
    preorder(node1->right);
}

void tree::postorder(node* node1){
    if (root==nullptr){
        cout<<"Empty tree";
    }
    if (node1==nullptr){
        return;
    }
    postorder(node1->left);
    postorder(node1->right);
    cout<<node1->data<<" ";
}

bool tree::search(node* node1,char target){
    if (node1==nullptr){
        return false;
    }
    if (node1->data==target){
        return true;
    }
    return search(node1->left,target) || search(node1->right,target);
}