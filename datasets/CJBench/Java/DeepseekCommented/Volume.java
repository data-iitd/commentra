import java.util.Scanner;

public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int choice = scanner.nextInt(); // Read user's choice
            double volume = 0; // Initialize volume variable

            // Switch case to determine the shape and calculate its volume
            switch (choice) {
                case 1:
                    double side = scanner.nextDouble(); // Read side length for cube
                    volume = volumeCube(side); // Calculate volume of cube
                    break;
                case 2:
                    double width = scanner.nextDouble(); // Read width for cuboid
                    double heightCuboid = scanner.nextDouble(); // Read height for cuboid
                    double length = scanner.nextDouble(); // Read length for cuboid
                    volume = volumeCuboid(width, heightCuboid, length); // Calculate volume of cuboid
                    break;
                case 3:
                    double radius = scanner.nextDouble(); // Read radius for sphere
                    volume = volumeSphere(radius); // Calculate volume of sphere
                    break;
                case 4:
                    double radiusCyl = scanner.nextDouble(); // Read radius for cylinder
                    double heightCyl = scanner.nextDouble(); // Read height for cylinder
                    volume = volumeCylinder(radiusCyl, heightCyl); // Calculate volume of cylinder
                    break;
                case 5:
                    double radiusHem = scanner.nextDouble(); // Read radius for hemisphere
                    volume = volumeHemisphere(radiusHem); // Calculate volume of hemisphere
                    break;
                case 6:
                    double radiusCone = scanner.nextDouble(); // Read radius for cone
                    double heightCone = scanner.nextDouble(); // Read height for cone
                    volume = volumeCone(radiusCone, heightCone); // Calculate volume of cone
                    break;
                case 7:
                    double baseAreaPrism = scanner.nextDouble(); // Read base area for prism
                    double heightPrism = scanner.nextDouble(); // Read height for prism
                    volume = volumePrism(baseAreaPrism, heightPrism); // Calculate volume of prism
                    break;
                case 8:
                    double baseAreaPyr = scanner.nextDouble(); // Read base area for pyramid
                    double heightPyr = scanner.nextDouble(); // Read height for pyramid
                    volume = volumePyramid(baseAreaPyr, heightPyr); // Calculate volume of pyramid
                    break;
                case 9:
                    double r1 = scanner.nextDouble(); // Read radius of smaller base for frustum
                    double r2 = scanner.nextDouble(); // Read radius of larger base for frustum
                    double heightFrustum = scanner.nextDouble(); // Read height for frustum
                    volume = volumeFrustumOfCone(r1, r2, heightFrustum); // Calculate volume of frustum of cone
                    break;
                default:
                    return; // Exit if choice is not recognized
            }
            System.out.printf("%.2f%n", volume); // Print the calculated volume with two decimal places
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage()); // Handle errors and display error message
        } finally {
            scanner.close(); // Close the scanner to free up resources
        }
    }

    // Methods to calculate the volume of different shapes
    public static double volumeCube(double sideLength) {
        return sideLength * sideLength * sideLength; // Volume of cube formula
    }

    public static double volumeCuboid(double width, double height, double length) {
        return width * height * length; // Volume of cuboid formula
    }

    public static double volumeSphere(double radius) {
        return (4 * Math.PI * radius * radius * radius) / 3; // Volume of sphere formula
    }

    public static double volumeCylinder(double radius, double height) {
        return Math.PI * radius * radius * height; // Volume of cylinder formula
    }

    public static double volumeHemisphere(double radius) {
        return (2 * Math.PI * radius * radius * radius) / 3; // Volume of hemisphere formula
    }

    public static double volumeCone(double radius, double height) {
        return (Math.PI * radius * radius * height) / 3; // Volume of cone formula
    }

    public static double volumePrism(double baseArea, double height) {
        return baseArea * height; // Volume of prism formula
    }

    public static double volumePyramid(double baseArea, double height) {
        return (baseArea * height) / 3; // Volume of pyramid formula
    }

    public static double volumeFrustumOfCone(double r1, double r2, double height) {
        return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2); // Volume of frustum of cone formula
    }
}
