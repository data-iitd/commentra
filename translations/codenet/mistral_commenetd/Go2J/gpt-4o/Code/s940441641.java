import java.util.*;

public class Main {
    static final long Inf = Long.MAX_VALUE;
    static int H, W, K, x1, y1, x2, y2;
    static long[] dist;
    static PriorityQueue<State> q;

    static class State implements Comparable<State> {
        long cost;
        int id;

        State(long cost, int id) {
            this.cost = cost;
            this.id = id;
        }

        @Override
        public int compareTo(State other) {
            return Long.compare(this.cost, other.cost);
        }
    }

    static int toID(int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    }

    static int[] splatID(int id) {
        int x = id % W;
        int y = id / W;
        int dir = id % 4;
        return new int[]{x, y, dir};
    }

    static void initDist() {
        dist = new long[W * H * 4];
        Arrays.fill(dist, Inf);
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i)));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        H = scanner.nextInt();
        W = scanner.nextInt();
        K = scanner.nextInt();
        x1 = scanner.nextInt() - 1;
        y1 = scanner.nextInt() - 1;
        x2 = scanner.nextInt() - 1;
        y2 = scanner.nextInt() - 1;

        // Swap x and y coordinates
        int temp = x1;
        x1 = y1;
        y1 = temp;
        temp = x2;
        x2 = y2;
        y2 = temp;

        q = new PriorityQueue<>();
        initDist();

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        while (!q.isEmpty()) {
            State now = q.poll();
            int[] pos = splatID(now.id);
            int x = pos[0], y = pos[1], dir = pos[2];

            if (x == x2 && y == y2) {
                break;
            }

            if (dist[now.id] <= now.cost) {
                continue;
            }

            dist[now.id] = now.cost;

            for (int i = 0; i < 4; i++) {
                long nCost = now.cost + K;
                int nID = toID(x, y, i);
                if (dist[nID] <= nCost) {
                    continue;
                }
                q.add(new State(nCost, nID));
            }

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                long nCost = now.cost + 1;
                int nID = toID(nx, ny, dir);
                if (dist[nID] <= nCost) {
                    continue;
                }
                q.add(new State(nCost, nID));
            }
        }

        long ans = Inf;
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i);
            if (dist[id] < ans) {
                ans = dist[id];
            }
        }

        if (ans < Inf) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}
