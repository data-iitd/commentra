
import java.util.Scanner;
public class LiangBarsky {
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
            return null; 
        }
        return calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1]);
    }
    private double[] clipLine(double[] p, double[] q) {
        double t0 = 0.0;
        double t1 = 1.0;
        for (int i = 0; i < 4; i++) {
            if (p[i] == 0 && q[i] < 0) {
                return null; 
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
        return new double[] {t0, t1}; 
    }
    private double[] calculateClippedLine(double x1, double y1, double dx, double dy, double t0, double t1) {
        double clippedX1 = x1 + t0 * dx;
        double clippedY1 = y1 + t0 * dy;
        double clippedX2 = x1 + t1 * dx;
        double clippedY2 = y1 + t1 * dy;
        return new double[] {clippedX1, clippedY1, clippedX2, clippedY2};
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double xMin = scanner.nextDouble();
        double yMin = scanner.nextDouble();
        double xMax = scanner.nextDouble();
        double yMax = scanner.nextDouble();
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
