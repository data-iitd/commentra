
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

// Initialize stack top and array kinbo
int top = 0;
int kinbo[1000];

void push(int chonda)
{
  // Increment top and push element chonda into kinbo array
  kinbo[++top] = chonda;
}

int pop()
{
  // Decrement top and return the top element
  top--;
  return kinbo[top + 1];
}

int main()
{
  int chonda, yamagami; // Initialize variables chonda and yamagami

  // Initialize stack top to 0
  top = 0;

  char null[100]; // Initialize a character array null of size 100

  // Read input strings from standard input until EOF is reached
  while(cin >> null)
    {
      // Check if the first character of the input string is '+'
      if(null[0] == '+')
	{
	  // Pop two elements from the stack
	  chonda = pop();
	  yamagami = pop();

	  // Add the popped elements and push the result onto the stack
	  push(chonda + yamagami);
	}
      // Check if the first character of the input string is '-'
      else if(null[0] == '-')
	{
	  // Pop two elements from the stack
	  yamagami = pop();
	  chonda = pop();

	  // Subtract the second popped element from the first popped element and push the result onto the stack
	  push(chonda - yamagami);
	}
      // Check if the first character of the input string is '*'
      else if(null[0] == '*')
	{
	  // Pop two elements from the stack
	  chonda = pop();
	  yamagami = pop();

	  // Multiply the popped elements and push the result onto the stack
	  push(chonda * yamagami);
	}
      // If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
      else
	push(atoi(null));
    }

  // Print the top element of the stack, which is the final result
  cout << pop() << endl;

  return 0;
}

