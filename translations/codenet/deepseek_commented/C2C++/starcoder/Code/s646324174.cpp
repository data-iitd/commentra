#include<iostream>
#include<stack>

using namespace std;

int main() {
    int a, b;
    char s[200];
    stack<int> st;

    // Read input until end of file
    while (cin >> s) {
        if (s[0] == '+') {
            // Pop two elements, add them, and push the result
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a + b);
        } else if (s[0] == '-') {
            // Pop two elements, subtract the top element from the bottom element, and push the result
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a - b);
        } else if (s[0] == '*') {
            // Pop two elements, multiply them, and push the result
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(a * b);
        } else {
            // Convert the input string to an integer and push it onto the stack
            st.push(atoi(s));
        }
    }
    // Print the final result from the stack
    cout << st.top() << endl;
    return 0;
}

