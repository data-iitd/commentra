
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        int A = sc.nextInt();
        int B = sc.nextInt();
        String U = sc.next();
        solve(S, T, A, B, U);
    }
    public static void solve(String S, String T, int A, int B, String U) {
        // Check if the string S is equal to the string U
        if (S.equals(U)) {
            // Decrement the count of A by 1
            A--;
        }
        // Check if the string T is equal to the string U
        if (T.equals(U)) {
            // Decrement the count of B by 1
            B--;
        }
        // Print the updated counts of A and B
        System.out.println(A + " " + B);
    }
}
