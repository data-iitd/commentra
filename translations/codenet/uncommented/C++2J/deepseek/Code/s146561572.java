import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1; // Assuming there's only one test case as per the given code
        while (t-- > 0) {
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        long ans = 0;
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
}
