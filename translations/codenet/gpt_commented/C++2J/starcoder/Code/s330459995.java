import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables for width (W), height (H), circle center coordinates (x, y), and radius (r)
        Scanner sc = new Scanner(System.in);
        int W, H, x, y, r;

        // Read input values for width, height, circle center coordinates, and radius
        W = sc.nextInt();
        H = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        r = sc.nextInt();

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
    }
}
