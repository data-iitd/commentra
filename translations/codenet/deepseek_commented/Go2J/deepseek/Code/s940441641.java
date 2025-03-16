import java.util.*;

class Main {
    static final long INF = 1L << 60;

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int K = scanner.nextInt();
        int x1 = scanner.nextInt() - 1;
        int y1 = scanner.nextInt() - 1;
        int x2 = scanner.nextInt() - 1;
        int y2 = scanner.nextInt() - 1;
        scanner.nextLine();

        String[] c = new String[H];
        for (int y = 0; y < H; y++) {
            c[y] = scanner.nextLine();
        }

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        int toID(int x, int y, int dir) {
            return 4 * (W * y + x) + dir;
        }

        int[] splatID(int id) {
            int[] result = new int[3];
            result[0] = id / 4 % W;
            result[1] = id / 4 / W;
            result[2] = id % 4;
            return result;
        }

        long[] dist = new long[W * H * 4];
        Arrays.fill(dist, INF);

        PriorityQueue<State> q = new PriorityQueue<>();
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i)));
        }

        while (!q.isEmpty()) {
            State now = q.poll();
            int[] splat = splatID(now.id);
            int x = splat[0], y = splat[1], dir = splat[2];

            if (c[y].charAt(x) == '@') {
                continue;
            }

            if (dist[now.id] <= now.cost) {
                continue;
            }

            dist[now.id] = now.cost;

            if (x == x2 && y == y2) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                long nCost = (now.cost + K - 1) / K * K;
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

        long ans = INF;
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i);
            if (dist[id] < ans) {
                long d2 = (dist[id] + K - 1) / K;
                if (d2 < ans) {
                    ans = d2;
                }
            }
        }

        if (ans < INF) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}
