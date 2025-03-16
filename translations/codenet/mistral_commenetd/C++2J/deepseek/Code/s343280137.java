import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();
        long c = scanner.nextLong();

        long[] x = new long[(int) (n + 1)];
        long[] v = new long[(int) (n + 1)];

        for (int i = 1; i < n + 1; i++) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }

        long[] lefttotal = new long[(int) (n + 1)];
        long[] maxlefttotal = new long[(int) (n + 1)];
        for (int i = 1; i < n + 1; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        long[] righttotal = new long[(int) (n + 1)];
        long[] maxrighttotal = new long[(int) (n + 1)];
        for (int i = 1; i < n + 1; i++) {
            righttotal[i] = righttotal[i - 1] + v[n - i + 1];
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[n + 1 - i]));
        }

        long ans = 0;
        for (int i = 1; i < n + 1; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]);
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]);
            ans = Math.max(ans, righttotal[i] - (c - x[n + 1 - i]));
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]);
        }

        System.out.println(ans);
    }
}
