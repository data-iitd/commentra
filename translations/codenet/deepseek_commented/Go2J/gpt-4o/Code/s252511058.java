import java.util.*;

public class Main {
    // point represents a point with x, l (left boundary), and r (right boundary).
    static class Point {
        int x, l, r;

        Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Read the number of points.
        List<Point> points = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int x = sc.nextInt(); // Read the x-coordinate of the point.
            int L = sc.nextInt(); // Read the length L.
            points.add(new Point(x, x - L, x + L)); // Calculate the left and right boundaries.
        }

        // Sort the points by their right boundary.
        points.sort(Comparator.comparingInt(p -> p.r));

        // Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
        int start = points.get(0).r; // Initialize the start of the first interval.
        int ans = 1; // Initialize the answer (at least one interval is selected).

        for (int i = 1; i < points.size(); i++) {
            if (points.get(i).l < start) { // If the current interval overlaps with the previous one, skip it.
                continue;
            }
            start = points.get(i).r; // Move to the next interval.
            ans++; // Increment the count of selected intervals.
        }

        System.out.println(ans); // Print the number of selected intervals.
    }
}
// <END-OF-CODE>
