import java.io.*;
import java.util.*;

public class Main {
    static boolean DEBUG = false;

    // Constants
    static final int BLACK = 35;
    static final int INF = 1000000007;
    static final int INF2 = 1000000009;
    static final int INF3 = 998244353;

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter writer = new PrintWriter(System.out);
            solve(reader, writer);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void solve(BufferedReader reader, PrintWriter writer) throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = reader.readLine();
            for (int j = 0; j < w; j++) {
                m[i][j] = (int) line.charAt(j);
            }
        }

        int answer = countConfigurations(h, w, k, m);
        writer.println(answer);
    }

    static int countConfigurations(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < (1 << h); i++) {
            for (int k = 0; k < (1 << w); k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    System.arraycopy(m[j], 0, tmp[j], 0, w);
                }
                for (int j = 0; j < h; j++) {
                    if ((1 << j & i) > 0) {
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    if ((1 << j & k) > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1;
                        }
                    }
                }
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        if (DEBUG) {
            System.out.println("new table");
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == BLACK) {
                    count++;
                }
            }
            if (DEBUG) {
                System.out.println(Arrays.toString(m[i]));
            }
        }
        if (DEBUG) {
            System.out.println("result : " + count);
        }
        return count;
    }
}

// <END-OF-CODE>
