import java.util.*;
import java.util.Map.*;

public class Main {
    private static int[] colors; // Step 2: Declare an array to store the color of each node

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in); // Step 1: Initialize a Scanner object to read input
        int n = sc.nextInt(); // Read the number of nodes
        int m = n - 1; // Calculate the number of edges
        colors = new int[n]; // Step 2: Initialize the colors array with size n
        Arrays.fill(colors, -1); // Step 2: Set all colors to -1 initially

        Point[] points = new Point[n]; // Step 3: Create an array to store the points (nodes)
        for (int i = 0; i < n; i++) {
            points[i] = new Point(i); // Step 3: Initialize each point with its name
        }

        while (m-- > 0) { // Step 4: Read the edges and their lengths
            int me = sc.nextInt() - 1; // Read the first node and adjust for 0-based index
            int you = sc.nextInt() - 1; // Read the second node and adjust for 0-based index
            int length = sc.nextInt(); // Read the length of the edge
            points[me].becomeFriend(points[you], length); // Update the friends list for the first node
            points[you].becomeFriend(points[me], length); // Update the friends list for the second node
        }

        dfs(points[0], 0); // Step 5: Perform a DFS starting from the first point

        for (int c : colors) { // Step 6: Output the color of each node
            System.out.println(c);
        }
    }

    public static void dfs(Point p, int length) {
        boolean alreadyKnown = colors[p.name] != -1; // Check if the color of the current point is already known
        if (alreadyKnown) return; // If the color is already known, return

        if (length % 2 == 0) { // Check if the length of the path is even
            colors[p.name] = 0; // Color the current point as 0
        } else {
            colors[p.name] = 1; // Color the current point as 1
        }

        for (Entry<Point, Integer> entry : p.friends.entrySet()) { // Iterate through the friends of the current point
            Point friend = entry.getKey(); // Get the friend point
            int length2 = entry.getValue(); // Get the length of the edge to the friend
            dfs(friend, length + length2); // Recursively call DFS for the friend
        }
    }

    public static class Point {
        int name;
        Map<Point, Integer> friends;

        Point(int name) {
            this.name = name;
            this.friends = new HashMap<>(); // Initialize the friends map
        }

        void becomeFriend(Point p, int length) {
            this.friends.put(p, length); // Add the friend and the length of the edge
        }
    }
}
