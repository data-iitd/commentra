import java.util.*;

public class Main {
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
        solve(N, M, Q, a, b, c, d);
    }

    public static void solve(int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        int res = 0;

        // Define the recursive function to generate sequences
        List<Integer> rec = new ArrayList<>();
        void rec(List<Integer> A) {
            if (A.size() == N) {
                int ans = 0;
                for (int i = 0; i < Q; i++) {
                    if (A.get(b[i] - 1) - A.get(a[i] - 1) == c[i]) {
                        ans += d[i];
                    }
                }
                res = Math.max(res, ans);
                return;
            }
            int last_max = A.isEmpty() ? 1 : A.get(A.size() - 1);
            for (int i = last_max; i <= M; i++) {
                A.add(i);
                rec(A);
                A.remove(A.size() - 1);
            }
        }

        rec(rec);
        System.out.println(res);
    }
}
