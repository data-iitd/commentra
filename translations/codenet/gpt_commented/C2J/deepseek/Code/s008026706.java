public class RectangleCalculator {
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and results
        int a, b, x, y;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integer inputs from the user (representing dimensions)
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the perimeter of the rectangle (2 * (length + width))
        x = 2 * a + 2 * b;

        // Calculate the area of the rectangle (length * width)
        y = a * b;

        // Output the area and perimeter
        System.out.println(y + " " + x);

        // Return 0 to indicate successful execution
        return 0;
    }
}
