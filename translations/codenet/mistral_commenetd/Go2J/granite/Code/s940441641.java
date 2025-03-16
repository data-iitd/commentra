
import java.util.*;

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
        x1 = y1;
        y1 = x1;
        x2 = y2;
        y2 = x2;
        String[] c = new String[H];
        for (int y = 0; y < H; y++) {
            c[y] = scanner.next();
        }
        int[][] dist = new int[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        PriorityQueue<State> q = new PriorityQueue<>();
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, 4 * (W * y1 + x1) + i));
        }
        while (!q.isEmpty()) {
            State now = q.poll();
            int x = now.id % W;
            int y = now.id / W;
            int dir = now.id % 4;
            if (dist[y][x] <= now.cost) {
                continue;
            }
            dist[y][x] = now.cost;
            for (int i = 0; i < 4; i++) {
                int nCost = now.cost + K;
                int nID = 4 * (W * y + x) + i;
                if (dist[nID / W][nID % W] <= nCost) {
                    continue;
                }
                q.add(new State(nCost, nID));
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                int nCost = now.cost + 1;
                int nID = 4 * (W * ny + nx) + dir;
                if (dist[nID / W][nID % W] <= nCost) {
                    continue;
                }
                q.add(new State(nCost, nID));
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int id = 4 * (W * y2 + x2) + i;
            if (dist[id / W][id % W] < ans) {
                ans = dist[id / W][id % W];
            }
        }
        System.out.println(ans == Integer.MAX_VALUE? -1 : ans);
    }

    static class State implements Comparable<State> {
        int cost, id;

        public State(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }

        @Override
        public int compareTo(State o) {
            return this.cost - o.cost;
        }
    }
}

// Constants
final int[] dx = {1, 0, -1, 0};
final int[] dy = {0, 1, 0, -1};

// Translate the above Java code to C++ and end with comment "