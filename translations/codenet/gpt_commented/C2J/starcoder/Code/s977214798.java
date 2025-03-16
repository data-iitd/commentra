import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                a[i][j] = in.nextInt() - 1;
            }
        }
        int[] e1 = new int[n * n];
        int[] e2 = new int[n * n];
        int[] d = new int[n * n];
        boolean[] b = new boolean[n * n];
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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]);
            int now = f(from);
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

    public static int f(int from) {
        if (b[from]) return -1;
        if (d[from]) return d[from];
        b[from] = true;
        int to;
        to = e1[from];
        int max = 0;
        if (to!= 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        to = e2[from];
        if (to!= 0) {
            int now = f(to);
            if (now < 0) return now;
            if (now > max) max = now;
        }
        b[from] = false;
        return d[from] = max + 1;
    }
}

