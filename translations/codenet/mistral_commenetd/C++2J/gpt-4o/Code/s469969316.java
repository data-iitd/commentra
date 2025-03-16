import java.util.Scanner;

public class LogicalExpressionEvaluator {
    static String input, ss; // Input string and string for parsing
    static int[] a = new int[3]; // Array for values of P, Q, R
    static int it, cnt; // Index and counter

    static int Not(int x) { // Function to calculate NOT of a binary number
        return 2 - x;
    }

    static int And(int x, int y) { // Function to calculate AND of two binary numbers
        if (x * y == 0) return 0; // If product of x and y is zero, return zero
        if (x == 2 && y == 2) return 2; // If both x and y are 2, return 2
        return 1; // Otherwise, return 1
    }

    static int Or(int x, int y) { // Function to calculate OR of two binary numbers
        if (x == 2 || y == 2) return 2; // If either x or y is 2, return 2
        if (x == 1 || y == 1) return 1; // If either x or y is 1, return 1
        return 0; // Otherwise, return 0
    }

    static int parse() { // Function to parse the input string and calculate the logical expression
        char c = ss.charAt(it++); // Read the next character from the input string
        if ('0' <= c && c <= '2') return c - '0'; // If character is a binary digit, convert it to an integer and return
        if (c == '-') return Not(parse()); // If character is NOT, recursively call parse() and apply NOT

        int x = parse(); // Parse the first binary number
        c = ss.charAt(it++); // Read the next character from the input string
        int y = parse(); // Parse the second binary number
        it++; // Increment the index of the input string
        return c == '*' ? And(x, y) : Or(x, y); // If character is AND, call And() function. Otherwise, call Or() function
    }

    public static void main(String[] args) { // Main function
        Scanner scanner = new Scanner(System.in);
        while (true) { // Read input until end of file is reached
            input = scanner.nextLine();
            if (input.equals(".")) break; // Break if input is "."
            for (int i = 0; i < 3; i++) a[i] = i; // Initialize the array a with values 0, 1, 2
            cnt = 0; // Initialize counter for counting the number of valid expressions
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) { // Nested loop to generate all possible combinations of a, b, c
                        a[0] = i; a[1] = j; a[2] = k;
                        ss = input; // Set the input string for the current combination
                        StringBuilder sb = new StringBuilder(ss);
                        for (int index = 0; index < sb.length(); index++) { // Replace P, Q, R with the values of a, b, c respectively
                            char c = sb.charAt(index);
                            if (c == 'P') sb.setCharAt(index, (char) (a[0] + '0'));
                            if (c == 'Q') sb.setCharAt(index, (char) (a[1] + '0'));
                            if (c == 'R') sb.setCharAt(index, (char) (a[2] + '0'));
                        }
                        ss = sb.toString(); // Convert StringBuilder back to String
                        it = 0; // Reset the index of the input string
                        if (parse() == 2) cnt++; // If the logical expression is valid, increment the counter
                    }
                }
            }
            System.out.println(cnt); // Print the number of valid expressions for the current input
        }
        scanner.close();
    }
}

// <END-OF-CODE>
