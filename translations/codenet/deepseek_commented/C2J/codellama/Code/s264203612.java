#include <stdio.h>

public class Main {
    public static void main(String[] args) {
        // Step 2: Declare variables to store the radius, area, and circumference of the circle.
        double r;
        double s, l;
        
        // Step 4: Initialize the value of π (pi) to a constant.
        double p = 3.141592653589;
        
        // Step 5: Read the radius from the user.
        scanf("%lf", &r);
        
        // Step 6: Calculate the area of the circle using the formula: area = π * radius^2.
        s = r * r * p;
        
        // Step 7: Calculate the circumference of the circle using the formula: circumference = 2 * π * radius.
        l = 2 * p * r;
        
        // Step 8: Print the area and circumference of the circle.
        printf("%f %f\n", s, l);
        
        // Step 9: Return 0 to indicate successful execution of the program.
        return 0;
    }
}

