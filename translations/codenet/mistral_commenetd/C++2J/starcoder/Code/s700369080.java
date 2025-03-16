
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Define variables to store input coordinates
        long x1, x2, y1, y2;

        // Read input coordinates from standard input
        Scanner sc = new Scanner(System.in);
        x1 = sc.nextLong();
        y1 = sc.nextLong();
        x2 = sc.nextLong();
        y2 = sc.nextLong();

        // Calculate differences between final and initial coordinates
        long dx = x2 - x1, dy = y2 - y1;

        // Calculate coordinates of points to the left and above, and right and below the final point
        long x3 = x2 - dy, y3 = y2 + dx;
        long x4 = x1 - dy, y4 = y1 + dx;

        // Print the calculated coordinates to the standard output
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

        // End the program with a return statement of 0
        return 0;
    }
}

