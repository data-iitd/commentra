import java.util.Arrays;
import java.util.Scanner;

public class ConvexHullArea {

    // Define a constant for PI using the arccosine function
    static final double PI = Math.acos(-1.0);

    // Function to determine the sign of a double value
    static int sig(double d) {
        return Math.abs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1; // Returns 0 if d is close to 0, -1 if d is negative, 1 if d is positive
    }

    // Class to represent a point in 2D space
    static class Point {
        double x, y; // Coordinates of the point

        // Constructor to initialize point with coordinates
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        // Method to calculate the modulus (length) of the point vector
        double mod() {
            return Math.sqrt(x * x + y * y);
        }

        // Method to calculate the square of the modulus (length squared)
        double modPow() {
            return x * x + y * y;
        }

        // Overloaded operator to compare two points
        public boolean lessThan(Point p) {
            return sig(x - p.x) != 0 ? x < p.x : sig(y - p.y) < 0; // Compare based on x, then y
        }
    }

    static Point[] P = new Point[110]; // Array to hold up to 110 points
    static int[] ch = new int[110]; // Array to hold the indices of the convex hull points
    static double[] ang = new double[110], ans = new double[110]; // Arrays to hold angles and results

    // Function to calculate the dot product of two vectors defined by points
    static double dot(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
    }

    // Overloaded function to calculate the dot product of two points
    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y; // Standard dot product
    }

    // Function to calculate the cross product of two vectors defined by points
    static double cross(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
    }

    // Function to determine if point x is between points a and b
    static int btw(Point x, Point a, Point b) {
        return sig(dot(x, a, b)); // Returns the sign of the dot product
    }

    // Function to calculate the distance between two points
    static double dis(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // Euclidean distance
    }

    // Function to calculate the cosine of the angle between two vectors
    static double cos(Point o, Point a, Point b) {
        return dot(o, a, b) / dis(o, a) / dis(o, b); // Cosine formula using dot product and distances
    }

    // Function to compute the convex hull using the Jarvis march algorithm
    static int jarvis(Point[] p, int n, int[] ch) {
        int d, i, o, s, l, t;
        // Find the leftmost point to start the hull
        for (d = i = 0; i < n; i++)
            if (p[i].lessThan(p[d]))
                d = i;

        l = s = ch[0] = d; // Initialize the starting point
        d = 1; // Index for the convex hull array

        // Loop to find all points in the convex hull
        do {
            o = l; // Current point
            for (i = 0; i < n; i++)
                // Check if point i is more counter-clockwise than the current point l
                if ((t = sig(cross(p[o], p[l], p[i]))) > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0))
                    l = i; // Update the point in the hull
            ch[d++] = l; // Add the point to the convex hull
        } while (l != s); // Continue until we return to the starting point

        return d - 1; // Return the number of points in the convex hull
    }

    // Main function
    public static void main(String[] args) {
        // Initialize angle and answer arrays to zero
        Arrays.fill(ang, 0);
        Arrays.fill(ans, 0);

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read number of points

        // Read the coordinates of the points
        for (int i = 0; i < n; i++) {
            int xx = scanner.nextInt();
            int yy = scanner.nextInt();
            P[i] = new Point(xx, yy); // Set the coordinates for each point
        }

        // Special case for two points
        if (n == 2) {
            System.out.println("0.5"); // Each point contributes equally to the area
            System.out.println("0.5");
        } else {
            // Compute the convex hull
            int m = jarvis(P, n, ch);
            double sum = 0;

            // Special case for two points in the convex hull
            if (m == 2) {
                ans[ch[0]] = 0.5; // Assign equal area to both points
                ans[ch[1]] = 0.5;
            } else {
                // Calculate angles for each point in the convex hull
                for (int i = 0; i < m; i++) {
                    ang[ch[i]] = PI - Math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
                }
                // Calculate the area contribution for each point
                for (int i = 0; i < n; i++) {
                    ans[i] = ang[i] / 2.0 / PI; // Normalize the angle to get area contribution
                }
            }

            // Output the area contributions for each point
            for (int i = 0; i < n; i++) {
                System.out.printf("%.20f\n", ans[i]); // Print results with high precision
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
