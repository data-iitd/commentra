import java.util.Scanner;

public class Main {

    // Define a method named 'solve' that takes five arguments: S, T, A, B, and U.
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
    }

    // Define the main method.
    public static void main(String[] args) {
        // Create a Scanner object for reading input.
        Scanner scanner = new Scanner(System.in);

        // Read the input values.
        String S = scanner.next();
        String T = scanner.next();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        String U = scanner.next();

        // Call the 'solve' method with the assigned variables.
        solve(S, T, A, B, U);

        // Close the scanner.
        scanner.close();
    }
}

// <END-OF-CODE>
