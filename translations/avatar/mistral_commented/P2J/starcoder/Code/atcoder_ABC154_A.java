// Import the sys module for reading input from standard input.
import java.util.Scanner;

// Define a class named 'Solution' that doesn't extend anything.
class Solution {

    // Define a function named'solve' that takes five arguments: S, T, A, B, and U.
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

    // Define a function named'main' that doesn't take any arguments.
    public static void main(String[] args) {

        // Create a new instance of the 'Scanner' class.
        Scanner input = new Scanner(System.in);

        // Read the next token from the standard input as a string and assign it to variables S, T, A, B, and U.
        String S = input.next();
        String T = input.next();
        int A = input.nextInt();
        int B = input.nextInt();
        String U = input.next();

        // Call the'solve' function with the assigned variables.
        solve(S, T, A, B, U);
    }
}

