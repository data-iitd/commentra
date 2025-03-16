import java.util.Scanner;

public class Main {
    // Define the boundaries of the clipping window
    private final double xMin;
    private final double xMax;
    private final double yMin;
    private final double yMax;

    // Constructor to initialize the clipping window boundaries
    public Main(double xMin, double yMin, double xMax, double yMax) {
        this.xMin = xMin;
        this.yMin = yMin;
        this.xMax = xMax;
        this.yMax = yMax;
    }

    // Method to perform Liang-Barsky line clipping algorithm
    public double[] liangBarskyClip(double x1, double y1, double x2, double y2) {
        // Calculate the differences in x and y coordinates
        double dx = x2 - x1;
        double dy = y2 - y1;

        // Define the parameters for the Liang-Barsky algorithm
        double[] p = {-dx, dx, -dy, dy};
        double[] q = {x1 - xMin, xMax - x1, y1 - yMin, yMax - y1};

        // Call the clipping function to get the parameter values
        double[] resultT = clipLine(p, q);
        
        // If the line is completely outside the clipping window, return null
        if (resultT == null) {
            return null; 
        }
        
        // Calculate the coordinates of the clipped line segment
        return calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1]);
    }

    // Method to clip the line using the Liang-Barsky algorithm
    private double[] clipLine(double[] p, double[] q) {
        double t0 = 0.0; // Start parameter
        double t1 = 1.0; // End parameter

        // Iterate over each of the four edges of the clipping window
        for (int i = 0; i < 4; i++) {
            // Check for parallel lines outside the clipping window
            if (p[i] == 0 && q[i] < 0) {
                return null; 
            }
            double t = q[i] / p[i]; // Calculate the intersection parameter

            // Update t0 and t1 based on the direction of the line
            if (p[i] < 0) {
                t0 = Math.max(t0, t); // Update t0 for negative p
                if (t0 > t1) return null; // No intersection
            } else if (p[i] > 0) {
                t1 = Math.min(t1, t); // Update t1 for positive p
                if (t1 < t0) return null; // No intersection
            }
        }
        
        // Return the final parameter values for the clipped line
        return new double[] {t0, t1}; 
    }

    // Method to calculate the coordinates of the clipped line segment
    private double[] calculateClippedLine(double x1, double y1, double dx, double dy, double t0, double t1) {
        // Calculate the start and end points of the clipped line
        double clippedX1 = x1 + t0 * dx;
        double clippedY1 = y1 + t0 * dy;
        double clippedX2 = x1 + t1 * dx;
        double clippedY2 = y1 + t1 * dy;

        // Return the coordinates of the clipped line segment
        return new double[] {clippedX1, clippedY1, clippedX2, clippedY2};
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the clipping window boundaries from user input
        double xMin = scanner.nextDouble();
        double yMin = scanner.nextDouble();
        double xMax = scanner.nextDouble();
        double yMax = scanner.nextDouble();
        
        // Read the coordinates of the line segment to be clipped
        double x1 = scanner.nextDouble();
        double y1 = scanner.nextDouble();
        double x2 = scanner.nextDouble();
        double y2 = scanner.nextDouble();
        
        // Create an instance of the Main class with the clipping window
        Main clipper = new Main(xMin, yMin, xMax, yMax);
        
        // Perform the clipping operation
        double[] clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2);
        
        // Output the result of the clipping operation
        if (clippedLine != null) {
            System.out.printf("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)%n", clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]);
        } else {
            System.out.println("The line is completely outside the clipping window.");
        }
    }
}
