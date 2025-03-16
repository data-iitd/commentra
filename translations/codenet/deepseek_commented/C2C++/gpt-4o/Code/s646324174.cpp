#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Main function to read input, perform operations, and print the result
int main() {
    stack<int> S; // Define the stack
    string s;

    // Read input until end of file
    while (cin >> s) {
        if (s == "+") {
            // Pop two elements, add them, and push the result
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a + b);
        } else if (s == "-") {
            // Pop two elements, subtract the top element from the bottom element, and push the result
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a - b);
        } else if (s == "*") {
            // Pop two elements, multiply them, and push the result
            int b = S.top(); S.pop();
            int a = S.top(); S.pop();
            S.push(a * b);
        } else {
            // Convert the input string to an integer and push it onto the stack
            S.push(stoi(s));
        }
    }
    // Print the final result from the stack
    cout << S.top() << endl;
    return 0;
}

// <END-OF-CODE>
