import java.util.*;

public class Stack
{
  public static void main(String[] args)
  {
    int chonda, yamagami; // Variables to hold values popped from the stack
    int top = 0; // Initialize the stack top index
    String null; // Buffer to hold input strings

    // Read input until EOF
    while((null = System.console().readLine())!= null)
      {
	// If the input is a '+' operator, perform addition
	if(null.charAt(0) == '+')
	  {
	    chonda = pop(); // Pop the top two values from the stack
	    yamagami = pop();
	    push(chonda + yamagami); // Push the result of addition back onto the stack
	  }
	// If the input is a '-' operator, perform subtraction
	else if(null.charAt(0) == '-')
	  {
	    yamagami = pop(); // Pop the top two values from the stack
	    chonda = pop();
	    push(chonda - yamagami); // Push the result of subtraction back onto the stack
	  }
	// If the input is a '*' operator, perform multiplication
	else if(null.charAt(0) == '*')
	  {
	    chonda = pop(); // Pop the top two values from the stack
	    yamagami = pop();
	    push(chonda * yamagami); // Push the result of multiplication back onto the stack
	  }
	// If the input is a number, convert it to an integer and push onto the stack
	else
	  push(Integer.parseInt(null));
      }

    // Pop and print the final result from the stack
    System.out.println(pop());
  }

  // Function to push an integer onto the stack
  public static void push(int chonda)
  {
    top++; // Increment the top index and store the value
    kinbo[top] = chonda;
  }

  // Function to pop an integer from the stack
  public static int pop()
  {
    return kinbo[top--]; // Decrement the top index and return the value
  }

  // Global variables for stack management
  public static int top, kinbo[] = new int[1000];
}

