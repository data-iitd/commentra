
import java.util.*;

public class Main
{
  // Function declarations for stack operations
  static void push(int chonda)
  {
    kinbo[++top] = chonda;
  }

  static int pop()
  {
    top--;
    return kinbo[top + 1];
  }

  // Global variables for stack and top index
  static int top, kinbo[] = new int[1000];

  public static void main(String[] args)
  {
    // Variables to store input values
    int chonda, yamagami;

    // Initialize the top index of the stack
    top = 0;

    // Read input until end of file
    Scanner in = new Scanner(System.in);
    while(in.hasNext())
    {
      // Check the operation based on the first character of the input
      if(in.next().charAt(0) == '+')
      {
        // Pop two values, add them, and push the result
        chonda = pop();
        yamagami = pop();
        push(chonda + yamagami);
      }
      else if(in.next().charAt(0) == '-')
      {
        // Pop two values, subtract the second from the first, and push the result
        yamagami = pop();
        chonda = pop();
        push(chonda - yamagami);
      }
      else if(in.next().charAt(0) == '*')
      {
        // Pop two values, multiply them, and push the result
        chonda = pop();
        yamagami = pop();
        push(chonda * yamagami);
      }
      else
      {
        // Convert input to integer and push it onto the stack
        push(Integer.parseInt(in.next()));
      }
    }

    // Print the final result from the stack
    System.out.println(pop());
  }
}

