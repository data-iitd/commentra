
import java.util.Arrays;
import java.util.Scanner;

public class s252511058{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Read the number of points.
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt(); // Read the x-coordinate of the point.
            int L = sc.nextInt(); // Read the length L.
            points[i] = new Point(x, x - L, x + L); // Create a new Point object with x, l, and r.
        }
        Arrays.sort(points); // Sort the points by their right boundary.
        int start = points[0].r; // Initialize the start of the first interval.
        int ans = 1; // Initialize the answer (at least one interval is selected).
        for (int i = 1; i < N; i++) {
            if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
                continue;
            }
            start = points[i].r; // Move to the next interval.
            ans++; // Increment the count of selected intervals.
        }
        System.out.println(ans); // Print the number of selected intervals.
    }

    // Point represents a point with x, l (left boundary), and r (right boundary).
    static class Point implements Comparable<Point> {
        int x, l, r;

        public Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Point o) {
            return this.r - o.r; // Compare by the right boundary.
        }
    }
}

