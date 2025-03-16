
import java.io.*;
import java.util.*;

public class s977214798{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] a = new int[n][n - 1];
        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            for (int j = 0; j < n - 1; j++) {
                a[i][j] = Integer.parseInt(s[j]) - 1;
            }
        }
        int[] e1 = new int[n * (n - 1) / 2];
        int[] e2 = new int[n * (n - 1) / 2];
        int[] d = new int[n * (n - 1) / 2];
        boolean[] b = new boolean[n * (n - 1) / 2];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                int from = p(i, a[i][j]);
                int to = p(i, a[i][j + 1]);
                if (e1[from] == 0) {
                    e1[from] = to;
                } else if (e2[from] == 0) {
                    e2[from] = to;
                } else {
                    System.out.println(-1);
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]);
            int now = f(from, e1, e2, d, b);
            if (now < 0) {
                ans = -1;
                break;
            }
            if (now > ans) ans = now;
        }
        System.out.println(ans);
    }

    public static int p(int a, int b) {
        if (a < b) {
            return a + b * n;
        } else {
            return b + a * n;
        }
    }

    public static int f(int from, int[] e1, int[] e2, int[] d, boolean[] b) {
        if (b[from]) return -1;
        if (d[from]!= 0) return d[from];
        b[from] = true;
        int to = e1[from];
        int max = 0;
        if (to!= 0) {
            int now = f(to, e1, e2, d, b);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        to = e2[from];
        if (to!= 0) {
            int now = f(to, e1, e2, d, b);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        b[from] = false;
        return d[from] = max + 1;
    }
}

// Translate the above Java code to Python and end with comment "