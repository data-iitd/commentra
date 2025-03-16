import java.util.*;

public class Main {
    static final long Inf = Long.MAX_VALUE; // Define a constant for infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the grid and the cost parameter
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Read the starting and ending coordinates, adjusting for 0-based indexing
        int x1 = scanner.nextInt() - 1;
        int y1 = scanner.nextInt() - 1;
        int x2 = scanner.nextInt() - 1;
        int y2 = scanner.nextInt() - 1;
        int temp = x1; x1 = y1; y1 = temp; // Swap x and y for the starting point
        temp = x2; x2 = y2; y2 = temp; // Swap x and y for the ending point

        // Read the grid representation
        String[] c = new String[H];
        for (int y = 0; y < H; y++) {
            c[y] = scanner.next();
        }

        // Define movement directions (right, down, left, up)
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        // Function to convert (x, y, dir) to a unique ID
        int toID(int x, int y, int dir) {
            return 4 * (W * y + x) + dir;
        }

        // Function to convert an ID back to (x, y, dir)
        int[] splatID(int id) {
            return new int[]{id / 4 % W, id / 4 / W, id % 4};
        }

        // Initialize the distance array with infinity
        long[] dist = new long[W * H * 4];
        Arrays.fill(dist, Inf);

        // Initialize the priority queue (min-heap) with starting states
        PriorityQueue<State> q = new PriorityQueue<>(Comparator.comparingLong(s -> s.cost));
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i)));
        }

        // Main loop for Dijkstra's algorithm
        while (!q.isEmpty()) {
            State now = q.poll(); // Get the state with the lowest cost
            int[] coords = splatID(now.id); // Decompose the ID into coordinates and direction
            int x = coords[0], y = coords[1], dir = coords[2];

            // Skip if the current position is a wall
            if (c[y].charAt(x) == '@') {
                continue;
            }
            // Skip if we have already found a better cost for this state
            if (dist[now.id] <= now.cost) {
                continue;
            }
            // Update the distance for the current state
            dist[now.id] = now.cost;

            // If we reached the destination, exit the loop
            if (x == x2 && y == y2) {
                break;
            }

            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                long nCost = (now.cost + K - 1) / K * K; // Calculate the new cost
                int nID = toID(x, y, i); // Get the new ID for the direction
                if (dist[nID] <= nCost) { // Skip if we have a better cost
                    continue;
                }
                // Push the new state into the priority queue
                q.add(new State(nCost, nID));
            }

            // Move in the current direction
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // Check if the new position is within bounds
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                long nCost = now.cost + 1; // Increment the cost for moving forward
                int nID = toID(nx, ny, dir); // Get the new ID for the position
                if (dist[nID] <= nCost) { // Skip if we have a better cost
                    continue;
                }
                // Push the new state into the priority queue
                q.add(new State(nCost, nID));
            }
        }

        // Determine the minimum cost to reach the destination
        long ans = Inf;
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i); // Get the ID for the destination in each direction
            if (dist[id] < ans) { // Check if we found a better cost
                long d2 = (dist[id] + K - 1) / K; // Calculate the cost in terms of K
                if (d2 < ans) { // Update the answer if it's better
                    ans = d2;
                }
            }
        }

        // Output the result
        if (ans < Inf) {
            System.out.println(ans); // Print the minimum cost
        } else {
            System.out.println(-1); // Print -1 if the destination is unreachable
        }
    }

    // State represents a state in the priority queue with its cost and ID
    static class State {
        long cost;
        int id;

        State(long cost, int id) {
            this.cost = cost;
            this.id = id;
        }
    }
}
// <END-OF-CODE>
