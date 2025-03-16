
import java.util.Scanner;

// Final class to prevent extension and ensure encapsulation
public final class Main {
    private Main() {
    }

    // Error message for invalid radius
    private static final String POSITIVE_RADIUS = "Must be a positive radius";

    // Error message for invalid height
    private static final String POSITIVE_HEIGHT = "Must be a positive height";

    // Error message for invalid base
    private static final String POSITIVE_BASE = "Must be a positive base";

    // Method to calculate the surface area of a cube
    public static double surfaceMainCube(final double sideLength) {
        if (sideLength <= 0) { // Check if sideLength is valid
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return 6 * sideLength * sideLength; // Calculate the surface area
    }

    // Method to calculate the surface area of a sphere
    public static double surfaceMainSphere(final double radius) {
        if (radius <= 0) { // Check if radius is valid
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 4 * Math.PI * radius * radius; // Calculate the surface area
    }

    // Method to calculate the surface area of a rectangle
    public static double surfaceMainRectangle(final double length, final double width) {
        if (length <= 0) { // Check if length is valid
            throw new IllegalArgumentException("Must be a positive length");
        }
        if (width <= 0) { // Check if width is valid
            throw new IllegalArgumentException("Must be a positive width");
        }
        return length * width; // Calculate the surface area
    }

    // Method to calculate the surface area of a cylinder
    public static double surfaceMainCylinder(final double radius, final double height) {
        if (radius <= 0) { // Check if radius is valid
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        if (height <= 0) { // Check if height is valid
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return 2 * (Math.PI * radius * radius + Math.PI * radius * height); // Calculate the surface area
    }

    // Method to calculate the surface area of a square
    public static double surfaceMainSquare(final double sideLength) {
        if (sideLength <= 0) { // Check if sideLength is valid
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return sideLength * sideLength; // Calculate the surface area
    }

    // Method to calculate the surface area of a triangle
    public static double surfaceMainTriangle(final double base, final double height) {
        if (base <= 0) { // Check if base is valid
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) { // Check if height is valid
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height / 2; // Calculate the surface area using the formula: 1/2 * base * height
    }

    // Method to calculate the surface area of a parallelogram
    public static double surfaceMainParallelogram(final double base, final double height) {
        if (base <= 0) { // Check if base is valid
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) { // Check if height is valid
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height; // Calculate the surface area
    }

    // Method to calculate the surface area of a trapezium
    public static double surfaceMainTrapezium(final double base1, final double base2, final double height) {
        if (base1 <= 0) { // Check if base1 is valid
            throw new IllegalArgumentException(POSITIVE_BASE + 1);
        }
        if (base2 <= 0) { // Check if base2 is valid
            throw new IllegalArgumentException(POSITIVE_BASE + 2);
        }
        if (height <= 0) { // Check if height is valid
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return (base1 + base2) * height / 2; // Calculate the surface area using the formula: 1/2 * (base1 + base2) * height
    }

    // Method to calculate the surface area of a circle
    public static double surfaceMainCircle(final double radius) {
        if (radius <= 0) { // Check if radius is valid
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return Math.PI * radius * radius; // Calculate the surface area
    }

    // Method to calculate the surface area of a hemisphere
    public static double surfaceMainHemisphere(final double radius) {
        if (radius <= 0) { // Check if radius is valid
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 3 * Math.PI * radius * radius; // Calculate the surface area
    }

    // Method to calculate the surface area of a cone
    public static double surfaceMainCone(final double radius, final double height) {
        if (radius <= 0) { // Check if radius is valid
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        if (height <= 0) { // Check if height is valid
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius)); // Calculate the surface area
    }

    // Main method to read user input and calculate the surface area based on the shape selected
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the Scanner to read user input

        int choice = scanner.nextInt(); // Read the user's choice of shape

        double result = 0.0; // Initialize the result variable to store the calculated surface area

        switch (choice) { // Switch statement to calculate the surface area based on the user's choice
            case 1:
                double side = scanner.nextDouble(); // Read the side length of the cube from the user
                result = surfaceMainCube(side); // Calculate the surface area of the cube
                break;
            case 2:
                double radiusSphere = scanner.nextDouble(); // Read the radius of the sphere from the user
                result = surfaceMainSphere(radiusSphere); // Calculate the surface area of the sphere
                break;
            case 3:
                double length = scanner.nextDouble(); // Read the length of the rectangle from the user
                double width = scanner.nextDouble(); // Read the width of the rectangle from the user
                result = surfaceMainRectangle(length, width); // Calculate the surface area of the rectangle
                break;
            case 4:
                double radiusCylinder = scanner.nextDouble(); // Read the radius of the cylinder from the user
                double heightCylinder = scanner.nextDouble(); // Read the height of the cylinder from the user
                result = surfaceMainCylinder(radiusCylinder, heightCylinder); // Calculate the surface area of the cylinder
                break;
            case 5:
                double sideSquare = scanner.nextDouble(); // Read the side length of the square from the user
                result = surfaceMainSquare(sideSquare); // Calculate the surface area of the square
                break;
            case 6:
                double baseTriangle = scanner.nextDouble(); // Read the base of the triangle from the user
                double heightTriangle = scanner.nextDouble(); // Read the height of the triangle from the user
                result = surfaceMainTriangle(baseTriangle, heightTriangle); // Calculate the surface area of the triangle
                break;
            case 7:
                double baseParallelogram = scanner.nextDouble(); // Read the base of the parallelogram from the user
                double heightParallelogram = scanner.nextDouble(); // Read the height of the parallelogram from the user
                result = surfaceMainParallelogram(baseParallelogram, heightParallelogram); // Calculate the surface area of the parallelogram
                break;
            case 8:
                double base1 = scanner.nextDouble(); // Read the base1 of the trapezium from the user
                double base2 = scanner.nextDouble(); // Read the base2 of the trapezium from the user
                double heightTrapezium = scanner.nextDouble(); // Read the height of the trapezium from the user
                result = surfaceMainTrapezium(base1, base2, heightTrapezium); // Calculate the surface area of the trapezium
                break;
            case 9:
                double radiusCircle = scanner.nextDouble(); // Read the radius of the circle from the user
                result = surfaceMainCircle(radiusCircle); // Calculate the surface area of the circle
                break;
            case 10:
                double radiusHemisphere = scanner.nextDouble(); // Read the radius of the hemisphere from the user
                result = surfaceMainHemisphere(radiusHemisphere); // Calculate the surface area of the hemisphere
                break;
            case 11:
                double radiusCone = scanner.nextDouble(); // Read the radius of the cone from the user
                double heightCone = scanner.nextDouble(); // Read the height of the cone from the user
                result = surfaceMainCone(radiusCone, heightCone); // Calculate the surface area of the cone
                break;
            default:
                System.out.println("Invalid choice"); // Print an error message if the user enters an invalid choice
                return; // Exit the program if the user enters an invalid choice
        }

        System.out.printf("Calculated Main: %.2f%n", result); // Print the calculated 