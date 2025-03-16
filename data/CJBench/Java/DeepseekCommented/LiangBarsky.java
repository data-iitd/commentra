import java.util.Scanner;
public class Main {
    private final double xMin;  // Clipping window boundary
    private final double xMax;  // Clipping window boundary
    private final double yMin;  // Clipping window boundary
    private final double yMax;  // Clipping window boundary

    // Constructor to initialize the clipping window boundaries
    public Main(double xMin, double yMin, double xMax, double yMax) {
        this.xMin = xMin;
        this.yMin = yMin;
        this.xMax = xMax;
        this.yMax = yMax;
    }

    // Method to clip a line segment against the clipping window using the Liang-Barsky algorithm
    public double[] liangBarskyClip(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;  // Calculate the difference in x coordinates
        double dy = y2 - y1;  // Calculate the difference in y coordinates
        double[] p = {-dx, dx, -dy, dy};  // Coefficients for the line segment
        double[] q = {x1 - xMin, xMax - x1, y1 - yMin, yMax - y1};  // Coefficients for the line segment relative to the clipping window
        double[] resultT = clipLine(p, q);  // Calculate the parameters for the line clipping
        if (resultT == null) {
            return null;  // If the line is completely outside the clipping window, return null
        }
        return calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1]);  // Calculate and return the clipped line coordinates
    }

    // Helper method to calculate the parameters for the line clipping
    private double[] clipLine(double[] p, double[] q) {
        double t0 = 0.0;  // Initial parameter for the start of the clipped line
        double t1 = 1.0;  // Initial parameter for the end of the clipped line
        for (int i = 0; i < 4; i++) {
            if (p[i] == 0 && q[i] < 0) {
                return null;  // If the line is parallel to an edge and outside the window, return null
            }
            double t = q[i] / p[i];  // Calculate the parameter t for the current edge
            if (p[i] < 0) {
                t0 = Math.max(t0, t);  // Update the start parameter if necessary
                if (t0 > t1) return null;  // If t0 is greater than t1, the line is outside
            } else if (p[i] > 0) {
                t1 = Math.min(t1, t);  // Update the end parameter if necessary
                if (t1 < t0) return null;  // If t1 is less than t0, the line is outside
            }
        }
        return new double[] {t0, t1};  // Return the parameters for the clipped line
    }

    // Helper method to calculate the coordinates of the clipped line segment
    private double[] calculateClippedLine(double x1, double y1, double dx, double dy, double t0, double t1) {
        double clippedX1 = x1 + t0 * dx;  // Calculate the x coordinate of the start of the clipped line
        double clippedY1 = y1 + t0 * dy;  // Calculate the y coordinate of the start of the clipped line
        double clippedX2 = x1 + t1 * dx;  // Calculate the x coordinate of the end of the clipped line
        double clippedY2 = y1 + t1 * dy;  // Calculate the y coordinate of the end of the clipped line
        return new double[] {clippedX1, clippedY1, clippedX2, clippedY2};  // Return the coordinates of the clipped line
    }

    // Main method to read input and apply the clipping algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double xMin = scanner.nextDouble();  // Read the x minimum boundary of the clipping window
        double yMin = scanner.nextDouble();  // Read the y minimum boundary of the clipping window
        double xMax = scanner.nextDouble();  // Read the x maximum boundary of the clipping window
        double yMax = scanner.nextDouble();  // Read the y maximum boundary of the clipping window
        double x1 = scanner.nextDouble();  // Read the x coordinate of the start of the line segment
        double y1 = scanner.nextDouble();  // Read the y coordinate of the start of the line segment
        double x2 = scanner.nextDouble();  // Read the x coordinate of the end of the line segment
        double y2 = scanner.nextDouble();  // Read the y coordinate of the end of the line segment
        Main clipper = new Main(xMin, yMin, xMax, yMax);  // Create a new instance of the Main class
        double[] clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2);  // Apply the clipping algorithm
        if (clippedLine != null) {
            System.out.printf("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)%n", clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]);  // Print the clipped line coordinates
        } else {
            System.out.println("The line is completely outside the clipping window.");  // Print a message if the line is outside the clipping window
        }
    }
}
