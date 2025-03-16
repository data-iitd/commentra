import java.util.*;

public class Main {
    public static void solve(String S, String T, int A, int B, String U) {
        if (S.equals(U)) {
            A -= 1;
        } else if (T.equals(U)) {
            B -= 1;
        }
        System.out.println(A + " " + B);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        String T = scanner.next();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        String U = scanner.next();
        solve(S, T, A, B, U);
    }
}
