import java.io.*;
import java.util.*;

public class Main {
    // Constants used in the program.
    private static final int MOD = 1000000000 + 7;
    private static final int ALPHABET_NUM = 26;
    private static final long INF_INT64 = Long.MAX_VALUE;
    private static final long INF_BIT60 = 1L << 60;
    private static final int INF_INT32 = Integer.MAX_VALUE;
    private static final int INF_BIT30 = 1 << 30;
    private static final int NIL = -1;
    private static final int WHITE = 0;
    private static final int GRAY = 1;
    private static final int BLACK = 2;

    private static BufferedReader reader;
    private static PrintWriter writer;

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);

        char[] S = readRuneSlice();
        int[] xy = readInt2();
        int x = xy[0];
        int y = xy[1];

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
        printfDebug("%s\n", F);

        List<Integer> evens = new ArrayList<>();
        List<Integer> odds = new ArrayList<>();
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        boolean[][] dpx = new boolean[evens.size() + 1][20001];
        boolean[][] dpy = new boolean[odds.size() + 1][20001];
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
            writer.println("Yes");
        } else {
            writer.println("No");
        }

        writer.flush();
    }

    private static char[] readRuneSlice() throws IOException {
        return reader.readLine().toCharArray();
    }

    private static int[] readInt2() throws IOException {
        String[] parts = reader.readLine().split(" ");
        return new int[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])};
    }

    private static void printfDebug(String format, Object... args) {
        System.err.printf(format, args);
    }
}
// <END-OF-CODE>
