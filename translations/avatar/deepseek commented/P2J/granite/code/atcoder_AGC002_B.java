
import java.util.*;
import java.io.*;

public class atcoder_AGC002_B{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[][] balls = new int[n][2];
        for (int i = 0; i < n; i++) {
            balls[i][0] = 1;
            balls[i][1] = 0;
        }
        balls[0][0] = 0;
        balls[0][1] = 1;
        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]) - 1;
            int y = Integer.parseInt(input[1]) - 1;
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
        for (int i = 0; i < n; i++) {
            if (balls[i][1] > 0) {
                ans += 1;
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "