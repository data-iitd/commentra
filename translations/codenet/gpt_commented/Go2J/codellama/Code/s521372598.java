
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter(System.out);

        solve();
        wr.flush();
    }

    public static void solve() {
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }

        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1;
        }
        Arrays.sort(xs);

        int b = xs[n / 2];
        int ans = 0;
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        System.out.println(ans);
    }

    public static int abs(int n) {
        if (n < 0) {
            return -n;
        }
        return n;
    }

    public static int[] getIntSlice(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = sc.nextInt();
        }
        return ret;
    }

    public static int getInt() {
        return sc.nextInt();
    }

    public static String getString() {
        return sc.next();
    }

    public static char[] getRunes() {
        return getString().toCharArray();
    }

    public static Scanner sc = new Scanner(System.in);
}

