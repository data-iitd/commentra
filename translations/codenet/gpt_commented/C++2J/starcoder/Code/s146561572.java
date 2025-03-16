
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }

    void solve() {
        int n = sc.nextInt();
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i * (n - i + 1);
        }
        for (int i = 1; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int a = Math.max(u, v);
            int b = Math.min(u, v);
            ans -= b * (n - a + 1);
        }
        System.out.println(ans);
    }
}

