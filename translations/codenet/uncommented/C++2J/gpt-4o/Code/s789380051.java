import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007;

    static long modPow(long x, long n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }

    static long combS(long n, long r) {
        long tmpN = 1;
        long tmpD = 1;
        long ans = 0;
        for (int i = 1; i <= r; i++) {
            tmpN = (tmpN * (n + 1 - i)) % MOD;
            tmpD = (tmpD * i) % MOD;
            ans = tmpN * modPow(tmpD, MOD - 2) % MOD;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long ans = 1;

        ans = modPow(2, n);
        ans--;
        long tmpNd;

        tmpNd = combS(n, a);
        ans = (ans - tmpNd) % MOD;
        if (ans < 0) {
            ans += MOD;
        }

        tmpNd = combS(n, b);
        ans = (ans - tmpNd) % MOD;
        if (ans < 0) {
            ans += MOD;
        }

        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
