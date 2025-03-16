
import java.util.*;
import java.io.*;
class atcoder_ABC152_E {
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
    static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        while (b > 0) {
            long t = a / b;
            a -= t * b;
            long x = a;
            a = b;
            b = x;
            x = u;
            u = v;
            v = x - t * v;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }
        long lcm = 1;
        for (int i = 0; i < N; i++) {
            lcm = lcm(lcm, A[i]);
        }
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += lcm * modinv(A[i], 100000007) % 100000007;
        }
        System.out.println(ans % 100000007);
    }
}
