public class CircleCalculator {
    public static void main(String[] args) {
        double r;  // Declare a variable to store the radius

        // Prompt the user to input the radius
        System.out.print("Enter the radius: ");
        java.util.Scanner scanner = new java.util.Scanner(System.in);  // Create a Scanner object
        r = scanner.nextDouble();  // Read the radius from user input

        // Calculate and print the area and circumference of the circle
        // Area = π * r^2
        // Circumference = 2 * π * r
        System.out.printf("%.6f %.6f\n", r * r * Math.PI, 2 * Math.PI * r);

        scanner.close();  // Close the scanner to free up resources
    }
}
