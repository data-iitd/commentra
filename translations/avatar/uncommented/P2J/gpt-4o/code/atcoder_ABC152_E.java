import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long MOD = 1000000007;
        int N = scanner.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        long lcm = 1;
        for (long a : A) {
            lcm = lcm * a / gcd(lcm, a);
        }
        
        long sum = 0;
        for (long s : A) {
            sum = (sum + modInverse(s, MOD)) % MOD;
        }
        
        long ans = (lcm * sum) % MOD;
        System.out.println(ans);
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private static long modInverse(long a, long mod) {
        return pow(a, mod - 2, mod);
    }

    private static long pow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
// <END-OF-CODE>
