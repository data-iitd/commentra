import java.util.*;
import java.io.*;

public class ProblemB {
    static final int constMod = (int) (1e9 + 7);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) throws IOException {
        new ProblemB().solve();
        pw.flush();
    }

    int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    int[] getIntArray() throws IOException {
        String[] tokens = br.readLine().split(" ");
        int[] arr = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            arr[i] = Integer.parseInt(tokens[i]);
        }
        return arr;
    }

    String getString() throws IOException {
        return br.readLine();
    }

    String[] getStringArray() throws IOException {
        return br.readLine().split(" ");
    }

    String[][] getStringDoubleArray(int m, int n) throws IOException {
        String[][] arr = new String[m][n];
        for (int i = 0; i < m; i++) {
            arr[i] = getStringArray();
        }
        return arr;
    }

    int[] sortIntArray(int[] arr) {
        Arrays.sort(arr);
        return arr;
    }

    int[] sortIntReverseArray(int[] arr) {
        Arrays.sort(arr);
        Collections.reverse(Arrays.asList(arr));
        return arr;
    }

    int numAbs(int x) {
        return Math.abs(x);
    }

    int numModPow(int a, int n, int m) {
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            n >>= 1;
        }
        return result;
    }

    int numGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return numGcd(b, a % b);
    }

    int numLcm(int a, int b) {
        return a * b / numGcd(a, b);
    }

    int numModInv(int a, int p) {
        if (a == 1) {
            return 1;
        }
        return p - numModInv(p % a, p) * (p / a) % p;
    }

    List<Integer> numModFrac(int n) {
        List<Integer> frac = new ArrayList<>();
        frac.add(1);
        for (int i = 1; i <= n; i++) {
            frac.add(i * frac.get(i - 1) % constMod);
        }
        return frac;
    }

    int numModConb(int n, int r) {
        List<Integer> frac = numModFrac(n);
        return (frac.get(n) / ((frac.get(n - r) * frac.get(r)) % constMod)) % constMod;
    }

    void solve() throws IOException {
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int[] a = getIntArray();

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
            pw.println("Yes");
        } else {
            pw.println("No");
        }
    }
}
