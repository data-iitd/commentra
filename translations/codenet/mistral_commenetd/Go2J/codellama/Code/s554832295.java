// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare four variables of type int to store the x and y coordinates of two points
        int x1, y1, x2, y2;

        // Use the "Scanner" class to read the values of x1, y1, x2, and y2 from the standard input
        Scanner scanner = new Scanner(System.in);
        x1 = scanner.nextInt();
        y1 = scanner.nextInt();
        x2 = scanner.nextInt();
        y2 = scanner.nextInt();

        // Calculate the differences between the x and y coordinates of the second point and the first point
        int a = x2 - x1;
        int b = y2 - y1;

        // Calculate the new x and y coordinates of the first point and the second point based on the values of a and b
        int x3 = x2 - b;
        int y3 = y2 + a;
        int x4 = x1 - b;
        int y4 = y1 + a;

        // Print the new x and y coordinates of the first and second points using the "System.out.println" method
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);

    }

}

