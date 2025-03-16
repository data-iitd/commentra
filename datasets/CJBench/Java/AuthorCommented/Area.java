import java.util.Scanner;

/**
 * Find the area of various geometric shapes
 */
public final class Area {
    private Area() {
    }

    /**
     * String of IllegalArgumentException for radius
     */
    private static final String POSITIVE_RADIUS = "Must be a positive radius";
    /**
     * String of IllegalArgumentException for height
     */
    private static final String POSITIVE_HEIGHT = "Must be a positive height";
    /**
     * String of IllegalArgumentException for base
     */
    private static final String POSITIVE_BASE = "Must be a positive base";

    /**
     * Calculate the surface area of a cube.
     *
     * @param sideLength side length of cube
     * @return surface area of given cube
     */
    public static double surfaceAreaCube(final double sideLength) {
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return 6 * sideLength * sideLength;
    }

    /**
     * Calculate the surface area of a sphere.
     *
     * @param radius radius of sphere
     * @return surface area of given sphere
     */
    public static double surfaceAreaSphere(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 4 * Math.PI * radius * radius;
    }

    /**
     * Calculate the area of a rectangle.
     *
     * @param length length of a rectangle
     * @param width  width of a rectangle
     * @return area of given rectangle
     */
    public static double surfaceAreaRectangle(final double length, final double width) {
        if (length <= 0) {
            throw new IllegalArgumentException("Must be a positive length");
        }
        if (width <= 0) {
            throw new IllegalArgumentException("Must be a positive width");
        }
        return length * width;
    }

    /**
     * Calculate surface area of a cylinder.
     *
     * @param radius radius of the floor
     * @param height height of the cylinder.
     * @return volume of given cylinder
     */
    public static double surfaceAreaCylinder(final double radius, final double height) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return 2 * (Math.PI * radius * radius + Math.PI * radius * height);
    }

    /**
     * Calculate the area of a square.
     *
     * @param sideLength side length of square
     * @return area of given square
     */
    public static double surfaceAreaSquare(final double sideLength) {
        if (sideLength <= 0) {
            throw new IllegalArgumentException("Must be a positive sideLength");
        }
        return sideLength * sideLength;
    }

    /**
     * Calculate the area of a triangle.
     *
     * @param base   base of triangle
     * @param height height of triangle
     * @return area of given triangle
     */
    public static double surfaceAreaTriangle(final double base, final double height) {
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height / 2;
    }

    /**
     * Calculate the area of a parallelogram.
     *
     * @param base   base of a parallelogram
     * @param height height of a parallelogram
     * @return area of given parallelogram
     */
    public static double surfaceAreaParallelogram(final double base, final double height) {
        if (base <= 0) {
            throw new IllegalArgumentException(POSITIVE_BASE);
        }
        if (height <= 0) {
            throw new IllegalArgumentException(POSITIVE_HEIGHT);
        }
        return base * height;
    }

    /**
     * Calculate the area of a trapezium.
     *
     * @param base1  upper base of trapezium
     * @param base2  bottom base of trapezium
     * @param height height of trapezium
     * @return area of given trapezium
     */
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

    /**
     * Calculate the area of a circle.
     *
     * @param radius radius of circle
     * @return area of given circle
     */
    public static double surfaceAreaCircle(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return Math.PI * radius * radius;
    }

    /**
     * Calculate the surface area of a hemisphere.
     *
     * @param radius radius of hemisphere
     * @return surface area of given hemisphere
     */
    public static double surfaceAreaHemisphere(final double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException(POSITIVE_RADIUS);
        }
        return 3 * Math.PI * radius * radius;
    }

    /**
     * Calculate the surface area of a cone.
     *
     * @param radius radius of cone.
     * @param height of cone.
     * @return surface area of given cone.
     */
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
                double side = scanner.nextDouble();
                result = surfaceAreaCube(side);
                break;
            case 2:
                double radiusSphere = scanner.nextDouble();
                result = surfaceAreaSphere(radiusSphere);
                break;
            case 3:
                double length = scanner.nextDouble();
                double width = scanner.nextDouble();
                result = surfaceAreaRectangle(length, width);
                break;
            case 4:
                double radiusCylinder = scanner.nextDouble();
                double heightCylinder = scanner.nextDouble();
                result = surfaceAreaCylinder(radiusCylinder, heightCylinder);
                break;
            case 5:
                double sideSquare = scanner.nextDouble();
                result = surfaceAreaSquare(sideSquare);
                break;
            case 6:
                double baseTriangle = scanner.nextDouble();
                double heightTriangle = scanner.nextDouble();
                result = surfaceAreaTriangle(baseTriangle, heightTriangle);
                break;
            case 7:
                double baseParallelogram = scanner.nextDouble();
                double heightParallelogram = scanner.nextDouble();
                result = surfaceAreaParallelogram(baseParallelogram, heightParallelogram);
                break;
            case 8:
                double base1 = scanner.nextDouble();
                double base2 = scanner.nextDouble();
                double heightTrapezium = scanner.nextDouble();
                result = surfaceAreaTrapezium(base1, base2, heightTrapezium);
                break;
            case 9:
                double radiusCircle = scanner.nextDouble();
                result = surfaceAreaCircle(radiusCircle);
                break;
            case 10:
                double radiusHemisphere = scanner.nextDouble();
                result = surfaceAreaHemisphere(radiusHemisphere);
                break;
            case 11:
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
