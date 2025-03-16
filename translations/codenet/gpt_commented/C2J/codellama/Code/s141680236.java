#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototypes for stack operations
void push(int);
int pop();

// Global variables for stack management
int top, kinbo[1000]; // 'top' keeps track of the top index of the stack, 'kinbo' is the stack array

int main()
{
  int chonda, yamagami; // Variables to hold values popped from the stack
  top = 0; // Initialize the stack top index
  char null[100]; // Buffer to hold input strings

  // Read input until EOF
  while(scanf("%s", null) != EOF)
    {
      // If the input is a '+' operator, perform addition
      if(null[0] == '+')
	{
	  chonda = pop(); // Pop the top two values from the stack
	  yamagami = pop();
	  push(chonda + yamagami); // Push the result of addition back onto the stack
	}
      // If the input is a '-' operator, perform subtraction
      else if(null[0] == '-')
	{
	    yamagami = pop(); // Pop the top two values from the stack
	    chonda = pop();
	    push(chonda - yamagami); // Push the result of subtraction back onto the stack
	}
      // If the input is a '*' operator, perform multiplication
      else if(null[0] == '*')
	{
	   chonda = pop(); // Pop the top two values from the stack
	   yamagami = pop();
	   push(chonda * yamagami); // Push the result of multiplication back onto the stack
	}
      // If the input is a number, convert it to an integer and push onto the stack
      else
	push(atoi(null));
    }

  // Pop and print the final result from the stack
  printf("%d\n", pop());

  return 0; // End of the program
}

// Function to push an integer onto the stack
void push(int chonda)
{
  kinbo[++top] = chonda; // Increment the top index and store the value
}

// Function to pop an integer from the stack
int pop()
{
  top--; // Decrement the top index
  return kinbo[top + 1]; // Return the value at the previous top index
}

