import java.io.*;
import java.util.*;

public class Main {
    static final int MAGIC = 1000000007;
    static int N;
    static int[] p = new int[200000];

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        StringTokenizer st = new StringTokenizer(reader.readLine());
        int X = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i <= 100; i++) {
            if (find(X - i) == 1) {
                writer.println(X - i);
                writer.close();
                return;
            }
            if (find(X + i) == 1) {
                writer.println(X + i);
                writer.close();
                return;
            }
        }

        writer.close();
    }

    static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0;
            }
        }
        return 1;
    }

    // Additional utility methods can be added here as needed
    // For example, combination, gcd, etc.

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

    static int gcd(int a, int b) {
        while (a != 0) {
            int temp = b;
            b = a;
            a = temp % a;
        }
        return b;
    }

    static int power2mod(int n, int mod) {
        int res = 1, x = 2;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }

    static int power2(int n) {
        return power2mod(n, MAGIC);
    }
}

// <END-OF-CODE>
