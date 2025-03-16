import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[][] a = new int[n][m];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        int ans = 1200001;
        for (int bits = 0; bits < 1 << n; bits++) {
            int tot = 0;
            boolean ok = true;
            int[] skill = new int[m];
            for (int i = 0; i < n; i++) {
                if ((bits >> i) & 1 == 1) {
                    tot += p[i];
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j];
                    }
                }
            }
            for (int v : skill) {
                if (v < x) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (ans > tot) {
                    ans = tot;
                }
            }
        }
        if (ans!= 1200001) {
            System.out.println(ans);
        } else {
            System.out.println("-1");
        }
    }
}

