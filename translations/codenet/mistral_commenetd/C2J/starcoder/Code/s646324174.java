import java.util.*;

public class Stack {
    public static void main(String[] args) {
        // Initialize variables
        int a, b;
        String s;

        // Initialize stack top to 0
        int top = 0;

        // Read input until end of file
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            s = in.next();

            // Check if the input is an operator or a number
            if (s.charAt(0) == '+' || s.charAt(0) == '-' || s.charAt(0) == '*') {
                // Pop the top two elements from the stack
                b = S.pop();
                a = S.pop();

                // Perform the operation and push the result back onto the stack
                if (s.charAt(0) == '+') {
                    S.push(a + b);
                } else if (s.charAt(0) == '-') {
                    S.push(a - b);
                } else { // s.charAt(0) == '*'
                    S.push(a * b);
                }
            } else { // Input is a number
                // Push the number directly onto the stack
                S.push(Integer.parseInt(s));
            }
        }

        // Print the final result
        System.out.println(S.pop());
    }
}
