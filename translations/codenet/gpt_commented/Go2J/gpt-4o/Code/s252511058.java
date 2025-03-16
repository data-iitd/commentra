import java.util.*;

public class Main {
    // point class represents a point with its position and its left and right bounds.
    static class Point {
        int x, l, r; // x is the position, l is the left bound, r is the right bound

        Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new scanner for standard input
        int N = sc.nextInt(); // Read the number of points
        List<Point> points = new ArrayList<>(); // Create a list to hold the points

        // Read each point's position and calculate its left and right bounds
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt(); // Read the position of the point
            int L = sc.nextInt(); // Read the length to calculate bounds
            points.add(new Point(x, x - L, x + L)); // Calculate the left and right bounds
        }

        // Sort the points based on their right bounds
        points.sort(Comparator.comparingInt(p -> p.r));

        // Initialize the scheduling process for the interval scheduling problem
        int start = points.get(0).r; // Start with the right bound of the first point
        int ans = 1; // Initialize the count of non-overlapping intervals

        // Iterate through the sorted points to count non-overlapping intervals
        for (int i = 0; i < points.size(); i++) {
            if (points.get(i).l < start) { // If the left bound overlaps with the current start
                continue; // Skip to the next point
            }
            start = points.get(i).r; // Update the start to the right bound of the current point
            ans++; // Increment the count of non-overlapping intervals
        }

        // Output the total number of non-overlapping intervals
        System.out.println(ans);
    }
}

// <END-OF-CODE>
