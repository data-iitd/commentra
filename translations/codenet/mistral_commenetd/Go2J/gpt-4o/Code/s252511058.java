import java.util.*;

public class Main {
    // Custom class 'Point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
    static class Point {
        int x, l, r;

        Point(int x, int l, int r) {
            this.x = x;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        // Initializing scanner for reading input from standard input
        Scanner sc = new Scanner(System.in);
        // Reading the number of segments N from the input
        int N = sc.nextInt();
        // Creating a list 'points' to store all segments
        List<Point> points = new ArrayList<>();

        // Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int L = sc.nextInt();
            // Calculating left and right endpoints of the segment
            points.add(new Point(x, x - L, x + L));
        }

        // Sorting 'points' list based on their right-endpoints
        points.sort(Comparator.comparingInt(p -> p.r));

        // Initializing variables for result calculation
        int start = points.get(0).r;
        int ans = 1;

        // Iterating through all segments in sorted order and updating result accordingly
        for (int i = 0; i < points.size(); i++) {
            // If the start of current segment is less than the end of previous segment, then skip it
            if (points.get(i).l < start) {
                continue;
            }
            // Updating start to the end of current segment
            start = points.get(i).r;
            // Incrementing answer by 1
            ans++;
        }

        // Printing the final answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
