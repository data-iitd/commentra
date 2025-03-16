
import java.util.Scanner;

public class Main {
    // Declare private instance variables for the clipping window bounds
    private final double xMin;
    private final double yMin;
    private final double xMax;
    private final double yMax;

    // Constructor initializes the clipping window bounds
    public Main(double xMin, double yMin, double xMax, double yMax) {
        this.xMin = xMin;
        this.yMin = yMin;
        this.xMax = xMax;
        this.yMax = yMax;
    }

    // Method to clip a line using the Liang-Barsky algorithm
    public double[] liangBarskyClip(double x1, double y1, double x2, double y2) {
        // Calculate the direction vector and the difference vector between the endpoints of the line
        double dx = x2 - x1;
        double dy = y2 - y1;
        double[] p = {-dx, dx, -dy, dy}; // The direction vector
        double[] q = {x1 - xMin, xMax - x1, y1 - yMin, yMax - y1}; // The vector from the origin to the line endpoints

        // Clip the line against the clipping window boundaries
        double[] resultT = clipLine(p, q);

        // If the line is completely outside the clipping window, return null
        if (resultT == null) {
            return null;
        }

        // Calculate the clipped line endpoints
        return calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1]);
    }

    // Method to clip a line against the clipping window boundaries
    private double[] clipLine(double[] p, double[] q) {
        // Initialize the t0 and t1 variables to represent the clipped line endpoints
        double t0 = 0.0;
        double t1 = 1.0;

        // Iterate through each boundary plane and check for intersection
        for (int i = 0; i < 4; i++) {
            // If the direction vector is parallel to the boundary plane, return null
            if (p[i] == 0) {
                if (q[i] < 0) {
                    // The line starts inside the clipping window, so no clipping is needed
                    return new double[] {t0, t1};
                }
                return null; // The line is completely outside the clipping window
            }

            // Calculate the intersection point t of the line with the boundary plane
            double t = q[i] / p[i];

            // If the line starts before the boundary plane, update t0
            if (p[i] < 0) {
                t0 = Math.max(t0, t);
                if (t0 > t1) return null; // The line is completely clipped
            }

            // If the line ends after the boundary plane, update t1
            else if (p[i] > 0) {
                t1 = Math.min(t1, t);
                if (t1 < t0) return null; // The line is completely clipped
            }
        }

        // If the line is completely clipped, return null
        if (t1 < 0) {
            return null;
        }

        // Otherwise, return the clipped line endpoints
        return new double[] {t0, t1};
    }

    // Method to calculate the clipped line endpoints
    private double[] calculateClippedLine(double x1, double y1, double dx, double dy, double t0, double t1) {
        // Calculate the clipped line endpoints
        double clippedX1 = x1 + t0 * dx;
        double clippedY1 = y1 + t0 * dy;
        double clippedX2 = x1 + t1 * dx;
        double clippedY2 = y1 + t1 * dy;

        // Return the clipped line endpoints as an array
        return new double[] {clippedX1, clippedY1, clippedX2, clippedY2};
    }

    // Main method to read input and test the clipping algorithm
    public static void main(String[] args) {
        // Initialize a Scanner to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the clipping window bounds from the standard input
        double xMin = scanner.nextDouble();
        double yMin = scanner.nextDouble();
        double xMax = scanner.nextDouble();
        double yMax = scanner.nextDouble();

        // Read the line endpoints from the standard input
        double x1 = scanner.nextDouble();
        double y1 = scanner.nextDouble();
        double x2 = scanner.nextDouble();
        double y2 = scanner.nextDouble();

        // Create a Main object with the clipping window bounds
        Main clipper = new Main(xMin, yMin, xMax, yMax);

        // Clip the line using the Liang-Barsky algorithm and print the result
        double[] clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2);
        if (clippedLine != null) {
            System.out.printf("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)%n", clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]);
        } else {
            System.out.println("The line is completely outside the clipping window.");
        }

        // Close the Scanner to free system resources
        scanner.close();
    }
}