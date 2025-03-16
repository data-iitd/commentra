import java.util.Scanner;

public class SubsequenceCheck {
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    static int n, A[] = new int[LEN];
    static int flag;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q, M;
        int i, j, k;

        n = scanner.nextInt();
        for (i = 0; i < n; i++) A[i] = scanner.nextInt();

        q = scanner.nextInt();
        for (i = 0; i < q; i++) {
            M = scanner.nextInt();
            flag = FALSE;

            if (solve(0, M)) System.out.println("yes");
            else System.out.println("no");
        }

        scanner.close();
    }

    static boolean solve(int i, int m) {
        if (i > n) return false;
        else if (m < 0) return false;
        else if (m == 0 || m - A[i] == 0) {
            flag = TRUE;
            return true;
        } else {
            boolean notUsing = solve(i + 1, m);
            boolean using = solve(i + 1, m - A[i]);
            return notUsing || using;
        }
    }
}
