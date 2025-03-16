#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

// Function declarations for stack operations
void push(int);
int pop();

// Global variables for stack and top index
int top, kinbo[1000];

int main()
{
  // Variables to store input values
  int chonda, yamagami;
  
  // Initialize the top index of the stack
  top = 0;
  
  // Array to store input characters temporarily
  char null[100];

  // Read input until end of file
  while(cin >> null)
  {
    // Check the operation based on the first character of the input
    if(null[0] == '+')
    {
      // Pop two values, add them, and push the result
      chonda = pop();
      yamagami = pop();
      push(chonda + yamagami);
    }
    else if(null[0] == '-')
    {
      // Pop two values, subtract the second from the first, and push the result
      yamagami = pop();
      chonda = pop();
      push(chonda - yamagami);
    }
    else if(null[0] == '*')
    {
      // Pop two values, multiply them, and push the result
      chonda = pop();
      yamagami = pop();
      push(chonda * yamagami);
    }
    else
    {
      // Convert input to integer and push it onto the stack
      push(atoi(null));
    }
  }

  // Print the final result from the stack
  cout << pop() << endl;

  return 0;
}

// Function to push a value onto the stack
void push(int chonda)
{
  kinbo[++top] = chonda;
}

// Function to pop a value from the stack
int pop()
{
  top--;
  return kinbo[top + 1];
}

