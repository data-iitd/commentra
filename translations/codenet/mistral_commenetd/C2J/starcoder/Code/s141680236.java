
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    int chonda, yamagami; // Initialize variables chonda and yamagami

    // Initialize stack top to 0
    int top = 0;

    char null[100]; // Initialize a character array null of size 100

    // Read input strings from standard input until EOF is reached
    Scanner in = new Scanner(System.in);
    while(in.hasNext())
    {
      // Check if the first character of the input string is '+'
      if(in.next().charAt(0) == '+')
      {
	// Pop two elements from the stack
	chonda = pop();
	yamagami = pop();

	// Add the popped elements and push the result onto the stack
	push(chonda + yamagami);
      }
      // Check if the first character of the input string is '-'
      else if(in.next().charAt(0) == '-')
      {
	// Pop two elements from the stack
	yamagami = pop();
	chonda = pop();

	// Subtract the second popped element from the first popped element and push the result onto the stack
	push(chonda - yamagami);
      }
      // Check if the first character of the input string is '*'
      else if(in.next().charAt(0) == '*')
      {
	// Pop two elements from the stack
	chonda = pop();
	yamagami = pop();

	// Multiply the popped elements and push the result onto the stack
	push(chonda * yamagami);
      }
      // If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
      else
	push(Integer.parseInt(in.next()));
    }

    // Print the top element of the stack, which is the final result
    System.out.println(pop());
  }

  // Initialize stack top and array kinbo
  static int top = 0;
  static int kinbo[] = new int[1000];

  static void push(int chonda)
  {
    // Increment top and push element chonda into kinbo array
    kinbo[++top] = chonda;
  }

  static int pop()
  {
    // Decrement top and return the top element
    top--;
    return kinbo[top + 1];
  }
}

