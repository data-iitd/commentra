import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        try {
            // Read the user's choice of shape
            int choice = scanner.nextInt();
            double volume = 0; // Variable to store the calculated volume

            // Switch statement to handle different shape volume calculations based on user choice
            switch (choice) {
                case 1: // Calculate volume of a cube
                    double side = scanner.nextDouble();
                    volume = volumeCube(side);
                    break;
                case 2: // Calculate volume of a cuboid
                    double width = scanner.nextDouble();
                    double height = scanner.nextDouble();
                    double length = scanner.nextDouble();
                    volume = volumeCuboid(width, height, length);
                    break;
                case 3: // Calculate volume of a sphere
                    double radius = scanner.nextDouble();
                    volume = volumeSphere(radius);
                    break;
                case 4: // Calculate volume of a cylinder
                    double radiusCyl = scanner.nextDouble();
                    double heightCyl = scanner.nextDouble();
                    volume = volumeCylinder(radiusCyl, heightCyl);
                    break;
                case 5: // Calculate volume of a hemisphere
                    double radiusHem = scanner.nextDouble();
                    volume = volumeHemisphere(radiusHem);
                    break;
                case 6: // Calculate volume of a cone
                    double radiusCone = scanner.nextDouble();
                    double heightCone = scanner.nextDouble();
                    volume = volumeCone(radiusCone, heightCone);
                    break;
                case 7: // Calculate volume of a prism
                    double baseAreaPrism = scanner.nextDouble();
                    double heightPrism = scanner.nextDouble();
                    volume = volumePrism(baseAreaPrism, heightPrism);
                    break;
                case 8: // Calculate volume of a pyramid
                    double baseAreaPyr = scanner.nextDouble();
                    double heightPyr = scanner.nextDouble();
                    volume = volumePyramid(baseAreaPyr, heightPyr);
                    break;
                case 9: // Calculate volume of a frustum of a cone
                    double r1 = scanner.nextDouble();
                    double r2 = scanner.nextDouble();
                    double heightFrustum = scanner.nextDouble();
                    volume = volumeFrustumOfCone(r1, r2, heightFrustum);
                    break;
                default: // Exit if the choice is not valid
                    return; 
            }

            // Print the calculated volume formatted to two decimal places
            System.out.printf("%.2f%n", volume);
        } catch (Exception e) {
            // Handle any exceptions that occur during input or calculation
            System.out.println("Error: " + e.getMessage());
        } finally {
            // Close the scanner to free up resources
            scanner.close();
        }
    }

    // Method to calculate the volume of a cube
    public static double volumeCube(double sideLength) {
        return sideLength * sideLength * sideLength;
    }

    // Method to calculate the volume of a cuboid
    public static double volumeCuboid(double width, double height, double length) {
        return width * height * length;
    }

    // Method to calculate the volume of a sphere
    public static double volumeSphere(double radius) {
        return (4 * Math.PI * radius * radius * radius) / 3;
    }

    // Method to calculate the volume of a cylinder
    public static double volumeCylinder(double radius, double height) {
        return Math.PI * radius * radius * height;
    }

    // Method to calculate the volume of a hemisphere
    public static double volumeHemisphere(double radius) {
        return (2 * Math.PI * radius * radius * radius) / 3;
    }

    // Method to calculate the volume of a cone
    public static double volumeCone(double radius, double height) {
        return (Math.PI * radius * radius * height) / 3;
    }

    // Method to calculate the volume of a prism
    public static double volumePrism(double baseArea, double height) {
        return baseArea * height;
    }

    // Method to calculate the volume of a pyramid
    public static double volumePyramid(double baseArea, double height) {
        return (baseArea * height) / 3;
    }

    // Method to calculate the volume of a frustum of a cone
    public static double volumeFrustumOfCone(double r1, double r2, double height) {
        return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2);
    }
}
