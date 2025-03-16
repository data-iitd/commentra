import java.util.*;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the center coordinates and the semi-major and semi-minor axes of the ellipse
        int centerX = scanner.nextInt();
        int centerY = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Generate the points of the ellipse based on the input parameters
        List<int[]> points = drawEllipse(centerX, centerY, a, b);
        
        // Output the generated points of the ellipse
        System.out.println("Ellipse Points:");
        for (int[] point : points) {
            System.out.println(point[0] + " " + point[1]);
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    public static List<int[]> drawEllipse(int centerX, int centerY, int a, int b) {
        // Initialize a list to hold the points of the ellipse
        List<int[]> points = new ArrayList<>();
        
        // Handle the case where both axes are zero (point case)
        if (a == 0 && b == 0) {
            points.add(new int[] {centerX, centerY});
            return points;
        }
        
        // Handle the case where the semi-major axis is zero (vertical line)
        if (a == 0) {
            for (int y = centerY - b; y <= centerY + b; y++) {
                points.add(new int[] {centerX, y});
            }
            return points;
        }
        
        // Handle the case where the semi-minor axis is zero (horizontal line)
        if (b == 0) {
            for (int x = centerX - a; x <= centerX + a; x++) {
                points.add(new int[] {x, centerY});
            }
            return points;
        }
        
        // Compute the points of the ellipse using the midpoint ellipse algorithm
        computeEllipsePoints(points, centerX, centerY, a, b);
        return points;
    }

    private static void computeEllipsePoints(Collection<int[]> points, int centerX, int centerY, int a, int b) {
        // Initialize variables for the ellipse drawing algorithm
        int x = 0, y = b;
        double d1 = b * b - a * a * b + 0.25 * a * a;
        double dx = 2 * b * b * x, dy = 2 * a * a * y;

        // First region of the ellipse (x < y)
        while (dx < dy) {
            // Add the calculated points to the collection
            addEllipsePoints(points, centerX, centerY, x, y);
            if (d1 < 0) {
                // Move to the next point in the x direction
                x++;
                dx += 2 * b * b;
                d1 += dx + b * b;
            } else {
                // Move to the next point in both x and y directions
                x++;
                y--;
                dx += 2 * b * b;
                dy -= 2 * a * a;
                d1 += dx - dy + b * b;
            }
        }

        // Second region of the ellipse (y < x)
        double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
        while (y >= 0) {
            // Add the calculated points to the collection
            addEllipsePoints(points, centerX, centerY, x, y);
            if (d2 > 0) {
                // Move to the next point in the y direction
                y--;
                dy -= 2 * a * a;
                d2 += a * a - dy;
            } else {
                // Move to the next point in both x and y directions
                y--;
                x++;
                dx += 2 * b * b;
                dy -= 2 * a * a;
                d2 += dx - dy + a * a;
            }
        }
    }

    private static void addEllipsePoints(Collection<int[]> points, int centerX, int centerY, int x, int y) {
        // Add symmetrical points of the ellipse to the collection
        points.add(new int[] {centerX + x, centerY + y});
        points.add(new int[] {centerX - x, centerY + y});
        points.add(new int[] {centerX + x, centerY - y});
        points.add(new int[] {centerX - x, centerY - y});
    }
}
