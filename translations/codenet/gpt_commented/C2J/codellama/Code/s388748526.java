#include <stdio.h>  // Include standard input-output library
#include <math.h>   // Include math library for mathematical constants and functions

public class Main {
    public static void main(String[] args) {
        double r;  // Declare a variable to store the radius

        // Prompt the user to input the radius
        System.out.print("Enter the radius: ");
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextDouble();  // Read the radius from user input

        // Calculate and print the area and circumference of the circle
        // Area = π * r^2
        // Circumference = 2 * π * r
        System.out.println(r * r * Math.PI + " " + 2 * Math.PI * r);
    }
}

