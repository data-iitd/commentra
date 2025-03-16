// ProblemB.java

import java.util.*;
import java.io.*;

public class ProblemB {
    private static final int constMod = (int) (1e9) + 7;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter wr = new PrintWriter(System.out);

    // -----------------------------------------

    private static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    // -----------------------------------------

    // Num Functions

    private static int numAbs(int x) {
        return x < 0 ? -x : x;
    }

    private static int numModPow(int a, int n, int m) {
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (int) ((1L * result * a) % m);
            }
            a = (int) ((1L * a * a) % m);
            n >>= 1;
        }
        return result;
    }

    private static int numGcd(int a, int b) {
        return b == 0 ? a : numGcd(b, a % b);
    }

    private static int numLcm(int a, int b) {
        return a * b / numGcd(a, b);
    }

    private static int numModInv(int a, int p) {
        if (a == 1) {
            return 1;
        }
        return (p - numModInv(p % a, p) * (p / a) % p + p) % p;
    }

    private static int[] numModFrac(int n) {
        int[] frac = new int[n + 1];
        frac[0] = 1;
        for (int i = 1; i <= n; i++) {
            frac[i] = (int) ((1L * i * frac[i - 1]) % constMod);
        }
        return frac;
    }

    private static int numModConb(int n, int r) {
        int[] frac = numModFrac(n);
        return (int) ((1L * frac[n] * numModInv((1L * frac[n - r] * frac[r]) % constMod, constMod)) % constMod);
    }

    // -----------------------------------------

    private static void solve() throws IOException {
        int n = getInt();
        int m = getInt();
        int[] a = getIntArray(n);

        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        for (int v : a) {
            double rate = (double) sum / (4 * m);
            if ((double) v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }
    }

    // -----------------------------------------

    public static void main(String[] args) throws IOException {
        solve();
        wr.flush();
    }
}

// <END-OF-CODE>
