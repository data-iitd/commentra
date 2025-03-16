import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        long[] acc = new long[n + 1];
        acc[0] = 0;
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            acc[i + 1] = acc[i] + a[i];
            acc[i + 1] %= 1000000007;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            long temp = a[i] % 1000000007 * (1000000007 + acc[n] - acc[i + 1]) % 1000000007;
            ans += temp;
            ans %= 1000000007;
        }
        System.out.println(ans);
    }
}
