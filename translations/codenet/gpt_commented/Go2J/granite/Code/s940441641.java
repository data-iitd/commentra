
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class s940441641{
    static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static final int INF = 1000000000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        int H = Integer.parseInt(split[0]);
        int W = Integer.parseInt(split[1]);
        int K = Integer.parseInt(split[2]);
        split = br.readLine().split(" ");
        int x1 = Integer.parseInt(split[0]) - 1;
        int y1 = Integer.parseInt(split[1]) - 1;
        split = br.readLine().split(" ");
        int x2 = Integer.parseInt(split[0]) - 1;
        int y2 = Integer.parseInt(split[1]) - 1;
        char[][] c = new char[H][W];
        for (int i = 0; i < H; i++) {
            c[i] = br.readLine().toCharArray();
        }
        int[][][] dist = new int[H][W][4];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                Arrays.fill(dist[i][j], INF);
            }
        }
        PriorityQueue<State> q = new PriorityQueue<>();
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, x1, y1, i));
            dist[y1][x1][i] = 0;
        }
        while (!q.isEmpty()) {
            State now = q.poll();
            int x = now.x;
            int y = now.y;
            int dir = now.dir;
            if (c[y][x] == '@') {
                continue;
            }
            if (dist[y][x][dir] < now.cost) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + DIRS[i][0];
                int ny = y + DIRS[i][1];
                if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                    int nCost = now.cost + 1;
                    if (dist[ny][nx][dir] > nCost) {
                        dist[ny][nx][dir] = nCost;
                        q.add(new State(nCost, nx, ny, dir));
                    }
                }
            }
            int nCost = (now.cost + K - 1) / K * K;
            int nx = x + DIRS[dir][0];
            int ny = y + DIRS[dir][1];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                if (dist[ny][nx][dir] > nCost) {
                    dist[ny][nx][dir] = nCost;
                    q.add(new State(nCost, nx, ny, dir));
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 4; i++) {
            ans = Math.min(ans, dist[y2][x2][i]);
        }
        System.out.println(ans == INF? -1 : ans);
    }

    static class State implements Comparable<State> {
        int cost, x, y, dir;

        public State(int cost, int x, int y, int dir) {
            this.cost = cost;
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        @Override
        public int compareTo(State o) {
            return cost - o.cost;
        }
    }
}

// Translate the above Java code to C++ and end with comment "