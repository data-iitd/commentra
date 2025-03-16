import java.util.*;
import java.io.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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
        FastScanner scanner = new FastScanner();
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[][] balls = new int[N][2];
        balls[0] = new int[]{0, 1};

        for (int i = 0; i < M; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;

            int w_x = balls[x][0];
            int r_x = balls[x][1];
            int w_y = balls[y][0];
            int r_y = balls[y][1];

            if (w_x >= 1 && r_x >= 1) {
                balls[x][0] -= 1;
                balls[y][1] += 1;
            } else if (w_x == 0) {
                balls[x][1] -= 1;
                balls[y][1] += 1;
            } else {
                balls[x][0] -= 1;
                balls[y][0] += 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (balls[i][1] > 0) {
                ans += 1;
            }
        }

        System.out.println(ans);
    }
}
