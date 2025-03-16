#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

// Function declarations for stack operations
void push(stack<int>& s, int value);
int pop(stack<int>& s);

// Main function
int main()
{
    // Variables to store input values
    int chonda, yamagami;

    // Stack to store integers
    stack<int> kinbo;

    // Array to store input characters temporarily
    char null[100];

    // Read input until end of file
    while (cin >> null)
    {
        // Check the operation based on the first character of the input
        if (null[0] == '+')
        {
            // Pop two values, add them, and push the result
            chonda = pop(kinbo);
            yamagami = pop(kinbo);
            push(kinbo, chonda + yamagami);
        }
        else if (null[0] == '-')
        {
            // Pop two values, subtract the second from the first, and push the result
            yamagami = pop(kinbo);
            chonda = pop(kinbo);
            push(kinbo, chonda - yamagami);
        }
        else if (null[0] == '*')
        {
            // Pop two values, multiply them, and push the result
            chonda = pop(kinbo);
            yamagami = pop(kinbo);
            push(kinbo, chonda * yamagami);
        }
        else
        {
            // Convert input to integer and push it onto the stack
            push(kinbo, atoi(null));
        }
    }

    // Print the final result from the stack
    cout << pop(kinbo) << endl;

    return 0;
}

// Function to push a value onto the stack
void push(stack<int>& s, int value)
{
    s.push(value);
}

// Function to pop a value from the stack
int pop(stack<int>& s)
{
    int value = s.top();
    s.pop();
    return value;
}

// <END-OF-CODE>
