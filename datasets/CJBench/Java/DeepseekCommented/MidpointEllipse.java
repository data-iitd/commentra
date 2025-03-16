import java.util.*;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int centerX = scanner.nextInt(); // Read the x-coordinate of the center of the ellipse
        int centerY = scanner.nextInt(); // Read the y-coordinate of the center of the ellipse
        int a = scanner.nextInt(); // Read the semi-major axis of the ellipse
        int b = scanner.nextInt(); // Read the semi-minor axis of the ellipse
        List<int[]> points = drawEllipse(centerX, centerY, a, b); // Draw the ellipse and get the points
        System.out.println("Ellipse Points:");
        for (int[] point : points) { // Iterate through the points and print them
            System.out.println(point[0] + " " + point[1]);
        }
        scanner.close(); // Close the scanner to free up resources
    }
    public static List<int[]> drawEllipse(int centerX, int centerY, int a, int b) {
        List<int[]> points = new ArrayList<>(); // Initialize a list to store the ellipse points
        if (a == 0 && b == 0) {
            points.add(new int[] {centerX, centerY}); // If both axes are zero, add the center point
            return points;
        }
        if (a == 0) {
            for (int y = centerY - b; y <= centerY + b; y++) { // If a is zero, draw a vertical line
                points.add(new int[] {centerX, y});
            }
            return points;
        }
        if (b == 0) {
            for (int x = centerX - a; x <= centerX + a; x++) { // If b is zero, draw a horizontal line
                points.add(new int[] {x, centerY});
            }
            return points;
        }
        computeEllipsePoints(points, centerX, centerY, a, b); // Compute the ellipse points using the midpoint algorithm
        return points;
    }
    private static void computeEllipsePoints(Collection<int[]> points, int centerX, int centerY, int a, int b) {
        int x = 0, y = b; // Initialize the starting point (0, b)
        double d1 = b * b - a * a * b + 0.25 * a * a; // Initialize the decision parameter d1
        double dx = 2 * b * b * x, dy = 2 * a * a * y; // Initialize the differences dx and dy
        while (dx < dy) { // Iterate while dx is less than dy
            addEllipsePoints(points, centerX, centerY, x, y); // Add the symmetric points to the list
            if (d1 < 0) {
                x++; // Move along the x-axis
                dx += 2 * b * b; // Update dx
                d1 += dx + b * b; // Update d1
            } else {
                x++; // Move along the x-axis
                y--; // Move along the y-axis
                dx += 2 * b * b; // Update dx
                dy -= 2 * a * a; // Update dy
                d1 += dx - dy + b * b; // Update d1
            }
        }
        double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b; // Initialize the decision parameter d2
        while (y >= 0) { // Iterate while y is greater than or equal to zero
            addEllipsePoints(points, centerX, centerY, x, y); // Add the symmetric points to the list
            if (d2 > 0) {
                y--; // Move along the y-axis
                dy -= 2 * a * a; // Update dy
                d2 += a * a - dy; // Update d2
            } else {
                y--; // Move along the y-axis
                x++; // Move along the x-axis
                dx += 2 * b * b; // Update dx
                dy -= 2 * a * a; // Update dy
                d2 += dx - dy + a * a; // Update d2
            }
        }
    }
    private static void addEllipsePoints(Collection<int[]> points, int centerX, int centerY, int x, int y) {
        points.add(new int[] {centerX + x, centerY + y}); // Add the point (centerX + x, centerY + y)
        points.add(new int[] {centerX - x, centerY + y}); // Add the point (centerX - x, centerY + y)
        points.add(new int[] {centerX + x, centerY - y}); // Add the point (centerX + x, centerY - y)
        points.add(new int[] {centerX - x, centerY - y}); // Add the point (centerX - x, centerY - y)
    }
}
