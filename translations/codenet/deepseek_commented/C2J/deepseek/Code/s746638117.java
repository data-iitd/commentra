public class RectangleCalculator {
    public static void main(String[] args) {
        int a, b, ar, le; // Step 3: Declare integer variables a, b, ar, and le.
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 4: Create a Scanner object to read input.
        a = scanner.nextInt(); // Step 4: Read the first integer from the user.
        b = scanner.nextInt(); // Step 4: Read the second integer from the user.
        ar = a * b; // Step 5: Calculate the area of a rectangle (ar) by multiplying a and b.
        le = 2 * (a + b); // Step 6: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
        System.out.println(ar + " " + le); // Step 7: Print the area and perimeter.
    }
}
