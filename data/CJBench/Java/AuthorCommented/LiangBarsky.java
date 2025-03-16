

import java.util.Scanner;

/**
 * @author shikarisohan
 * @since 10/5/24
 *
 *  * The Liang-Barsky line clipping algorithm is an efficient algorithm for
 *  * line clipping against a rectangular window. It is based on the parametric
 *  * equation of a line and checks the intersections of the line with the
 *  * window boundaries. This algorithm calculates the intersection points,
 *  * if any, and returns the clipped line that lies inside the window.
 *  *
 *  * Reference:
 *  * https://en.wikipedia.org/wiki/Liang%E2%80%93Barsky_algorithm
 *
 * Clipping window boundaries are defined as (xMin, yMin) and (xMax, yMax).
 * The algorithm computes the clipped line segment if it's partially or
 * fully inside the clipping window.
 */
public class LiangBarsky {

    // Define the clipping window
    private final double xMin;
    private final double xMax;
    private final double yMin;
    private final double yMax;

    public LiangBarsky(double xMin, double yMin, double xMax, double yMax) {
        this.xMin = xMin;
        this.yMin = yMin;
        this.xMax = xMax;
        this.yMax = yMax;
    }

    public double[] liangBarskyClip(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;

        double[] p = {-dx, dx, -dy, dy};
        double[] q = {x1 - xMin, xMax - x1, y1 - yMin, yMax - y1};

        double[] resultT = clipLine(p, q);

        if (resultT == null) {
            return null; // Line is completely outside the clipping window
        }

        return calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1]);
    }

    // clip the line by adjusting t0 and t1 for each edge
    private double[] clipLine(double[] p, double[] q) {
        double t0 = 0.0;
        double t1 = 1.0;

        for (int i = 0; i < 4; i++) {
            if (p[i] == 0 && q[i] < 0) {
                return null; // Line is outside the boundary
            }

            double t = q[i] / p[i];
            if (p[i] < 0) {
                t0 = Math.max(t0, t);
                if (t0 > t1) return null;
            } else if (p[i] > 0) {
                t1 = Math.min(t1, t);
                if (t1 < t0) return null;
            }
        }

        return new double[] {t0, t1}; // Return valid t0 and t1
    }

    // calculate the clipped line based on t0 and t1
    private double[] calculateClippedLine(double x1, double y1, double dx, double dy, double t0, double t1) {
        double clippedX1 = x1 + t0 * dx;
        double clippedY1 = y1 + t0 * dy;
        double clippedX2 = x1 + t1 * dx;
        double clippedY2 = y1 + t1 * dy;

        return new double[] {clippedX1, clippedY1, clippedX2, clippedY2};
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input clipping window
        double xMin = scanner.nextDouble();
        double yMin = scanner.nextDouble();
        double xMax = scanner.nextDouble();
        double yMax = scanner.nextDouble();

        // Input line coordinates
        double x1 = scanner.nextDouble();
        double y1 = scanner.nextDouble();
        double x2 = scanner.nextDouble();
        double y2 = scanner.nextDouble();

        LiangBarsky clipper = new LiangBarsky(xMin, yMin, xMax, yMax);
        double[] clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2);

        if (clippedLine != null) {
            System.out.printf("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)%n", clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]);
        } else {
            System.out.println("The line is completely outside the clipping window.");
        }
    }
}
