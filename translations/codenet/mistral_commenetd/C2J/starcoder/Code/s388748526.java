import java.util.Scanner;

public class Circle {
    public static void main(String[] args) {
        // Create a Scanner object for reading the standard input
        Scanner input = new Scanner(System.in);

        // Read a value for 'r' from the standard input
        double r = input.nextDouble();

        // Calculate the area and circumference of a circle with radius 'r'
        double area = r * r * Math.PI;
        double circumference = 2 * Math.PI * r;

        // Print the results to the standard output
        System.out.println(area + " " + circumference);
    }
}
