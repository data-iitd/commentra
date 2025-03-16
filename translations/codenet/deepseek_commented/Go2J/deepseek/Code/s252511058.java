import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Point implements Comparable<Point> {
    int x, l, r;

    Point(int x, int l) {
        this.x = x;
        this.l = x - l;
        this.r = x + l;
    }

    @Override
    public int compareTo(Point other) {
        return Integer.compare(this.r, other.r);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of points.
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt(); // Read the x-coordinate of the point.
            int L = scanner.nextInt(); // Read the length L.
            points.add(new Point(x, L)); // Create a point and add it to the list.
        }
        Collections.sort(points); // Sort the points by their right boundary.
        // Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
        int start = points.get(0).r; // Initialize the start of the first interval.
        int ans = 1; // Initialize the answer (at least one interval is selected).
        for (int i = 0; i < points.size(); i++) {
            if (points.get(i).l < start) { // If the current interval overlaps with the previous one, skip it.
                continue;
            }
            start = points.get(i).r; // Move to the next interval.
            ans++; // Increment the count of selected intervals.
        }
        System.out.println(ans); // Print the number of selected intervals.
    }
}
