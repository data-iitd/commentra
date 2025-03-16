
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int H = Integer.parseInt(line[0]);
        int W = Integer.parseInt(line[1]);
        int K = Integer.parseInt(line[2]);
        line = reader.readLine().split(" ");
        int x1 = Integer.parseInt(line[0]) - 1;
        int y1 = Integer.parseInt(line[1]) - 1;
        int x2 = Integer.parseInt(line[2]) - 1;
        int y2 = Integer.parseInt(line[3]) - 1;
        x1 = y1;
        x2 = y2;
        y1 = x1;
        y2 = x2;
        String[] c = new String[H];
        for (int y = 0; y < H; y++) {
            c[y] = reader.readLine();
        }

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        // Conversion function to get the ID of a state based on its coordinates and direction.
        int toID(int x, int y, int dir) {
            return 4 * (W * y + x) + dir;
        }
        // Conversion function to split the ID back into coordinates and direction.
        int[] splatID(int id) {
            int[] ret = new int[3];
            ret[0] = id / 4 % W;
            ret[1] = id / 4 / W;
            ret[2] = id % 4;
            return ret;
        }

        int[] dist = new int[W * H * 4];
        for (int i = 0; i < W * H * 4; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        PriorityQueue<State> q = new PriorityQueue<>(Comparator.comparingInt(a -> a.cost));
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i)));
        }
        while (!q.isEmpty()) {
            State now = q.poll();
            int x = splatID(now.id)[0];
            int y = splatID(now.id)[1];
            int dir = splatID(now.id)[2];
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
                q.add(new State(nCost, nID));
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                int nCost = now.cost + 1;
                int nID = toID(nx, ny, dir);
                if (dist[nID] <= nCost) {
                    continue;
                }
                q.add(new State(nCost, nID));
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

    static class State {
        int cost;
        int id;

        State(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }
    }

    