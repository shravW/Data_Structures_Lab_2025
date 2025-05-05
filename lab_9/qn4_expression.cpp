#include <iostream>
#include <stack>
using namespace std;

class tree {
private:
    struct node {
        char data;
        node* left;
        node* right;
    };

    node* root;

public:
    // Constructor
    tree() {
        root = nullptr;
    }

    // Setter for root
    void setRoot(node* r) {
        root = r;
    }

    // Getter for root
    node* getRoot() {
        return root;
    }

    // Function declarations
    node* constructExpressionTree(string postfix);
    void inorder(node* node1);
    void preorder(node* node1);
    void postorder(node* node1);
};

int main() {
    tree t1;
    int choice;
    string postfix;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                t1.constructExpressionTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder: ";
                t1.preorder(t1.getRoot());
                cout << "\n";
                break;
            case 4:
                cout << "Inorder: ";
                t1.inorder(t1.getRoot());
                cout << "\n";
                break;
            case 5:
                cout << "Postorder: ";
                t1.postorder(t1.getRoot());
                cout << "\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

// --- Function Definitions ---

tree::node* tree::constructExpressionTree(string postfix) {
    stack<node*> st;
    for (char ch : postfix) {
        node* newNode = new node{ch, nullptr, nullptr};
        if (isalnum(ch)) {
            st.push(newNode);
        } else {
            if (st.size() < 2) {
                cout << "Invalid postfix expression!\n";
                return nullptr;
            }
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }

    if (st.size() != 1) {
        cout << "Invalid postfix expression!\n";
        return nullptr;
    }

    setRoot(st.top());
    return getRoot();
}

void tree::inorder(node* node1) {
    if (!node1) return;
    inorder(node1->left);
    cout << node1->data << " ";
    inorder(node1->right);
}

void tree::preorder(node* node1) {
    if (!node1) return;
    cout << node1->data << " ";
    preorder(node1->left);
    preorder(node1->right);
}

void tree::postorder(node* node1) {
    if (!node1) return;
    postorder(node1->left);
    postorder(node1->right);
    cout << node1->data << " ";
}
