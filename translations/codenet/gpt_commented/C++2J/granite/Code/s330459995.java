
import java.util.Scanner;

public class s330459995{
    public static void main(String[] args) {
        // Declare variables for width (W), height (H), circle center coordinates (x, y), and radius (r)
        int W, H, x, y, r;

        // Create a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);

        // Read input values for width, height, circle center coordinates, and radius
        W = scanner.nextInt();
        H = scanner.nextInt();
        x = scanner.nextInt();
        y = scanner.nextInt();
        r = scanner.nextInt();

        // Check if the circle is out of bounds on any side
        if (x - r < 0 || x + r > W || y - r < 0 || y + r > H) {
            // If the circle exceeds the boundaries, print "No"
            System.out.println("No");
        }
        // Check if the circle is completely within the bounds
        else if (x - r >= 0 && x + r <= W && y - r >= 0 && y + r <= H) {
            // If the circle is completely within the boundaries, print "Yes"
            System.out.println("Yes");
        }

        // Close the Scanner object
        scanner.close();
    }
}
