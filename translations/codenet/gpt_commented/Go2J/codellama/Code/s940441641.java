
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) {
        // Read the dimensions of the grid and the cost parameter
        int H = readInt();
        int W = readInt();
        int K = readInt();
        // Read the starting and ending coordinates, adjusting for 0-based indexing
        int x1 = readInt() - 1;
        int y1 = readInt() - 1;
        int x2 = readInt() - 1;
        int y2 = readInt() - 1;
        x1 = y1; // Swap x and y for the starting point
        x2 = y2; // Swap x and y for the ending point

        // Read the grid representation
        String[] c = new String[H];
        for (int y = 0; y < H; y++) {
            c[y] = readString();
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
            int[] ret = new int[3];
            ret[0] = id / 4 % W;
            ret[1] = id / 4 / W;
            ret[2] = id % 4;
            return ret;
        }

        // Initialize the distance array with infinity
        int[] dist = new int[W * H * 4];
        Arrays.fill(dist, Integer.MAX_VALUE);

        // Initialize the priority queue (min-heap) with starting states
        PriorityQueue<State> q = new PriorityQueue<>(Comparator.comparingInt(s -> s.cost));
        for (int i = 0; i < 4; i++) {
            q.add(new State(0, toID(x1, y1, i)));
        }

        // Main loop for Dijkstra's algorithm
        while (!q.isEmpty()) {
            State now = q.poll(); // Get the state with the lowest cost
            int x = splatID(now.id)[0]; // Decompose the ID into coordinates and direction
            int y = splatID(now.id)[1];
            int dir = splatID(now.id)[2];

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
                int nCost = (now.cost + K - 1) / K * K; // Calculate the new cost
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
                int nCost = now.cost + 1; // Increment the cost for moving forward
                int nID = toID(nx, ny, dir); // Get the new ID for the position
                if (dist[nID] <= nCost) { // Skip if we have a better cost
                    continue;
                }
                // Push the new state into the priority queue
                q.add(new State(nCost, nID));
            }
        }

        // Determine the minimum cost to reach the destination
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int id = toID(x2, y2, i); // Get the ID for the destination in each direction
            if (dist[id] < ans) { // Check if we found a better cost
                int d2 = (dist[id] + K - 1) / K; // Calculate the cost in terms of K
                if (d2 < ans) { // Update the answer if it's better
                    ans = d2;
                }
            }
        }

        // Output the result
        if (ans < Integer.MAX_VALUE) {
            System.out.println(ans); // Print the minimum cost
        } else {
            System.out.println(-1); // Print -1 if the destination is unreachable
        }
    }

    // State represents a state in the priority queue with its cost and ID
    static class State {
        int cost;
        int id;

        State(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }
    }

    // Read an integer from input
    static int readInt() {
        try {
            return Integer.parseInt(reader.readLine());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Read a string from input
    static String readString() {
        try {
            return reader.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Reader for standard input
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    // END-OF-CODE
}