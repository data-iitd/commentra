#include<iostream>
#include<string>
using namespace std;

int main() {
    // Declare variables to hold two integers and a character for the operation
    int a, b;
    char S;

    // Start an infinite loop to continuously accept user input
    while (true) {
        // Read two integers and an operator from the user
        cin >> a >> S >> b;

        // Perform addition if the operator is '+'
        if (S == '+') 
            cout << a + b << endl;

        // Perform subtraction if the operator is '-'
        if (S == '-') 
            cout << a - b << endl;

        // Perform multiplication if the operator is '*'
        if (S == '*') 
            cout << a * b << endl;

        // Perform division if the operator is '/'
        if (S == '/') 
            cout << a / b << endl;

        // Exit the loop if the operator is '?'
        if (S == '?') 
            break;
    }
}
