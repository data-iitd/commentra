import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        
        int[][] balls = new int[N][2];
        balls[0][0] = 0;
        balls[0][1] = 1;
        for (int i = 1; i < N; i++) {
            balls[i][0] = 1;
            balls[i][1] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            String[] xy = br.readLine().split(" ");
            int x = Integer.parseInt(xy[0]) - 1;
            int y = Integer.parseInt(xy[1]) - 1;
            
            if (balls[x][0] > 0 && balls[x][1] > 0) {
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
