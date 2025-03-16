import java.util.*;
import java.io.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
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
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[][] balls = new int[N][2];
        balls[0] = new int[]{0, 1};
        for (int i = 0; i < M; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            if (balls[x][0] >= 1 && balls[x][1] >= 1) {
                balls[x][0]--;
                balls[y][1]++;
            } else if (balls[x][0] == 0) {
                balls[x][1]--;
                balls[y][1]++;
            } else {
                balls[x][0]--;
                balls[y][0]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (balls[i][1] > 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
