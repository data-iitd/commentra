import java.util.*;

public class Main {
    // Global variables for stack management
    static int top;
    static int[] kinbo = new int[1000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        top = 0; // Initialize the stack top index
        String nullInput; // Buffer to hold input strings

        // Read input until EOF
        while (scanner.hasNext()) {
            nullInput = scanner.next();

            // If the input is a '+' operator, perform addition
            if (nullInput.equals("+")) {
                int chonda = pop(); // Pop the top two values from the stack
                int yamagami = pop();
                push(chonda + yamagami); // Push the result of addition back onto the stack
            }
            // If the input is a '-' operator, perform subtraction
            else if (nullInput.equals("-")) {
                int yamagami = pop(); // Pop the top two values from the stack
                int chonda = pop();
                push(chonda - yamagami); // Push the result of subtraction back onto the stack
            }
            // If the input is a '*' operator, perform multiplication
            else if (nullInput.equals("*")) {
                int chonda = pop(); // Pop the top two values from the stack
                int yamagami = pop();
                push(chonda * yamagami); // Push the result of multiplication back onto the stack
            }
            // If the input is a number, convert it to an integer and push onto the stack
            else {
                push(Integer.parseInt(nullInput));
            }
        }

        // Pop and print the final result from the stack
        System.out.println(pop());
    }

    // Function to push an integer onto the stack
    static void push(int chonda) {
        kinbo[++top] = chonda; // Increment the top index and store the value
    }

    // Function to pop an integer from the stack
    static int pop() {
        return kinbo[top--]; // Decrement the top index and return the value
    }
}
