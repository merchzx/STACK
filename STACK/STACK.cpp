#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* stackArray;
    int maxSize;
    int top;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new char[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(char value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow." << endl;
            return;
        }
        stackArray[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return '\0';
        }
        return stackArray[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

bool checkBrackets(const string& expression) {
    Stack stack(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        char chr = expression[i];

        if (chr == '(' || chr == '{' || chr == '[') {
            stack.push(chr);
        }
        else if (chr == ')' || chr == '}' || chr == ']') {
            if (stack.isEmpty()) {
                cout << "Error: closing bracket without opening at position " << i << endl;
                return false;
            }
            char open_bracket = stack.pop();
            if ((chr == ')' && open_bracket != '(') ||
                (chr == '}' && open_bracket != '{') ||
                (chr == ']' && open_bracket != '[')) {
                cout << "Error: mismatched brackets at position " << i << endl;
                return false;
            }
        }
    }

    if (!stack.isEmpty()) {
        cout << "Error: not all brackets are closed." << endl;
        return false;
    }

    return true;
}

int main() {
    string viragenie;
    cout << "Enter an viragenie: ";
    getline(cin, viragenie);

    if (checkBrackets(viragenie)) {
        cout << "The viragenie is correct!" << endl;
    }
    else {
        cout << "The viragenie is incorrect!" << endl;
    }
}
