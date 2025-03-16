
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = in.nextInt();
            }
        }
        ArrayList<ArrayList<Integer>> l = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> rem = new ArrayList<Integer>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                l.add(new ArrayList<Integer>(Arrays.asList(i, j)));
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;
                for (int k : l.get(j)) {
                    ca += c[k][i];
                }
                if (ca < x) {
                    rem.add(j);
                }
            }
            for (int j = rem.size() - 1; j >= 0; j--) {
                l.remove(rem.get(j).intValue());
            }
            rem.clear();
            if (l.size() == 0) {
                System.out.println(-1);
                break;
            }
        }
        if (l.size() > 0) {
            for (int j : l) {
                int ca = 0;
                for (int k : j) {
                    ca += c[k][0];
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = Math.min(ans, ca);
                }
            }
            System.out.println(ans);
        }
    }
}

