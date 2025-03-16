
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the coordinates of two points
        int x1, y1, x2, y2;

        // Read the coordinates of the two points from standard input
        Scanner scanner = new Scanner(System.in);
        x1 = scanner.nextInt();
        y1 = scanner.nextInt();
        x2 = scanner.nextInt();
        y2 = scanner.nextInt();

        // Calculate the differences in x and y coordinates
        int a = x2 - x1; // Difference in x-coordinates
        int b = y2 - y1; // Difference in y-coordinates

        // Calculate the coordinates of the two new points that form a rectangle
        int x3 = x2 - b; // x-coordinate of the third point
        int y3 = y2 + a; // y-coordinate of the third point
        int x4 = x1 - b; // x-coordinate of the fourth point
        int y4 = y1 + a; // y-coordinate of the fourth point

        // Output the coordinates of the two new points
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

