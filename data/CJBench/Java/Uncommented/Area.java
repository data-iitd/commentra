import java.util.Scanner;
public final class Area {
    private Area() {
    }
    private static final String POSITIVE_RADIUS = "Must be a positive radius";
    private static final String POSITIVE_HEIGHT = "Must be a positive height";
    private static final String POSITIVE_BASE = "Must be a positive base";
    public static double surfaceAreaCube(final double sideLength) {
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return 6 * sideLength * sideLength;
    }
    public static double surfaceAreaSphere(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 4 * Math.PI * radius * radius;
    }
    public static double surfaceAreaRectangle(final double length, final double width) {
        if (length <= 0) {
            throw new IllegalArgumentException("Must be a positive length");
        }
        if (width <= 0) {
            throw new IllegalArgumentException("Must be a positive width");
        }
        return length * width;
    }
    public static double surfaceAreaCylinder(final double radius, final double height) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return 2 * (Math.PI * radius * radius + Math.PI * radius * height);
    }
    public static double surfaceAreaSquare(final double sideLength) {
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return sideLength * sideLength;
    }
    public static double surfaceAreaTriangle(final double base, final double height) {
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height / 2;
    }
    public static double surfaceAreaParallelogram(final double base, final double height) {
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height;
    }
    public static double surfaceAreaTrapezium(final double base1, final double base2, final double height) {
        if (base1 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 1);
        }
        if (base2 <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE + 2);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return (base1 + base2) * height / 2;
    }
    public static double surfaceAreaCircle(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return Math.PI * radius * radius;
    }
    public static double surfaceAreaHemisphere(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 3 * Math.PI * radius * radius;
    }
    public static double surfaceAreaCone(final double radius, final double height) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        double result = 0.0;
        switch (choice) {
            case 1:
                System.out.print("Enter side length: ");
                double side = scanner.nextDouble();
                result = surfaceAreaCube(side);
                break;
            case 2:
                System.out.print("Enter radius: ");
                double radiusSphere = scanner.nextDouble();
                result = surfaceAreaSphere(radiusSphere);
                break;
            case 3:
                System.out.print("Enter length and width: ");
                double length = scanner.nextDouble();
                double width = scanner.nextDouble();
                result = surfaceAreaRectangle(length, width);
                break;
            case 4:
                System.out.print("Enter radius and height: ");
                double radiusCylinder = scanner.nextDouble();
                double heightCylinder = scanner.nextDouble();
                result = surfaceAreaCylinder(radiusCylinder, heightCylinder);
                break;
            case 5:
                System.out.print("Enter side length: ");
                double sideSquare = scanner.nextDouble();
                result = surfaceAreaSquare(sideSquare);
                break;
            case 6:
                System.out.print("Enter base and height: ");
                double baseTriangle = scanner.nextDouble();
                double heightTriangle = scanner.nextDouble();
                result = surfaceAreaTriangle(baseTriangle, heightTriangle);
                break;
            case 7:
                System.out.print("Enter base and height: ");
                double baseParallelogram = scanner.nextDouble();
                double heightParallelogram = scanner.nextDouble();
                result = surfaceAreaParallelogram(baseParallelogram, heightParallelogram);
                break;
            case 8:
                System.out.print("Enter base1, base2 and height: ");
                double base1 = scanner.nextDouble();
                double base2 = scanner.nextDouble();
                double heightTrapezium = scanner.nextDouble();
                result = surfaceAreaTrapezium(base1, base2, heightTrapezium);
                break;
            case 9:
                System.out.print("Enter radius: ");
                double radiusCircle = scanner.nextDouble();
                result = surfaceAreaCircle(radiusCircle);
                break;
            case 10:
                System.out.print("Enter radius: ");
                double radiusHemisphere = scanner.nextDouble();
                result = surfaceAreaHemisphere(radiusHemisphere);
                break;
            case 11:
                System.out.print("Enter radius and height: ");
                double radiusCone = scanner.nextDouble();
                double heightCone = scanner.nextDouble();
                result = surfaceAreaCone(radiusCone, heightCone);
                break;
            default:
                System.out.println("Invalid choice");
                return;
        }
        System.out.printf("Calculated Area: %.2f%n", result);
    }
}
