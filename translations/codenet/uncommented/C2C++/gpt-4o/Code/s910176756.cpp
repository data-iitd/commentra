#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    char op;
    cin >> a >> op >> b;

    while (true) {
        if (op == '+') {
            c = a + b;
            cout << c << endl;
        } 
        else if (op == '-') {
            c = a - b;
            cout << c << endl;
        } 
        else if (op == '*') {
            c = a * b;
            cout << c << endl;
        } 
        else if (op == '/') {
            if (b != 0) {
                c = a / b;
                cout << c << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
        } 
        else {
            break;
        }
        cin >> a >> op >> b;
    }
    return 0;
}

// <END-OF-CODE>
