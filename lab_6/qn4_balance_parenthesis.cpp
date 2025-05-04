//Checking whether parentheses is balanced or not using Stack ADT
#include <iostream>
#include "stack_header.h"
using namespace std;

//Creating classes
class ParenthesisChecker {
public:
    bool isBalanced(string);
};

int main() {
    ParenthesisChecker checker;
    int choice;
    string expr;
    //menu of the program
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> expr;
                if (checker.isBalanced(expr)) {
                    cout << "Parenthesis is balanced.\n";
                } else {
                    cout << "Parenthesis is unbalanced.\n";
                }
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
        }
    } while (choice != 2);

    return 0;
}

//Checking whether the parenthesis is balanced or not
bool ParenthesisChecker::isBalanced(string expr) {
    Stack stack;
    for (char ch : expr) {
        if (ch == '(') {
            stack.Push(ch);
        } else if (ch == ')') {
            if (stack.Peek()==NULL) {
                return false;
            }
            stack.Pop();
        }
    }
    if (stack.Peek()==NULL) {
        return true;
    }
    return false;
}