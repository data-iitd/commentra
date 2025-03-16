
// Import the java.util.Scanner class for reading input from standard input.
import java.util.Scanner;

// Define a class named 'Solution' that contains the 'main' function.
class Solution {

    // Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
    public static void solve(String S, String T, int A, int B, String U) {

        // Check if S is equal to U. If yes, decrement A.
        if (S.equals(U)) {
            A--;
        }

        // Check if T is equal to U. If yes, decrement B.
        if (T.equals(U)) {
            B--;
        }

        // Print the updated values of A and B.
        System.out.println(A + " " + B);

        // Return from the function.
        return;
    }

    // Define a function named 'main' that doesn't take any arguments.
    public static void main(String[] args) {

        // Define a Scanner object for reading input from standard input.
        Scanner scanner = new Scanner(System.in);

        // Assign the next token to variables S, T, A, B, and U.
        String S = scanner.next();
        String T = scanner.next();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        String U = scanner.next();

        // Call the 'solve' function with the assigned variables.
        solve(S, T, A, B, U);

        // Close the scanner object.
        scanner.close();
    }
}

// End of code.
