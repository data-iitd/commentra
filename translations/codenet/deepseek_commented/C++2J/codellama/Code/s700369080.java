import java.util.Scanner; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        long x1 = sc.nextLong(); // Read the first long integer
        long y1 = sc.nextLong(); // Read the second long integer
        long x2 = sc.nextLong(); // Read the third long integer
        long y2 = sc.nextLong(); // Read the fourth long integer

        // Calculate the differences between the coordinates
        long dx = x2 - x1;
        long dy = y2 - y1;

        // Compute the new coordinates based on the differences
        long x3 = x2 - dy;
        long y3 = y2 + dx;
        long x4 = x1 - dy;
        long y4 = y1 + dx;

        // Output the new coordinates
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

