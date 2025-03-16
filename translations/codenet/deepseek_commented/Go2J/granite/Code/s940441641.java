
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class s940441641{
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
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        int[][] dist = new int[H][W];
        for (int i = 0; i < H; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }

        PriorityQueue<State> q = new PriorityQueue<>();
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, x1, y1, i));
        }
        while (!q.isEmpty()) {
            State now = q.poll();
            int x = now.x;
            int y = now.y;
            int dir = now.dir;
            if (c[y][x] == '@') {
                continue;
            }
            if (dist[y][x] <= now.cost) {
                continue;
            }
            dist[y][x] = now.cost;
            if (x == x2 && y == y2) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nCost = (now.cost + K - 1) / K * K;
                int nX = x + dx[i];
                int nY = y + dy[i];
                if (nX < 0 || nX >= W || nY < 0 || nY >= H) {
                    continue;
                }
                q.add(new State(nCost, nX, nY, i));
            }
            int nCost = now.cost + 1;
            int nX = x + dx[dir];
            int nY = y + dy[dir];
            if (nX < 0 || nX >= W || nY < 0 || nY >= H) {
                continue;
            }
            q.add(new State(nCost, nX, nY, dir));
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int d2 = (dist[y2][x2] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
        if (ans < Integer.MAX_VALUE) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
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

