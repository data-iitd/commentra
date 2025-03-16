// Global variables for input and state management
String input, ss;
int a[] = new int[3];
int it, cnt;

// Function to compute the NOT operation
int Not(int x) {
    return 2 - x; // Returns the negation of the input value
}

// Function to compute the AND operation
int And(int x, int y) {
    if (x * y == 0) return 0; // If either input is 0, return 0
    if (x == 2 && y == 2) return 2; // If both inputs are 2, return 2
    return 1; // Otherwise, return 1
}

// Function to compute the OR operation
int Or(int x, int y) {
    if (x == 2 || y == 2) return 2; // If either input is 2, return 2
    if (x == 1 || y == 1) return 1; // If either input is 1, return 1
    return 0; // Otherwise, return 0
}

// Recursive function to parse the expression and evaluate it
int parse() {
    char c = ss.charAt(it++); // Get the current character from the string
    if ('0' <= c && c <= '2') return c - '0'; // Return the numeric value if it's a digit
    if (c == '-') return Not(parse()); // Handle NOT operation

    // Parse left operand
    int x = parse();
    c = ss.charAt(it++); // Get the operator
    // Parse right operand
    int y = parse();
    ++it; // Move past the closing parenthesis
    // Return the result of the operation based on the operator
    return c == '*' ? And(x, y) : Or(x, y);
}

// Main function to read input and evaluate expressions
public static void main(String[] args) {
    // Loop until the input is a single dot (.)
    while (true) {
        // Read input and break if it's a single dot (.)
        input = scanner.nextLine();
        if (input.equals(".")) break;

        // Initialize the truth values for P, Q, R
        for (int i = 0; i < 3; i++) a[i] = i;
        cnt = 0; // Initialize the count of valid evaluations

        // Iterate through all combinations of truth values for P, Q, R
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++) {
                    a[0] = i; a[1] = j; a[2] = k; // Assign truth values to P, Q, R
                    ss = input; // Copy the input expression for processing

                    // Replace variables P, Q, R in the expression with their truth values
                    for (int i = 0; i < ss.length(); i++) {
                        if (ss.charAt(i) == 'P') ss = ss.substring(0, i) + a[0] + ss.substring(i + 1); // Replace P with its truth value
                        if (ss.charAt(i) == 'Q') ss = ss.substring(0, i) + a[1] + ss.substring(i + 1); // Replace Q with its truth value
                        if (ss.charAt(i) == 'R') ss = ss.substring(0, i) + a[2] + ss.substring(i + 1); // Replace R with its truth value
                    }

                    it = 0; // Reset the index for parsing
                    // Evaluate the expression and count if it evaluates to true (2)
                    if (parse() == 2) cnt++;
                }
        // Output the count of valid evaluations
        System.out.println(cnt);
    }
}

