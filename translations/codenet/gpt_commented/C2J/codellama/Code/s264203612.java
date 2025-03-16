#include <stdio.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables for radius, area, and circumference
        double r; // radius
        double s, l; // area and circumference
        double p = 3.141592653589; // value of pi

        // Read the radius from user input
        scanf("%lf", &r);
        
        // Calculate the area of the circle using the formula: area = π * r^2
        s = r * r * p;

        // Calculate the circumference of the circle using the formula: circumference = 2 * π * r
        l = 2 * p * r;
        
        // Print the calculated area and circumference
        printf("%f %f\n", s, l);
        
        return 0; // Indicate that the program ended successfully
    }
}

