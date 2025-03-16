public class SubsetSum {
    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    static int n, A[] = new int[LEN];
    static int flag;

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int q, M;
        int i, j, k;

        n = scanner.nextInt();
        for (i = 0; i < n; i++) A[i] = scanner.nextInt();

        q = scanner.nextInt();
        for (i = 0; i < q; i++) {
            M = scanner.nextInt();
            flag = FALSE;
            solve(-1, M);
            if (flag == TRUE) System.out.println("yes");
            else System.out.println("no");
        }
    }

    static int solve(int i, int m) {
        if (i > n) return FALSE;
        else if (m < 0) return FALSE;
        else if (m == 0 || m - A[i + 1] == 0) {
            flag = TRUE;
            return TRUE;
        } else {
            solve(i + 1, m);
            solve(i + 1, m - A[i]);
        }
    }
}
