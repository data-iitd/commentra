// Package main defines the entry point of the program.
import java.io.*;
import java.util.*;

public class Main {
    // Constants
    static final int MAGIC = 1000000007;

    // Variables
    static int N;
    static int[] p = new int[200000];

    // find checks if a number exists in the array p.
    static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }

    // solve is the main function that handles the program logic.
    static void solve() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int X = Integer.parseInt(tokenizer.nextToken());
        N = Integer.parseInt(tokenizer.nextToken());
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(tokenizer.nextToken());
        }

        // Search for the closest number to X in the array p.
        for (int i = 0; i <= 100; i++) {
            if (find(X - i) == 1) {
                System.out.println(X - i);
                System.exit(0);
            }
            if (find(X + i) == 1) {
                System.out.println(X + i);
                System.exit(0);
            }
        }
    }

    // main is the entry point of the program.
    public static void main(String[] args) throws IOException {
        solve();
    }

    // Utility functions
    static int intMin(int a, int b) {
        return Math.min(a, b);
    }

    static int intMax(int a, int b) {
        return Math.max(a, b);
    }

    // direct calculation of combination
    // n, m should be "small"
    static int combination(int n, int m) {
        if (m > n) {
            return 0;
        } else if (m == n || m == 0) {
            return 1;
        } else {
            int res = 1;
            for (int i = 0; i < m; i++) {
                res *= (n - i);
            }
            for (int i = 1; i <= m; i++) {
                res /= i;
            }
            return res;
        }
    }

    // calculate combination modulo based on Lucas theorem
    static int lucas(int n, int m, int p) {
        int ntemp = n;
        int mtemp = m;
        int res = 1;
        for (int i = 0; i < 100; i++) {
            int nreminder = ntemp % p;
            ntemp = ntemp / p;
            int mreminder = mtemp % p;
            mtemp = mtemp / p;
            res = res * (combination(nreminder, mreminder) % p);
            if (ntemp == 0) {
                break;
            }
        }
        return res % p;
    }

    static int combMod(int n, int m, int p) {
        return lucas(n, m, p);
    }

    static void findDivisors(int n, List<Integer> a) {
        if (n == 1) {
            return;
        }

        int sqrt = (int) Math.sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (n % i == 0) {
                a.add(i);
                a.add(n / i);
            }
        }
        a.add(n);
    }

    static List<Integer> removeDuplicate(int[] a) {
        Set<Integer> set = new HashSet<>();
        for (int value : a) {
            set.add(value);
        }
        return new ArrayList<>(set);
    }

    static int gcd(int a, int b) {
        while (a != 0) {
            int temp = b % a;
            b = a;
            a = temp;
        }
        return b;
    }

    static int power2mod(int n, int mod) {
        int res = 1, x = 2;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    static int power2(int n) {
        return power2mod(n, MAGIC);
    }
}

// <END-OF-CODE>
