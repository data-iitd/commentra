
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Read the number of points.
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = new Point(sc.nextInt(), sc.nextInt()); // Read the x-coordinate and the length of the interval.
        }
        sort(points); // Sort the points by their right boundary.
        // Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
        int start = points[0].r; // Initialize the start of the first interval.
        int ans = 1; // Initialize the answer (at least one interval is selected).
        for (int i = 0; i < points.length; i++) {
            if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
                continue;
            }
            start = points[i].r; // Move to the next interval.
            ans++; // Increment the count of selected intervals.
        }
        System.out.println(ans); // Print the number of selected intervals.
    }

    // Sort the points by their right boundary.
    public static void sort(Point[] points) {
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].r > points[j].r) {
                    Point temp = points[i];
                    points[i] = points[j];
                    points[j] = temp;
                }
            }
        }
    }

    // A class to represent a point with x, l (left boundary), and r (right boundary).
    public static class Point {
        int x, l, r;

        public Point(int x, int l) {
            this.x = x;
            this.l = x - l;
            this.r = x + l;
        }
    }
}

