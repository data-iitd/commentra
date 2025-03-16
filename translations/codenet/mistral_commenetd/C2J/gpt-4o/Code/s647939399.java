import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        char m; // Declare character variable m
        int a, b; // Declare integer variables a, b
        int[] c = new int[256]; // Declare integer array c of size 256
        int i = 0; // Initialize index variable i

        // Initialize array c with zeros
        for (int index = 0; index < 256; index++) {
            c[index] = 0;
        }

        Scanner scanner = new Scanner(System.in);

        // Read input values of a, m, and b from the user
        while (true) {
            a = scanner.nextInt();
            m = scanner.next().charAt(0);
            b = scanner.nextInt();

            // Check if the user has entered '?' to terminate the loop
            if (m == '?') {
                break;
            }

            // Perform arithmetic operations based on the operator m
            if (m == '+') {
                c[i] = a + b; // Store the result of addition in the array c
            } else if (m == '-') {
                c[i] = a - b; // Store the result of subtraction in the array c
            } else if (m == '*') {
                c[i] = a * b; // Store the result of multiplication in the array c
            } else if (m == '/') {
                c[i] = a / b; // Store the result of division in the array c
            }
            i++; // Increment index after storing the result
        }

        // Print the results of the arithmetic operations
        for (int j = 0; j < i; j++) {
            System.out.println(c[j]);
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
