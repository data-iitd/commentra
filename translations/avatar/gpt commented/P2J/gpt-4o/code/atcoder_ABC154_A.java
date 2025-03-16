import java.util.Scanner;

public class Main {
    public static void solve(String S, String T, int A, int B, String U) {
        // Check if the first string S matches the string U
        if (S.equals(U)) {
            A--;  // Decrement A if S matches U
        }
        // Check if the second string T matches the string U
        if (T.equals(U)) {
            B--;  // Decrement B if T matches U
        }
        // Print the final values of A and B
        System.out.println(A + " " + B);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string S from input
        String S = scanner.next();
        // Read the second string T from input
        String T = scanner.next();
        // Read the integer A from input
        int A = scanner.nextInt();
        // Read the integer B from input
        int B = scanner.nextInt();
        // Read the string U from input
        String U = scanner.next();
        
        // Call the solve function with the read values
        solve(S, T, A, B, U);
        
        scanner.close();
    }
}

// <END-OF-CODE>
