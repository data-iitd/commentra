import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        String T = scanner.next();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        String U = scanner.next();
        solve(S, T, A, B, U);
    }

    public static void solve(String S, String T, int A, int B, String U) {
        // Check if the first string S matches the string U
        if (S.equals(U)) {
            A--; // Decrement A if S matches U
        }
        // Check if the second string T matches the string U
        if (T.equals(U)) {
            B--; // Decrement B if T matches U
        }
        // Print the final values of A and B
        System.out.println(A + " " + B);
    }
}

