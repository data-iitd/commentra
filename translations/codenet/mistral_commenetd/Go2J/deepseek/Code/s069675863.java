import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        char[] S = scanner.next().toCharArray();
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        // Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
        boolean[][] dpx = new boolean[8000][20000];
        boolean[][] dpy = new boolean[8000][20000];

        // Iterate through the even indices of the F slice and update the dpx array accordingly
        for (int i = 0; i < F.length; i += 2) {
            updateDPX(dpx, i, F[i]);
        }

        // Iterate through the odd indices of the F slice and update the dpy array accordingly
        for (int i = 1; i < F.length; i += 2) {
            updateDPY(dpy, i, F[i]);
        }

        // Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
        if (dpx[F.length / 2][x + 10000] && dpy[F.length / 2][y + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // helper function to initialize a 2D boolean array
    public static boolean[][] make2DBooleanArray(int rows, int cols) {
        boolean[][] array = new boolean[rows][cols];
        return array;
    }

    // helper function to update dpx array
    public static void updateDPX(boolean[][] dpx, int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
            }
            if (j - val >= 2000 && index != 0) {
                dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
            }
        }
    }

    // helper function to update dpy array
    public static void updateDPY(boolean[][] dpy, int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
            }
            if (j - val >= 2000) {
                dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
            }
        }
    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
