import java.util.*;

public class Main {
    static final long Inf = Long.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt(), W = scanner.nextInt(), K = scanner.nextInt(); // Reading the dimensions of the grid and the number of obstacles.
        int x1 = scanner.nextInt() - 1, y1 = scanner.nextInt() - 1, x2 = scanner.nextInt() - 1, y2 = scanner.nextInt() - 1; // Reading the starting and ending coordinates, adjusted for 0-based indexing.
        x1 = swap(y1, x1); // Adjusting the coordinates for the grid's indexing.
        x2 = swap(y2, x2); // Adjusting the coordinates for the grid's indexing.
        String[] c = new String[H]; // Creating an array to hold the grid rows.
        for (int y = 0; y < H; y++) {
            c[y] = scanner.next(); // Reading each row of the grid.
        }

        int[] dx = {1, 0, -1, 0}; // Defining the possible horizontal directions.
        int[] dy = {0, 1, 0, -1}; // Defining the possible vertical directions.

        // Conversion function to get the ID of a state based on its coordinates and direction.
        int toID(int x, int y, int dir) {
            return 4 * (W * y + x) + dir;
        }

        // Conversion function to split the ID back into coordinates and direction.
        int[] splatID(int id) {
            return new int[]{id / 4 % W, id / 4 / W, id % 4};
        }

        long[] dist = new long[W * H * 4]; // Initializing the distance array.
        Arrays.fill(dist, Inf); // Setting all distances to infinity initially.

        PriorityQueue<State> q = new PriorityQueue<>(Comparator.comparingLong(s -> s.Cost)); // Initializing the priority queue.
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i))); // Starting from all possible directions at the initial position.
        }

        while (!q.isEmpty()) { // Processing each state in the priority queue.
            State now = q.poll(); // Getting the state with the minimum cost.
            int[] coords = splatID(now.ID); // Splitting the ID back into coordinates and direction.
            int x = coords[0], y = coords[1], dir = coords[2];
            if (c[y].charAt(x) == '@') { // Skipping if the current cell is an obstacle.
                continue;
            }
            if (dist[now.ID] <= now.Cost) { // Skipping if the current cost is not the minimum.
                continue;
            }
            dist[now.ID] = now.Cost; // Updating the minimum cost to reach this state.
            if (x == x2 && y == y2) { // Breaking if the end is reached.
                break;
            }
            for (int i = 0; i < 4; i++) { // Considering all possible directions.
                long nCost = (now.Cost + K - 1) / K * K; // Calculating the cost to the next state.
                int nID = toID(x, y, i); // Getting the ID of the next state.
                if (dist[nID] <= nCost) { // Skipping if the next state has been processed with a lower cost.
                    continue;
                }
                q.add(new State(nCost, nID)); // Pushing the next state into the priority queue.
            }
            int nx = x + dx[dir]; // Calculating the next x-coordinate.
            int ny = y + dy[dir]; // Calculating the next y-coordinate.
            if (0 <= nx && nx < W && 0 <= ny && ny < H) { // Checking if the next position is within the grid.
                long nCost = now.Cost + 1; // Calculating the cost to move to the next position.
                int nID = toID(nx, ny, dir); // Getting the ID of the next position.
                if (dist[nID] <= nCost) { // Skipping if the next position has been processed with a lower cost.
                    continue;
                }
                q.add(new State(nCost, nID)); // Pushing the next position into the priority queue.
            }
        }
        long ans = Inf; // Initializing the answer with infinity.
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i); // Getting the ID of the end position from each direction.
            if (dist[id] < ans) { // Updating the answer if a new minimum cost is found.
                long d2 = (dist[id] + K - 1) / K; // Calculating the minimum number of obstacles to overcome.
                if (d2 < ans) {
                    ans = d2;
                }
            }
        }
        if (ans < Inf) { // Outputting the result.
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }

    static int swap(int a, int b) {
        return a; // Adjusting the coordinates for the grid's indexing.
    }

    static class State {
        long Cost;
        int ID;

        State(long cost, int id) {
            this.Cost = cost;
            this.ID = id;
        }
    }
}
