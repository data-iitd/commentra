import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000 + 7;
    static final int INF_INT64 = Long.MAX_VALUE;
    static final int INF_INT32 = Integer.MAX_VALUE;

    static char[] S;
    static int x, y;
    static boolean[][] dpx = new boolean[8000][20000];
    static boolean[][] dpy = new boolean[8000][20000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        S = br.readLine().toCharArray();
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        List<Integer> F = new ArrayList<>();
        int cur = 0;

        for (char c : S) {
            if (c == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur);

        List<Integer> evens = new ArrayList<>();
        List<Integer> odds = new ArrayList<>();
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        dpx[0][10000] = true;
        dpy[0][10000] = true;

        for (int i = 0; i < evens.size(); i++) {
            int val = evens.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
                }
                if (j - val >= 2000 && i != 0) {
                    dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
                }
            }
        }

        for (int i = 0; i < odds.size(); i++) {
            int val = odds.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
                }
                if (j - val >= 2000) {
                    dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
                }
            }
        }

        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

/* <END-OF-CODE> */
