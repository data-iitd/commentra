import java.io.*;
import java.util.*;

public class Main {
    private static final int MOD = 1000000000 + 7;
    private static final int ALPHABET_NUM = 26;
    private static final long INF_INT64 = Long.MAX_VALUE;
    private static final int INF_INT32 = Integer.MAX_VALUE;
    private static final int MAX_ROWS = 8000;
    private static final int MAX_COLS = 20000;
    
    private static boolean[][] dpx = new boolean[MAX_ROWS][MAX_COLS];
    private static boolean[][] dpy = new boolean[MAX_ROWS][MAX_COLS];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        // Initialize dpx and dpy
        for (int i = 0; i < MAX_ROWS; i++) {
            Arrays.fill(dpx[i], false);
            Arrays.fill(dpy[i], false);
        }
        
        // Read the even and odd values from the string S
        List<Integer> evens = new ArrayList<>();
        List<Integer> odds = new ArrayList<>();
        
        for (char c : S.toCharArray()) {
            int value = c - '0';
            if (value % 2 == 0) {
                evens.add(value);
            } else {
                odds.add(value);
            }
        }

        // Update dpx for even indices
        for (int i = 0; i < evens.size(); i++) {
            updateDPX(i, evens.get(i));
        }

        // Update dpy for odd indices
        for (int i = 0; i < odds.size(); i++) {
            updateDPY(i, odds.get(i));
        }

        // Check the conditions
        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static void updateDPX(int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
            }
            if (j - val >= 2000 && index != 0) {
                dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
            }
        }
    }

    private static void updateDPY(int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
            }
            if (j - val >= 2000) {
                dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
            }
        }
    }
}

/* <END-OF-CODE> */
