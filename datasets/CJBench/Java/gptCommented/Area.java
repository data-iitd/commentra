import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Constants for error messages
    private static final String POSITIVE_RADIUS = "Must be a positive radius";
    private static final String POSITIVE_HEIGHT = "Must be a positive height";
    private static final String POSITIVE_BASE = "Must be a positive base";

    // Method to calculate the surface area of a cube
    public static double surfaceMainCube(final double sideLength) {
        // Validate that the side length is positive
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        // Calculate and return the surface area of the cube
        return 6 * sideLength * sideLength;
    }

    // Method to calculate the surface area of a sphere
    public static double surfaceMainSphere(final double radius) {
        // Validate that the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate and return the surface area of the sphere
        return 4 * Math.PI * radius * radius;
    }

    // Method to calculate the surface area of a rectangle
    public static double surfaceMainRectangle(final double length, final double width) {
        // Validate that the length is positive
        if (length <= 0) {
            throw new IllegalArgumentException("Must be a positive length");
        }
        // Validate that the width is positive
        if (width <= 0) {
            throw new IllegalArgumentException("Must be a positive width");
        }
        // Calculate and return the surface area of the rectangle
        return length * width;
    }

    // Method to calculate the surface area of a cylinder
    public static double surfaceMainCylinder(final double radius, final double height) {
        // Validate that the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Validate that the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate and return the surface area of the cylinder
        return 2 * (Math.PI * radius * radius + Math.PI * radius * height);
    }

    // Method to calculate the surface area of a square
    public static double surfaceMainSquare(final double sideLength) {
        // Validate that the side length is positive
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        // Calculate and return the surface area of the square
        return sideLength * sideLength;
    }

    // Method to calculate the surface area of a triangle
    public static double surfaceMainTriangle(final double base, final double height) {
        // Validate that the base is positive
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        // Validate that the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate and return the surface area of the triangle
        return base * height / 2;
    }

    // Method to calculate the surface area of a parallelogram
    public static double surfaceMainParallelogram(final double base, final double height) {
        // Validate that the base is positive
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        // Validate that the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate and return the surface area of the parallelogram
        return base * height;
    }

    // Method to calculate the surface area of a trapezium
    public static double surfaceMainTrapezium(final double base1, final double base2, final double height) {
        // Validate that both bases are positive
        if (base1 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 1);
        }
        if (base2 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 2);
        }
        // Validate that the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate and return the surface area of the trapezium
        return (base1 + base2) * height / 2;
    }

    // Method to calculate the surface area of a circle
    public static double surfaceMainCircle(final double radius) {
        // Validate that the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate and return the surface area of the circle
        return Math.PI * radius * radius;
    }

    // Method to calculate the surface area of a hemisphere
    public static double surfaceMainHemisphere(final double radius) {
        // Validate that the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate and return the surface area of the hemisphere
        return 3 * Math.PI * radius * radius;
    }

    // Method to calculate the surface area of a cone
    public static double surfaceMainCone(final double radius, final double height) {
        // Validate that the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Validate that the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate and return the surface area of the cone
        return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        // Read the user's choice of shape
        int choice = scanner.nextInt();
        double result = 0.0;

        // Switch case to handle different shape calculations based on user choice
        switch (choice) {
            case 1:
                // Calculate surface area of a cube
                double side = scanner.nextDouble();
                result = surfaceMainCube(side);
                break;
            case 2:
                // Calculate surface area of a sphere
                double radiusSphere = scanner.nextDouble();
                result = surfaceMainSphere(radiusSphere);
                break;
            case 3:
                // Calculate surface area of a rectangle
                double length = scanner.nextDouble();
                double width = scanner.nextDouble();
                result = surfaceMainRectangle(length, width);
                break;
            case 4:
                // Calculate surface area of a cylinder
                double radiusCylinder = scanner.nextDouble();
                double heightCylinder = scanner.nextDouble();
                result = surfaceMainCylinder(radiusCylinder, heightCylinder);
                break;
            case 5:
                // Calculate surface area of a square
                double sideSquare = scanner.nextDouble();
                result = surfaceMainSquare(sideSquare);
                break;
            case 6:
                // Calculate surface area of a triangle
                double baseTriangle = scanner.nextDouble();
                double heightTriangle = scanner.nextDouble();
                result = surfaceMainTriangle(baseTriangle, heightTriangle);
                break;
            case 7:
                // Calculate surface area of a parallelogram
                double baseParallelogram = scanner.nextDouble();
                double heightParallelogram = scanner.nextDouble();
                result = surfaceMainParallelogram(baseParallelogram, heightParallelogram);
                break;
            case 8:
                // Calculate surface area of a trapezium
                double base1 = scanner.nextDouble();
                double base2 = scanner.nextDouble();
                double heightTrapezium = scanner.nextDouble();
                result = surfaceMainTrapezium(base1, base2, heightTrapezium);
                break;
            case 9:
                // Calculate surface area of a circle
                double radiusCircle = scanner.nextDouble();
                result = surfaceMainCircle(radiusCircle);
                break;
            case 10:
                // Calculate surface area of a hemisphere
                double radiusHemisphere = scanner.nextDouble();
                result = surfaceMainHemisphere(radiusHemisphere);
                break;
            case 11:
                // Calculate surface area of a cone
                double radiusCone = scanner.nextDouble();
                double heightCone = scanner.nextDouble();
                result = surfaceMainCone(radiusCone, heightCone);
                break;
            default:
                // Handle invalid choice
                System.out.println("Invalid choice");
                return;
        }
        // Print the calculated surface area result
        System.out.printf("Calculated Main: %.2f%n", result);
    }
}
