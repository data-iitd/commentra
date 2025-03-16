
import java.util.*;

class atcoder_ABC165_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int Q = scanner.nextInt();
        int[] a = new int[Q];
        int[] b = new int[Q];
        int[] c = new int[Q];
        int[] d = new int[Q];
        for (int i = 0; i < Q; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
            d[i] = scanner.nextInt();
        }
        int res = 0;
        int[] A = new int[N];
        rec(A, 0, N, M, Q, a, b, c, d, 0);
        System.out.println(res);
    }

    public static void rec(int[] A, int i, int N, int M, int Q, int[] a, int[] b, int[] c, int[] d, int ans) {
        if (i == N) {
            int cur = 0;
            for (int j = 0; j < Q; j++) {
                if (A[b[j] - 1] - A[a[j] - 1] == c[j]) {
                    cur += d[j];
                }
            }
            res = Math.max(res, cur);
            return;
        }
        int last_max = i == 0? 1 : A[i - 1];
        for (int j = last_max; j <= M; j++) {
            A[i] = j;
            rec(A, i + 1, N, M, Q, a, b, c, d, ans);
        }
    }
}

Translate the above Java code to C++ and end with comment "