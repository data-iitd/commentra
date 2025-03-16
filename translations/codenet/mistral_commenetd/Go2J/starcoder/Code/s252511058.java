import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Creating a new Scanner object for reading the input from the standard input
        Scanner sc = new Scanner(System.in);
        // Reading the number of segments N from the input
        int N = sc.nextInt();
        // Creating a new array of size N to store all segments
        point[] points = new point[N];
        // Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' array
        for (int i = 0; i < N; i++) {
            points[i] = new point();
            points[i].x = sc.nextInt();
            // Reading left-endpoint L of the segment
            int L = sc.nextInt();
            // Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
            points[i].l = points[i].x - L;
            points[i].r = points[i].x + L;
        }
        // Sorting 'points' array based on their right-endpoints
        Arrays.sort(points, new Comparator<point>() {
            public int compare(point a, point b) {
                return a.r - b.r;
            }
        });
        // Initializing variables for result calculation
        int start = points[0].r;
        int ans = 1;
        // Iterating through all segments in sorted order and updating result accordingly
        for (int i = 0; i < N; i++) {
            // If the start of current segment is less than the end of previous segment, then skip it
            if (points[i].l < start) {
                continue;
            }
            // Updating start to the end of current segment
            start = points[i].r;
            // Incrementing answer by 1
            ans++;
        }
        // Printing the final answer
        System.out.println(ans);
    }
}

// Defining a class 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
class point {
    int x, l, r;
}

