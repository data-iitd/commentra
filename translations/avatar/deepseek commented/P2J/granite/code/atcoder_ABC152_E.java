
import java.util.*;

class atcoder_ABC152_E {
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

        long ans = lcm;
        for (int i = 0; i < N; i++) {
            ans = ans * modinv(A[i], 100000007) % 100000007;
        }

        System.out.println(ans);
    }

    // Function to calculate the least common multiple (LCM) of two numbers
    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    // Function to calculate the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    // Function to calculate the modular inverse of a number
    static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        long tmp;
        while (b > 0) {
            long t = a / b;
            a -= t * b;
            tmp = a; a = b; b = tmp;
            u -= t * v;
            tmp = u; u = v; v = tmp;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }
}

Translate the above Java code to C++ and end with comment "