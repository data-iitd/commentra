import java.util.Scanner;

public class Circle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double r;  // Declare a variable to store the radius

        // Prompt the user to input the radius
        System.out.print("Enter the radius: ");
        r = input.nextDouble();  // Read the radius from user input

        // Calculate and print the area and circumference of the circle
        // Area = π * r^2
        // Circumference = 2 * π * r
        System.out.printf("%.2f %.2f\n", r * r * Math.PI, 2 * Math.PI * r);
    }
}
