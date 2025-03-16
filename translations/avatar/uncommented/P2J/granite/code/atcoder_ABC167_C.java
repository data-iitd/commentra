
import java.util.*;
import java.io.*;

class atcoder_ABC167_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int x = Integer.parseInt(s[2]);
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            s = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                c[i][j] = Integer.parseInt(s[j]);
            }
        }
        List<Integer> pre = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pre.add(i);
        }
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (List<Integer> j : getCombinations(pre, i)) {
                l.add(j);
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;
                for (int ii : l.get(j)) {
                    ca += c[ii][i - 1];
                }
                if (ca < x) {
                    rem.add(j);
                } else {
                    // do nothing
                }
            }
            if (rem.size() > 0) {
                for (int j = rem.size() - 1; j >= 0; j--) {
                    l.remove(rem.get(j));
                }
                rem.clear();
            }
            if (l.size() == 0) {
                System.out.println(-1);
                break;
            }
        }
        if (l.size() > 0) {
            int min = Integer.MAX_VALUE;
            for (List<Integer> i : l) {
                int ca = 0;
                for (int j : i) {
                    ca += c[j][0];
                }
                if (ca < min) {
                    min = ca;
                }
            }
            System.out.println(min);
        }
        // 