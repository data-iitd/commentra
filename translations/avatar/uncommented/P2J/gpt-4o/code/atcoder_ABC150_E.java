import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int mod = 1000000007;
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextLong();
        }
        
        Arrays.sort(c);
        long b = pow(2, 2 * n - 2, mod);
        long a = (2 * b) % mod;
        long ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = (ans + c[n - 1 - i] * (a + i * b)) % mod;
        }
        
        System.out.println(ans);
        scanner.close();
    }

    private static long pow(long base, long exp, long mod) {
        long result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }
}
// <END-OF-CODE>
