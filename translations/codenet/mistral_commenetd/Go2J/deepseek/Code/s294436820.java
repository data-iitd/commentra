import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int a = scanner.nextInt();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = scanner.nextLine();
            for (int j = 0; j < w; j++) {
                m[i][j] = s.charAt(j);
            }
        }

        int answer = solve(h, w, a, m);
        out.println(answer);
        out.flush();
    }

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == '35') {
                    count++;
                }
            }
        }
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
                    if ((i & (1 << j)) > 0) {
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 35;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    if ((k & (1 << j)) > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 35;
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
