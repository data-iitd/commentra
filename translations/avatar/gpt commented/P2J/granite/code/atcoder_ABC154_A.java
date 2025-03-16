
import java.util.*;

class atcoder_ABC154_A {
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
        if (S.equals(U)) {
            A--;
        }
        if (T.equals(U)) {
            B--;
        }
        System.out.println(A + " " + B);
    }
}

