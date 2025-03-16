import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    // Method to generate points on the circumference of a circle
    public static List<int[]> generateCirclePoints(int centerX, int centerY, int radius) {
        // List to hold the points on the circle
        List<int[]> points = new ArrayList<>();
        
        // If the radius is zero, return the center point
        if (radius == 0) {
            points.add(new int[] {centerX, centerY});
            return points;
        }
        
        // Initialize variables for the circle drawing algorithm
        int x = radius; // Start with the radius on the x-axis
        int y = 0;      // Start with y at 0
        int p = 1 - radius; // Decision parameter for the circle drawing algorithm
        
        // Add initial symmetric points for the circle
        addSymmetricPoints(points, centerX, centerY, x, y);
        
        // Loop to calculate points using Bresenham's circle algorithm
        while (x > y) {
            y++; // Increment y coordinate
            
            // Update the decision parameter based on its value
            if (p <= 0) {
                p = p + 2 * y + 1; // Inside the circle
            } else {
                x--; // Move left in the x direction
                p = p + 2 * y - 2 * x + 1; // Outside the circle
            }
            
            // Add symmetric points for the current (x, y)
            addSymmetricPoints(points, centerX, centerY, x, y);
        }
        
        // Return the list of points on the circle
        return points;
    }

    // Method to add symmetric points for the circle based on the current (x, y)
    private static void addSymmetricPoints(List<int[]> points, int centerX, int centerY, int x, int y) {
        // Add all eight symmetric points of the circle
        points.add(new int[] {centerX + x, centerY + y});
        points.add(new int[] {centerX - x, centerY + y});
        points.add(new int[] {centerX + x, centerY - y});
        points.add(new int[] {centerX - x, centerY - y});
        points.add(new int[] {centerX + y, centerY + x});
        points.add(new int[] {centerX - y, centerY + x});
        points.add(new int[] {centerX + y, centerY - x});
        points.add(new int[] {centerX - y, centerY - x});
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        try {
            // Read the center coordinates and radius from user input
            int centerX = scanner.nextInt();
            int centerY = scanner.nextInt();
            int radius = scanner.nextInt();
            
            // Generate the points on the circle
            List<int[]> circlePoints = generateCirclePoints(centerX, centerY, radius);
            System.out.println("The points on the circumference of the circle are:");
            
            // Print each point on the circle
            for (int[] point : circlePoints) {
                System.out.printf("(%d, %d)%n", point[0], point[1]);
            }
        } catch (Exception e) {
            // Handle invalid input
            System.out.println("Invalid input! Please enter integers.");
        } finally {
            // Close the scanner to free resources
            scanner.close();
        }
    }
}
