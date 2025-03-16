
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read input from the user

        try {
            int choice = scanner.nextInt(); // Read an integer input from the user

            double volume = 0; // Initialize the volume variable to 0

            // Switch statement to determine the volume of different shapes based on user input
            switch (choice) {
                case 1:
                    double side = scanner.nextDouble(); // Read a double input for the side length of a cube
                    volume = volumeCube(side); // Calculate the volume of a cube using the volumeCube method
                    break;
                case 2:
                    double width = scanner.nextDouble(); // Read double inputs for the width, height, and length of a cuboid
                    double height = scanner.nextDouble();
                    volume = volumeCuboid(width, height, length); // Calculate the volume of a cuboid using the volumeCuboid method
                    break;
                case 3:
                    double radius = scanner.nextDouble(); // Read a double input for the radius of a sphere
                    volume = volumeSphere(radius); // Calculate the volume of a sphere using the volumeSphere method
                    break;
                case 4:
                    double radiusCyl = scanner.nextDouble(); // Read a double input for the radius of a cylinder
                    double heightCyl = scanner.nextDouble();
                    volume = volumeCylinder(radiusCyl, heightCyl); // Calculate the volume of a cylinder using the volumeCylinder method
                    break;
                case 5:
                    double radiusHem = scanner.nextDouble(); // Read a double input for the radius of a hemisphere
                    volume = volumeHemisphere(radiusHem); // Calculate the volume of a hemisphere using the volumeHemisphere method
                    break;
                case 6:
                    double radiusCone = scanner.nextDouble(); // Read a double input for the radius of a cone
                    double heightCone = scanner.nextDouble();
                    volume = volumeCone(radiusCone, heightCone); // Calculate the volume of a cone using the volumeCone method
                    break;
                case 7:
                    double baseAreaPrism = scanner.nextDouble(); // Read a double input for the base area of a prism
                    double heightPrism = scanner.nextDouble();
                    volume = volumePrism(baseAreaPrism, heightPrism); // Calculate the volume of a prism using the volumePrism method
                    break;
                case 8:
                    double baseAreaPyr = scanner.nextDouble(); // Read a double input for the base area of a pyramid
                    double heightPyr = scanner.nextDouble();
                    volume = volumePyramid(baseAreaPyr, heightPyr); // Calculate the volume of a pyramid using the volumePyramid method
                    break;
                case 9:
                    double r1 = scanner.nextDouble(); // Read double inputs for the radii and height of a frustum of a cone
                    double r2 = scanner.nextDouble();
                    double heightFrustum = scanner.nextDouble();
                    volume = volumeFrustumOfCone(r1, r2, heightFrustum); // Calculate the volume of a frustum of a cone using the volumeFrustumOfCone method
                    break;
                default:
                    return; // Exit the program if the user enters an invalid choice
            }

            System.out.printf("%.2f%n", volume); // Print the calculated volume with 2 decimal places

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage()); // Print an error message if an exception occurs
        } finally {
            scanner.close(); // Close the Scanner object to free up system resources
        }
    }

    // Methods to calculate the volumes of different shapes
    public static double volumeCube(double sideLength) {
        return sideLength * sideLength * sideLength; // Calculate the volume of a cube by cubing the side length
    }

    public static double volumeCuboid(double width, double height, double length) {
        return width * height * length; // Calculate the volume of a cuboid by multiplying the width, height, and length
    }

    public static double volumeSphere(double radius) {
        return (4 * Math.PI * radius * radius * radius) / 3; // Calculate the volume of a sphere using the given formula
    }

    public static double volumeCylinder(double radius, double height) {
        return Math.PI * radius * radius * height; // Calculate the volume of a cylinder by multiplying the area of the base and height
    }

    public static double volumeHemisphere(double radius) {
        return (2 * Math.PI * radius * radius * radius) / 3; // Calculate the volume of a hemisphere using the given formula
    }

    public static double volumeCone(double radius, double height) {
        return (Math.PI * radius * radius * height) / 3; // Calculate the volume of a cone using the given formula
    }

    public static double volumePrism(double baseArea, double height) {
        return baseArea * height; // Calculate the volume of a prism by multiplying the base area and height
    }

    public static double volumePyramid(double baseArea, double height) {
        return (baseArea * height) / 3; // Calculate the volume of a pyramid by dividing the product of the base area and height by 3
    }

    public static double volumeFrustumOfCone(double r1, double r2, double height) {
        return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2); // Calculate the volume of a frustum of a cone using the given formula
    }