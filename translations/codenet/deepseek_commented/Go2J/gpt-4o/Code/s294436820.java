import java.io.*;
import java.util.*;

public class Main {
    static boolean DEBUG = false;

    // Constants
    static final int INF = 1000000007;
    static final int INF2 = 1000000009;
    static final int INF3 = 998244353;
    static final int Black = 35;

    // IO functions
    static BufferedReader reader;
    static PrintWriter writer;

    public static void main(String[] args) {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new PrintWriter(System.out);

        try {
            String[] firstLine = reader.readLine().split(" ");
            int h = Integer.parseInt(firstLine[0]);
            int w = Integer.parseInt(firstLine[1]);
            int k = Integer.parseInt(firstLine[2]);

            int[][] m = new int[h][w];
            for (int i = 0; i < h; i++) {
                String line = reader.readLine();
                for (int j = 0; j < w; j++) {
                    m[i][j] = (int) line.charAt(j);
                }
            }

            int answer = solve(h, w, k, m);
            writer.println(answer);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            writer.flush();
            writer.close();
        }
    }

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        debug("new table");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
            debug(Arrays.toString(m[i]));
        }
        debug("result : ", count);
        return count;
    }

    static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < (1 << h); i++) {
            for (int k = 0; k < (1 << w); k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    System.arraycopy(m[j], 0, tmp[j], 0, w);
                }
                for (int j = 0; j < h; j++) {
                    if ((1 << j & i) > 0) {
                        debug("painted ", j, (1 << j), i, (1 << j & i));
                        Arrays.fill(tmp[j], 1);
                    }
                }
                for (int j = 0; j < w; j++) {
                    if ((1 << j & k) > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1;
                        }
                    }
                }
                debug("i", Integer.toBinaryString(i));
                debug("k", Integer.toBinaryString(k));
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }

    static void debug(Object... args) {
        if (!DEBUG) return;
        System.err.println(Arrays.toString(args));
    }
}

// <END-OF-CODE>
