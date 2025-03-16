
import java.util.*;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read input from the console

        int centerX = scanner.nextInt(); // Read the center X coordinate from the input
        int centerY = scanner.nextInt(); // Read the center Y coordinate from the input
        int a = scanner.nextInt(); // Read the major axis length from the input
        int b = scanner.nextInt(); // Read the minor axis length from the input

        List<int[]> points = drawEllipse(centerX, centerY, a, b); // Call the drawEllipse method to get the list of ellipse points

        System.out.println("Ellipse Points:"); // Print the header message for the list of ellipse points
        for (int[] point : points) { // Iterate through the list of points and print each point
            System.out.println(point[0] + " " + point[1]);
        }

        scanner.close(); // Close the Scanner object to release the system resources
    }

    public static List<int[]> drawEllipse(int centerX, int centerY, int a, int b) {
        List<int[]> points = new ArrayList<>(); // Create an empty ArrayList to store the ellipse points

        if (a == 0 && b == 0) { // Check if the ellipse has zero radius
            points.add(new int[] {centerX, centerY}); // Add the center point to the list and return it
            return points;
        }

        if (a == 0) { // Check if the ellipse is a horizontal line
            for (int y = centerY - b; y <= centerY + b; y++) {
                points.add(new int[] {centerX, y}); // Add each point on the horizontal line to the list
            }
            return points;
        }

        if (b == 0) { // Check if the ellipse is a vertical line
            for (int x = centerX - a; x <= centerX + a; x++) {
                points.add(new int[] {x, centerY}); // Add each point on the vertical line to the list
            }
            return points;
        }

        computeEllipsePoints(points, centerX, centerY, a, b); // Call the computeEllipsePoints method to calculate the ellipse points
        return points;
    }

    private static void computeEllipsePoints(Collection<int[]> points, int centerX, int centerY, int a, int b) {
        int x = 0, y = b; // Initialize the x and y variables for the ellipse points calculation

        double d1 = b * b - a * a * b + 0.25 * a * a; // Calculate the discriminant d1 for the ellipse points calculation

        double dx = 2 * b * b * x, dy = 2 * a * a * y; // Calculate the temporary variables dx and dy for the while loop condition

        while (dx < dy) { // Iterate through the major half of the ellipse
            addEllipsePoints(points, centerX, centerY, x, y); // Add the current ellipse point to the list

            if (d1 < 0) { // Check if the next point is on the left side of the ellipse
                x++; // Increment x and update dx
                dx += 2 * b * b;
                d1 += dx + b * b;
            } else { // Check if the next point is on the right side of the ellipse
                x++; // Increment x
                y--; // Decrement y and update dy
                dx += 2 * b * b;
                dy -= 2 * a * a;
                d1 += dx - dy + b * b;
            }
        }

        double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b; // Calculate the discriminant d2 for the second half of the ellipse

        while (y >= 0) { // Iterate through the minor half of the ellipse
            addEllipsePoints(points, centerX, centerY, x, y); // Add the current ellipse point to the list

            if (d2 > 0) { // Check if the next point is below the ellipse
                y--; // Decrement y and update dy
                dy -= 2 * a * a;
                d2 += a * a - dy;
            } else { // Check if the next point is above the ellipse
                y--; // Decrement y
                x++; // Increment x and update dx
                dx += 2 * b * b;
                dy -= 2 * a * a;
                d2 += dx - dy + a * a;
            }
        }
    }

    private static void addEllipsePoints(Collection<int[]> points, int centerX, int centerY, int x, int y) {
        points.add(new int[] {centerX + x, centerY + y}); // Add the point with positive x and y coordinates to the list
        points.add(new int[] {centerX - x, centerY + y}); // Add the point with negative x and positive y coordinates to the list
        points.add(new int[] {centerX + x, centerY - y}); // Add the point with positive x and negative y coordinates to the list
        points.add(new int[] {centerX - x, centerY - y}); // Add the point with negative x and negative y coordinates to the list
    }
}