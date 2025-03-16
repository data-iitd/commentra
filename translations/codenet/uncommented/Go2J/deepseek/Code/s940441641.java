import java.util.*;

class Main {
    static class State {
        int cost, id;
        State(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }
    }

    static class PriorityQueueComparator implements Comparator<State> {
        public int compare(State a, State b) {
            return Integer.compare(a.cost, b.cost);
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
        for (int i = 0; i < H; i++) {
            c[i] = scanner.nextLine();
        }

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        int toID(int x, int y, int dir) {
            return 4 * (W * y + x) + dir;
        }

        int[] splatID(int id) {
            int x = id / 4 % W;
            int y = id / 4 / W;
            int dir = id % 4;
            return new int[]{x, y, dir};
        }

        int[] dist = new int[W * H * 4];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<State> pq = new PriorityQueue<>(new PriorityQueueComparator());
        for (int i = 0; i < 4; i++) {
            pq.add(new State(0, toID(x1, y1, i)));
        }

        while (!pq.isEmpty()) {
            State now = pq.poll();
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
                int nCost = (now.cost + K - 1) / K * K;
                int nID = toID(x, y, i);
                if (dist[nID] <= nCost) {
                    continue;
                }
                pq.add(new State(nCost, nID));
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                int nCost = now.cost + 1;
                int nID = toID(nx, ny, dir);
                if (dist[nID] <= nCost) {
                    continue;
                }
                pq.add(new State(nCost, nID));
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i);
            if (dist[id] < ans) {
                int d2 = (dist[id] + K - 1) / K;
                if (d2 < ans) {
                    ans = d2;
                }
            }
        }

        if (ans < Integer.MAX_VALUE) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}
