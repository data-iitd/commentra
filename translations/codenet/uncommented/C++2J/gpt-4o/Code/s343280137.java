import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007;
    static final long INF = 1 << 29;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();
        long c = scanner.nextLong();

        long[] x = new long[(int) n + 1];
        long[] v = new long[(int) n + 1];

        for (int i = 1; i <= n; i++) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }

        long[] lefttotal = new long[(int) n + 1];
        long[] maxlefttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
        }

        for (int i = 1; i <= n; i++) {
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        long[] righttotal = new long[(int) n + 1];
        long[] maxrighttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            righttotal[i] = righttotal[i - 1] + v[(int) (n - i + 1)];
        }

        for (int i = 1; i <= n; i++) {
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[(int) (n + 1 - i)]));
        }

        long ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]);
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[(int) (n - i)]);
            ans = Math.max(ans, righttotal[i] - (c - x[(int) (n + 1 - i)]));
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[(int) (n + 1 - i)]) + maxlefttotal[(int) (n - i)]);
        }

        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
