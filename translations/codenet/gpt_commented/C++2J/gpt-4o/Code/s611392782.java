import java.util.Scanner;

public class Miscalculation {

    // Function to perform multiplication based on the custom operator '*' in the string
    private static int mul(String str, int[] idx) {
        // Initialize result with the first digit
        int res = str.charAt(idx[0]) - '0';
        // Loop through the string to find '*' operators and perform multiplication
        while (idx[0] + 1 < str.length() && str.charAt(idx[0] + 1) == '*') {
            idx[0] += 2; // Move index to the next number after '*'
            res *= str.charAt(idx[0]) - '0'; // Multiply the result with the next number
        }
        return res; // Return the final multiplication result
    }

    // Function to perform addition based on the custom operator '+' in the string
    private static int add(String str, int[] idx) {
        // Start with the first multiplication result
        int res = mul(str, idx);
        // Loop through the string to find '+' operators and perform addition
        while (idx[0] + 1 < str.length() && str.charAt(idx[0] + 1) == '+') {
            idx[0] += 2; // Move index to the next number after '+'
            res += mul(str, idx); // Add the next multiplication result to the total
        }
        return res; // Return the final addition result
    }

    // Function to calculate the result based on Bob's interpretation of the expression
    private static int bob(String str, int[] idx) {
        // Initialize result with the first digit
        int res = str.charAt(idx[0]) - '0';
        // Loop through the string to evaluate the expression according to Bob's rules
        while (idx[0] + 1 < str.length()) {
            // Check if the next operator is '+' or '*' and perform the corresponding operation
            if (str.charAt(idx[0] + 1) == '+') 
                res += str.charAt(idx[0] + 2) - '0'; // Add the next number
            else                  
                res *= str.charAt(idx[0] + 2) - '0'; // Multiply by the next number
            idx[0] += 2; // Move index to the next operator
        }
        return res; // Return the final result according to Bob's interpretation
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read input until end of file
        while (scanner.hasNext()) {
            String s = scanner.next(); // String to hold the expression
            int d = scanner.nextInt(); // Variable to hold the expected result
            int[] idx = {0}; // Initialize index for parsing the string
            int a = add(s, idx); // Calculate the result using the addition function
            idx[0] = 0; // Reset index for Bob's calculation
            int b = bob(s, idx); // Calculate the result using Bob's interpretation
            // Compare results and print the corresponding output
            if (a == d) {
                System.out.println(b == d ? "U" : "M"); // Output 'U' if both are equal, else 'M'
            } else {
                System.out.println(b == d ? "L" : "I"); // Output 'L' if Bob's result is equal, else 'I'
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
