public class BooleanExpressionEvaluator {
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
    static int parse(String ss, int it) {
        char c = ss.charAt(it++); // Get the current character from the string
        if ('0' <= c && c <= '2') return c - '0'; // Return the numeric value if it's a digit
        if (c == '-') return Not(parse(ss, it)); // Handle NOT operation

        // Parse left operand
        int x = parse(ss, it);
        char operatorChar = ss.charAt(it++); // Get the operator
        // Parse right operand
        int y = parse(ss, it);
        ++it; // Move past the closing parenthesis
        // Return the result of the operation based on the operator
        return operatorChar == '*' ? And(x, y) : Or(x, y);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextLine() && !scanner.nextLine().equals(".")) {
            String input = scanner.nextLine();
            int[] a = new int[3];
            int cnt = 0;

            // Iterate through all combinations of truth values for P, Q, R
            for (int i = 0; i < 3; i++) {
                a[0] = i;
                for (int j = 0; j < 3; j++) {
                    a[1] = j;
                    for (int k = 0; k < 3; k++) {
                        a[2] = k;
                        String ss = input;

                        // Replace variables P, Q, R in the expression with their truth values
                        ss = ss.replace('P', (char) ('0' + a[0]));
                        ss = ss.replace('Q', (char) ('0' + a[1]));
                        ss = ss.replace('R', (char) ('0' + a[2]));

                        int it = 0; // Reset the index for parsing
                        // Evaluate the expression and count if it evaluates to true (2)
                        if (parse(ss, it) == 2) cnt++;
                    }
                }
            }
            // Output the count of valid evaluations
            System.out.println(cnt);
        }
        scanner.close();
    }
}
