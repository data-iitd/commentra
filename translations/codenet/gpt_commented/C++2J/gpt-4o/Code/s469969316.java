import java.util.Scanner;

public class Main {
    // Global variables for input and state management
    static String input, ss;
    static int[] a = new int[3];
    static int it, cnt;

    // Function to compute the NOT operation
    static int Not(int x) {
        return 2 - x; // Returns the negation of the input value
    }

    // Function to compute the AND operation
    static int And(int x, int y) {
        if (x * y == 0) return 0; // If either input is 0, return 0
        if (x == 2 && y == 2) return 2; // If both inputs are 2, return 2
        return 1; // Otherwise, return 1
    }

    // Function to compute the OR operation
    static int Or(int x, int y) {
        if (x == 2 || y == 2) return 2; // If either input is 2, return 2
        if (x == 1 || y == 1) return 1; // If either input is 1, return 1
        return 0; // Otherwise, return 0
    }

    // Recursive function to parse the expression and evaluate it
    static int parse() {
        char c = ss.charAt(it++); // Get the current character from the string
        if ('0' <= c && c <= '2') return c - '0'; // Return the numeric value if it's a digit
        if (c == '-') return Not(parse()); // Handle NOT operation

        // Parse left operand
        int x = parse();
        c = ss.charAt(it++); // Get the operator
        // Parse right operand
        int y = parse();
        it++; // Move past the closing parenthesis
        // Return the result of the operation based on the operator
        return c == '*' ? And(x, y) : Or(x, y);
    }

    // Main function to read input and evaluate expressions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Loop until the input is a single dot (.)
        while (true) {
            input = scanner.nextLine();
            if (input.equals(".")) break;

            // Initialize the truth values for P, Q, R
            for (int i = 0; i < 3; i++) a[i] = i;
            cnt = 0; // Initialize the count of valid evaluations

            // Iterate through all combinations of truth values for P, Q, R
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        a[0] = i; a[1] = j; a[2] = k; // Assign truth values to P, Q, R
                        ss = input; // Copy the input expression for processing

                        // Replace variables P, Q, R in the expression with their truth values
                        for (int l = 0; l < ss.length(); l++) {
                            char c = ss.charAt(l);
                            if (c == 'P') ss = ss.substring(0, l) + (a[0] + '0') + ss.substring(l + 1);
                            if (c == 'Q') ss = ss.substring(0, l) + (a[1] + '0') + ss.substring(l + 1);
                            if (c == 'R') ss = ss.substring(0, l) + (a[2] + '0') + ss.substring(l + 1);
                        }

                        it = 0; // Reset the index for parsing
                        // Evaluate the expression and count if it evaluates to true (2)
                        if (parse() == 2) cnt++;
                    }
                }
            }
            // Output the count of valid evaluations
            System.out.println(cnt);
        }
        scanner.close();
    }
}

// <END-OF-CODE>
