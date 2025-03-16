import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Constants for validation messages
    private static final String POSITIVE_RADIUS = "Must be a positive radius";
    private static final String POSITIVE_HEIGHT = "Must be a positive height";
    private static final String POSITIVE_BASE = "Must be a positive base";

    // Methods to calculate the surface area of various shapes
    public static double surfaceMainCube(final double sideLength) {
        // Check if the side length is positive
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        // Calculate the surface area of a cube
        return 6 * sideLength * sideLength;
    }

    public static double surfaceMainSphere(final double radius) {
        // Check if the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate the surface area of a sphere
        return 4 * Math.PI * radius * radius;
    }

    public static double surfaceMainRectangle(final double length, final double width) {
        // Check if the length is positive
        if (length <= 0) {
            throw new IllegalArgumentException("Must be a positive length");
        }
        // Check if the width is positive
        if (width <= 0) {
            throw new IllegalArgumentException("Must be a positive width");
        }
        // Calculate the surface area of a rectangle
        return length * width;
    }

    public static double surfaceMainCylinder(final double radius, final double height) {
        // Check if the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Check if the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate the surface area of a cylinder
        return 2 * (Math.PI * radius * radius + Math.PI * radius * height);
    }

    public static double surfaceMainSquare(final double sideLength) {
        // Check if the side length is positive
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        // Calculate the surface area of a square
        return sideLength * sideLength;
    }

    public static double surfaceMainTriangle(final double base, final double height) {
        // Check if the base is positive
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        // Check if the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate the surface area of a triangle
        return base * height / 2;
    }

    public static double surfaceMainParallelogram(final double base, final double height) {
        // Check if the base is positive
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        // Check if the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate the surface area of a parallelogram
        return base * height;
    }

    public static double surfaceMainTrapezium(final double base1, final double base2, final double height) {
        // Check if the first base is positive
        if (base1 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 1);
        }
        // Check if the second base is positive
        if (base2 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 2);
        }
        // Check if the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate the surface area of a trapezium
        return (base1 + base2) * height / 2;
    }

    public static double surfaceMainCircle(final double radius) {
        // Check if the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate the surface area of a circle
        return Math.PI * radius * radius;
    }

    public static double surfaceMainHemisphere(final double radius) {
        // Check if the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Calculate the surface area of a hemisphere
        return 3 * Math.PI * radius * radius;
    }

    public static double surfaceMainCone(final double radius, final double height) {
        // Check if the radius is positive
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        // Check if the height is positive
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        // Calculate the surface area of a cone
        return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
    }

    // Main method to read user input and calculate the surface area based on the choice
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        double result = 0.0;
        switch (choice) {
            case 1:
                double side = scanner.nextDouble();
                result = surfaceMainCube(side);
                break;
            case 2:
                double radiusSphere = scanner.nextDouble();
                result = surfaceMainSphere(radiusSphere);
                break;
            case 3:
                double length = scanner.nextDouble();
                double width = scanner.nextDouble();
                result = surfaceMainRectangle(length, width);
                break;
            case 4:
                double radiusCylinder = scanner.nextDouble();
                double heightCylinder = scanner.nextDouble();
                result = surfaceMainCylinder(radiusCylinder, heightCylinder);
                break;
            case 5:
                double sideSquare = scanner.nextDouble();
                result = surfaceMainSquare(sideSquare);
                break;
            case 6:
                double baseTriangle = scanner.nextDouble();
                double heightTriangle = scanner.nextDouble();
                result = surfaceMainTriangle(baseTriangle, heightTriangle);
                break;
            case 7:
                double baseParallelogram = scanner.nextDouble();
                double heightParallelogram = scanner.nextDouble();
                result = surfaceMainParallelogram(baseParallelogram, heightParallelogram);
                break;
            case 8:
                double base1 = scanner.nextDouble();
                double base2 = scanner.nextDouble();
                double heightTrapezium = scanner.nextDouble();
                result = surfaceMainTrapezium(base1, base2, heightTrapezium);
                break;
            case 9:
                double radiusCircle = scanner.nextDouble();
                result = surfaceMainCircle(radiusCircle);
                break;
            case 10:
                double radiusHemisphere = scanner.nextDouble();
                result = surfaceMainHemisphere(radiusHemisphere);
                break;
            case 11:
                double radiusCone = scanner.nextDouble();
                double heightCone = scanner.nextDouble();
                result = surfaceMainCone(radiusCone, heightCone);
                break;
            default:
                System.out.println("Invalid choice");
                return;
        }
        System.out.printf("Calculated Main: %.2f%n", result);
    }
}
