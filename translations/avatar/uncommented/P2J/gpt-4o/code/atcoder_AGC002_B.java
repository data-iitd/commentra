import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static String next() throws IOException {
        if (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public static void main(String[] args) throws IOException {
        int N = nextInt();
        int M = nextInt();
        int[][] balls = new int[N][2];
        
        for (int i = 0; i < N; i++) {
            balls[i][0] = 1; // weight
            balls[i][1] = 0; // red
        }
        balls[0][0] = 0; // first ball weight
        balls[0][1] = 1; // first ball red

        for (int i = 0; i < M; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int w_x = balls[x][0];
            int r_x = balls[x][1];
            int w_y = balls[y][0];
            int r_y = balls[y][1];

            if (w_x >= 1 && r_x >= 1) {
                balls[x][0]--; // decrease weight of x
                balls[y][1]++; // increase red of y
            } else if (w_x == 0) {
                balls[x][1]--; // decrease red of x
                balls[y][1]++; // increase red of y
            } else {
                balls[x][0]--; // decrease weight of x
                balls[y][0]++; // increase weight of y
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
//<END-OF-CODE>
