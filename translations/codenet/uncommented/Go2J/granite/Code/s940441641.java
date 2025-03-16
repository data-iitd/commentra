
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class s940441641{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int K = scanner.nextInt();
        int x1 = scanner.nextInt() - 1;
        int y1 = scanner.nextInt() - 1;
        int x2 = scanner.nextInt() - 1;
        int y2 = scanner.nextInt() - 1;
        char[][] c = new char[H][W];
        for (int i = 0; i < H; i++) {
            c[i] = scanner.next().toCharArray();
        }
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        int[][] dist = new int[H][W];
        for (int i = 0; i < H; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        Queue<int[]> queue = new ArrayDeque<>();
        for (int i = 0; i < 4; i++) {
            queue.add(new int[]{x1, y1, i});
            dist[y1][x1] = 0;
        }
        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int x = pos[0];
            int y = pos[1];
            int dir = pos[2];
            if (x == x2 && y == y2) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx]!= '@') {
                    int cost = dist[y][x] + 1;
                    if (dist[ny][nx] > cost) {
                        dist[ny][nx] = cost;
                        queue.add(new int[]{nx, ny, dir});
                    }
                }
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx]!= '@') {
                int cost = (dist[y][x] + K - 1) / K * K;
                if (dist[ny][nx] > cost) {
                    dist[ny][nx] = cost;
                    queue.add(new int[]{nx, ny, dir});
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            ans = Math.min(ans, dist[y2][x2]);
        }
        System.out.println(ans == Integer.MAX_VALUE? -1 : ans);
    }
}
