import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                l.add(new ArrayList<>());
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n - j; k++) {
                    l.get(k).add(j);
                }
            }
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;
                for (int ii : l.get(j)) {
                    ca += c[ii][i];
                }
                if (ca < x) {
                    rem.add(j);
                }
            }
            if (rem.size() > 0) {
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();
            }
            if (l.size() == 0) {
                System.out.println(-1);
                return;
            }
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;
                for (int ii : l.get(j)) {
                    ca += c[ii][0];
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = Math.min(ans, ca);
                }
            }
        }
        System.out.println(ans);
    }
}

