#include <stdio.h>

int main() {
    # Declare variables for radius, area, and circumference
    r = 0.0 # radius
    s = 0.0 # area
    l = 0.0 # circumference
    p = 3.141592653589 # value of pi

    # Read the radius from user input
    r = float(input())
    
    # Calculate the area of the circle using the formula: area = π * r^2
    s = r * r * p

    # Calculate the circumference of the circle using the formula: circumference = 2 * π * r
    l = 2 * p * r
    
    # Print the calculated area and circumference
    print(s, l)
    
    return 0 # Indicate that the program ended successfully
}
