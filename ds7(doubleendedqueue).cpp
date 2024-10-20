#include <iostream>
using namespace std;
#define size 10

class stackexp
{
    int top;
    char stk[size];
public:
    stackexp()
    {
     top = -1;
    }
    void push(char);
    char pop();
    bool isfull();
    bool isempty();
    char peek();
};

void stackexp::push(char x)
{
    if (!isfull()) {
        stk[++top] = x;
    }
}

char stackexp::pop()
{
    if (!isempty()) {
        return stk[top--];
    }
    return '\0'; // Return null character if stack is empty
}

bool stackexp::isfull()
{
    return top == size - 1;
}

bool stackexp::isempty()
{
    return top == -1;
}

char stackexp::peek() {
    if (!isempty()) {
        return stk[top];
    }
    return '\0'; // Return null character if stack is empty
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

int main()
{
    char choice;
    
    do {
        stackexp s1;
        char exp[50], ch;
        int i = 0;

        cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
        cout << "\nEnter the expression to check whether it is in well form or not: ";
        cin >> exp;

        while (exp[i] != '\0')
        {
            ch = exp[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                s1.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (s1.isempty() || !isMatchingPair(s1.pop(), ch)) {
                    cout << "\nSorry !!! Invalid Expression or not well parenthesized....\n";
                    break;
                }
            }
            i++;
        }

        if (exp[i] == '\0') {
            if (s1.isempty()) {
                cout << "\nExpression is well parenthesized...\n";
            } else {
                cout << "\nSorry !!! Invalid Expression or not well parenthesized....\n";
            }
        }

        cout << "\nDo you want to check another expression? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting the program. Goodbye!\n";
    return 0;
}
