// Package main contains the main function for solving the problem.
import java.io.*;
import java.util.*;

public class Main {
    // Constants for large prime numbers used in modular arithmetic.
    private static final int INF = 1000000007;
    private static final int INF2 = 1000000009;
    private static final int INF3 = 998244353;

    // Constants for black cell representation.
    private static final int BLACK = 35;

    // Main function for solving the problem.
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        // Read input
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());

        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String line = reader.readLine();
            for (int j = 0; j < w; j++) {
                m[i][j] = (int) line.charAt(j);
            }
        }

        // Solve the problem
        int answer = solve(h, w, a, m);

        // Print the result
        writer.println(answer);
        writer.flush();
    }

    // Function to count the number of black cells in a grid.
    private static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == BLACK) {
                    count++;
                }
            }
        }
        return count;
    }

    // Function to solve the problem.
    private static int solve(int h, int w, int a, int[][] m) {
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
}

// <END-OF-CODE>
