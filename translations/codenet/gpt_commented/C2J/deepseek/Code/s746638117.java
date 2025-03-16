public class RectangleCalculator {
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and results
        int a, b, ar, le;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the length and width from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the area of the rectangle (length * width)
        ar = a * b;

        // Calculate the perimeter of the rectangle (2 * (length + width))
        le = 2 * (a + b);

        // Output the calculated area and perimeter
        System.out.println(ar + " " + le);

        // Return 0 to indicate successful execution
        return 0;
    }
}
