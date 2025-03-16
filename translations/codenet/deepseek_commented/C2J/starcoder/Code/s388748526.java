import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Read the input value for the radius of the circle
        double r = sc.nextDouble();

        // Calculate the area of the circle (πr^2) and the circumference (2πr)
        double area = r * r * Math.PI;
        double circumference = 2 * Math.PI * r;

        // Print the results to the standard output
        System.out.println(area + " " + circumference);
    }
}
