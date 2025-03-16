import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] balls = new int[n];
        for (int i = 0; i < n; i++) {
            balls[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int w_x = balls[x - 1] / 10;
            int r_x = balls[x - 1] % 10;
            int w_y = balls[y - 1] / 10;
            int r_y = balls[y - 1] % 10;
            if (w_x >= 1 && r_x >= 1) {
                balls[x - 1] = w_x * 10 + r_x - 1;
                balls[y - 1] = w_y * 10 + r_y + 1;
            } else if (w_x == 0) {
                balls[x - 1] = w_x * 10 + r_x - 1;
                balls[y - 1] = w_y * 10 + r_y + 1;
            } else {
                balls[x - 1] = w_x * 10 + r_x - 1;
                balls[y - 1] = w_y * 10 + r_y + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (balls[i] % 10!= 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
