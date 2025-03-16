import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare integer variables to hold the input values and results
        int a, b, c, d;

        // Read two integer values from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate the area of a rectangle (length * width)
        c = a * b;

        // Calculate the perimeter of a rectangle (2 * (length + width))
        d = 2 * a + 2 * b;

        // Output the calculated area and perimeter
        System.out.println(c + " " + d);
    }
}
