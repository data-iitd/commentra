
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static List<int[]> generateCirclePoints(int centerX, int centerY, int radius) {
        List<int[]> points = new ArrayList<>(); // Initialize an empty list to store the circle points

        if (radius == 0) { // Check if the radius is zero
            points.add(new int[] {centerX, centerY}); // Add the center point to the list if the radius is zero
            return points; // Return the list with the center point
        }

        int x = radius; // Initialize x and y variables for calculating the circle points
        int y = 0;
        int p = 1 - radius; // Initialize the decision variable p

        addSymmetricPoints(points, centerX, centerY, x, y); // Add the first four symmetric points to the list

        while (x > y) { // Iterate while x is greater than y
            y++; // Increment y

            if (p <= 0) { // Check the condition for the decision variable p
                p = p + 2 * y + 1; // Update the value of p
            } else { // If the condition is not met, update x and p
                x--;
                p = p + 2 * y - 2 * x + 1;
            }

            addSymmetricPoints(points, centerX, centerY, x, y); // Add the next four symmetric points to the list
        }

        return points; // Return the list of circle points
    }

    private static void addSymmetricPoints(List<int[]> points, int centerX, int centerY, int x, int y) {
        // Add the eight symmetric points to the list
        points.add(new int[] {centerX + x, centerY + y});
        points.add(new int[] {centerX - x, centerY + y});
        points.add(new int[] {centerX + x, centerY - y});
        points.add(new int[] {centerX - x, centerY - y});
        points.add(new int[] {centerX + y, centerY + x});
        points.add(new int[] {centerX - y, centerY + x});
        points.add(new int[] {centerX + y, centerY - x});
        points.add(new int[] {centerX - y, centerY - x});
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input

        try {
            int centerX = scanner.nextInt(); // Read the center x-coordinate from the user
            int centerY = scanner.nextInt(); // Read the center y-coordinate from the user
            int radius = scanner.nextInt(); // Read the radius from the user

            List<int[]> circlePoints = generateCirclePoints(centerX, centerY, radius); // Generate the circle points

            System.out.println("The points on the circumference of the circle are:"); // Print a message to the console
            for (int[] point : circlePoints) { // Iterate through the list of circle points
                System.out.printf("(%d, %d)%n", point[0], point[1]); // Print each point to the console
            }
        } catch (Exception e) {
            System.out.println("Invalid input! Please enter integers."); // Print an error message if the user enters invalid input
        } finally {
            scanner.close(); // Close the Scanner object to free system resources
        }
    }
}