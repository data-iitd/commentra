import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the dimensions and results
        int a, b, ar, le;

        // Read the length and width from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate the area of the rectangle (length * width)
        ar = a * b;

        // Calculate the perimeter of the rectangle (2 * (length + width))
        le = 2 * (a + b);

        // Output the calculated area and perimeter
        System.out.println(ar + " " + le);
    }
}
