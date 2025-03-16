#include <stdio.h>  // Include the standard input/output library
#include <math.h>   // Include the mathematical library

public class Main {
    public static void main(String[] args) {
        double r;          // Declare a variable named 'r' of type double

        // Read a value for 'r' from the standard input
        scanf("%lf", &r);

        // Calculate the area and circumference of a circle with radius 'r'
        double area = r * r * M_PI;
        double circumference = 2 * M_PI * r;

        // Print the results to the standard output
        printf("%lf %lf\n", area, circumference);

        // Indicate successful termination of the program
        return 0;
    }
}

