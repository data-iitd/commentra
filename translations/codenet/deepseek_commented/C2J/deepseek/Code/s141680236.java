import java.util.*;

public class Main {
    // Global variables for stack and top index
    static int top;
    static int[] kinbo = new int[1000];

    public static void main(String[] args) {
        // Variables to store input values
        int chonda, yamagami;

        // Initialize the top index of the stack
        top = 0;

        // Read input until end of file
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String nullInput = scanner.next();

            // Check the operation based on the first character of the input
            if (nullInput.equals("+")) {
                // Pop two values, add them, and push the result
                chonda = pop();
                yamagami = pop();
                push(chonda + yamagami);
            } else if (nullInput.equals("-")) {
                // Pop two values, subtract the second from the first, and push the result
                yamagami = pop();
                chonda = pop();
                push(chonda - yamagami);
            } else if (nullInput.equals("*")) {
                // Pop two values, multiply them, and push the result
                chonda = pop();
                yamagami = pop();
                push(chonda * yamagami);
            } else {
                // Convert input to integer and push it onto the stack
                push(Integer.parseInt(nullInput));
            }
        }

        // Print the final result from the stack
        System.out.println(pop());
    }

    // Function to push a value onto the stack
    static void push(int chonda) {
        kinbo[++top] = chonda;
    }

    // Function to pop a value from the stack
    static int pop() {
        return kinbo[top--];
    }
}
