//Menu-driven program to implement infix to postfix and postfix evaluation using Stack ADT
#include <iostream>
#include <cctype>
#include <cstring>
#include "stack_header.h"
using namespace std;

//Creating classes
class InfixPostfix{
private:
    //Private members
    string infix;
    string postfix;
public:
    //Public members
    int Infixget(string);
    int converttoPostfix();
    float evaluatePostfix();
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%' ) return 2;
        return 0;
    }
};

int main(){
    InfixPostfix fixer;
    int choice;
    string val;
    do{
        //Menu of the program
        cout<<"\nMenu\n";
        cout<<"1. Get Infix\n";
        cout<<"2. Convert\n";
        cout<<"3. Evaluate Postfix\n";
        cout<<"4. Exit\n";
        cout<<"Which function to do : ";
        cin>>choice;
        cout<<"\n";
        switch(choice){
            case 1:
                //Getting an infix expression
                cout << "Give infix expression : ";
                cin >> val;
                fixer.Infixget(val);
                cout << "\n";
                break;
            case 2:
                //Conversion of infix to postfix
                fixer.converttoPostfix();
                cout << "\n";
                break;
            case 3:
                //Evaluation of the postfix expression
                cout << "Result : " << fixer.evaluatePostfix() << "\n";
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

//Getting an infix expression
int InfixPostfix::Infixget(string val){
    infix = val;
    return 1;
}

//Conversion of infix to postfix
int InfixPostfix::converttoPostfix(){
    Stack stack;
    postfix= "";
    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.Push(ch);
        }
        else if (ch == ')') {
            while (stack.Peek()!=NULL && stack.Peek() != '(') {
                postfix += stack.Peek();
                stack.Pop();
            }
            stack.Pop();
        }
        else {
            while (stack.Peek()!=NULL && precedence(stack.Peek()) >= precedence(ch)) {
                postfix += stack.Peek();
                stack.Pop();
            }
            stack.Push(ch);
        }
    }

    while (stack.Peek()!=NULL) {
        postfix += stack.Peek();
        stack.Pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
    return 1;
}

//Evaluation of Postfix
float InfixPostfix::evaluatePostfix(){
        Stack stack;
        for (char ch : postfix) {
            if (isdigit(ch)) {
                stack.Push(ch - '0'); // Convert char to int
            }
            else {
                int val2 = stack.Peek(); stack.Pop();
                int val1 = stack.Peek(); stack.Pop();
                switch (ch) {
                    case '+': stack.Push(val1 + val2); break;
                    case '-': stack.Push(val1 - val2); break;
                    case '*': stack.Push(val1 * val2); break;
                    case '/': stack.Push(val1 / val2); break;
                    case '%': stack.Push(val1 % val2); break;
                }
            }
        }
        return stack.Peek();
    }
