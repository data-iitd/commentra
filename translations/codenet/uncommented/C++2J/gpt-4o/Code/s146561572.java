import java.util.*;

public class Main {
    private static final int N = (int) (2e5) + 10;
    private static final int K = (int) (2e6) + 10;
    private static final int MOD = (int) (1e9) + 7;
    private static final int INF = (int) (1e9) + 5;
    private static final long INF64 = (long) 2e18;

    public static void solve() {
        long ans = 0;
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        // Contribution of The Nodes.
        for (int i = 1; i <= n; i++) {
            ans += i * 1L * (n - i + 1);
        }
        for (int i = 1; i < n; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int a = Math.max(u, v);
            int b = Math.min(u, v);
            ans -= b * 1L * (n - a + 1);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1; // You can uncomment the next line to read the number of test cases
        // t = scanner.nextInt();
        while (t-- > 0) {
            solve();
        }
    }
}

// <END-OF-CODE>
