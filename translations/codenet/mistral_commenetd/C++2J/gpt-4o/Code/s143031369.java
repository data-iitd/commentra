import java.util.Arrays;
import java.util.Scanner;

public class ConvexHull {
    // Define a constant value
    static final double PI = Math.acos(-1.0);

    // Define a Point class
    static class Point {
        double x, y;

        // Default constructor
        Point() {}

        // Constructor with x and y coordinates
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        // Set x and y coordinates
        void set(double x, double y) {
            this.x = x;
            this.y = y;
        }

        // Calculate the modulus of a Point
        double mod() {
            return Math.sqrt(x * x + y * y);
        }

        // Output the x and y coordinates of a Point
        void output() {
            System.out.printf("x = %f, y = %f\n", x, y);
        }

        // Compare two Points based on their x and y coordinates
        public int compareTo(Point p) {
            if (Math.abs(this.x - p.x) > 1e-8) {
                return this.x < p.x ? -1 : 1;
            }
            return this.y < p.y ? -1 : (this.y > p.y ? 1 : 0);
        }
    }

    // Define an array of Points P
    static Point[] P = new Point[110];
    // Define an array ch to store the indices of the points in the convex hull
    static int[] ch = new int[110];
    // Define arrays ang and ans to store the angles and answers respectively
    static double[] ang = new double[110], ans = new double[110];

    // Calculate the dot product of three Points
    static double dot(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
    }

    // Calculate the cross product of a Point and two other Points
    static double cross(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
    }

    // Check if a Point is between two other Points on the counterclockwise arc
    static int btw(Point x, Point a, Point b) {
        return sig(dot(x, a, b));
    }

    // Calculate the distance between two Points
    static double dis(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // Calculate the cosine of the angle between a line passing through two Points and a given Point
    static double cos(Point o, Point a, Point b) {
        return dot(o, a, b) / dis(o, a) / dis(o, b);
    }

    // Determine the sign of a double value
    static int sig(double d) {
        return Math.abs(d) < 1e-8 ? 0 : (d < 0 ? -1 : 1);
    }

    // Find the convex hull of a set of Points using Jarvis March algorithm
    static int jarvis(Point[] p, int n, int[] ch) {
        int d = 0, i, o, s, l, t;
        for (i = 0; i < n; i++) {
            if (p[i].compareTo(p[d]) < 0) {
                d = i;
            }
        }
        l = s = ch[0] = d;
        d = 1;
        do {
            o = l;
            for (i = 0; i < n; i++) {
                t = sig(cross(p[o], p[l], p[i]));
                if (t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0)) {
                    l = i;
                }
            }
            ch[d++] = l;
        } while (l != s);
        return d - 1;
    }

    // Main function to read input and calculate the answers
    public static void main(String[] args) {
        Arrays.fill(ang, 0);
        Arrays.fill(ans, 0);
        Scanner scanner = new Scanner(System.in);
        // Read the number of Points
        int n = scanner.nextInt();
        // Initialize the Points
        for (int i = 0; i < n; i++) {
            double xx = scanner.nextDouble();
            double yy = scanner.nextDouble();
            // Set the x and y coordinates of the Point
            P[i] = new Point(xx, yy);
        }
        // Special case for 2 Points
        if (n == 2) {
            // Output the answers
            System.out.println("0.5");
            System.out.println("0.5");
        } else {
            // Find the convex hull of the Points
            int m = jarvis(P, n, ch);
            // Calculate the angles for the Points in the convex hull
            if (m == 2) {
                // Set the answers for the first and second Points
                ans[ch[0]] = 0.5;
                ans[ch[1]] = 0.5;
            } else {
                // Calculate the angles for all the Points in the convex hull
                for (int i = 0; i < m; i++) {
                    ang[ch[i]] = PI - Math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
                }
                // Calculate the answers for all the Points
                for (int i = 0; i < n; i++) {
                    ans[i] = ang[i] / 2.0 / PI;
                }
            }
            // Output the answers for all the Points
            for (int i = 0; i < n; i++) {
                System.out.printf("%.20f\n", ans[i]);
            }
        }
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
