import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1; // Number of test cases
        while (t-- > 0) {
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        long ans = 0;
        int n = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            ans += i * (n - i + 1);
        }

        for (int i = 1; i < n; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int a = Math.max(u, v);
            int b = Math.min(u, v);
            ans -= b * (n - a + 1);
        }

        System.out.println(ans);
    }
}
