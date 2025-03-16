import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define variables to store input coordinates
        long x1, x2, y1, y2;

        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read input coordinates from standard input
        x1 = scanner.nextLong();
        y1 = scanner.nextLong();
        x2 = scanner.nextLong();
        y2 = scanner.nextLong();

        // Calculate differences between final and initial coordinates
        final long dx = x2 - x1, dy = y2 - y1;

        // Calculate coordinates of points to the left and above, and right and below the final point
        long x3 = x2 - dy, y3 = y2 + dx;
        long x4 = x1 - dy, y4 = y1 + dx;

        // Print the calculated coordinates to the standard output
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

        // End the program with a return statement of 0
        return;
    }
}
