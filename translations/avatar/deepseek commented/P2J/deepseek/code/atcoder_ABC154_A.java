import java.util.*;

public class Main {
    public static void solve(String S, String T, int A, int B, String U) {
        // Check if the string S is equal to the string U
        if (S.equals(U)) {
            // Decrement the count of A by 1
            A -= 1;
        }
        // Check if the string T is equal to the string U
        else if (T.equals(U)) {
            // Decrement the count of B by 1
            B -= 1;
        }
        // Print the updated counts of A and B
        System.out.println(A + " " + B);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the string S
        String S = scanner.next();
        // Read the string T
        String T = scanner.next();
        // Read the integer A
        int A = scanner.nextInt();
        // Read the integer B
        int B = scanner.nextInt();
        // Read the string U
        String U = scanner.next();
        // Call the solve function with the read inputs
        solve(S, T, A, B, U);
    }
}
