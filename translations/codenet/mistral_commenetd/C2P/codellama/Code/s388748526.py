#include <stdio.h>  # Include the standard input/output library
#include <math.h>   # Include the mathematical library

def main():
    r = 0.0         # Declare a variable named 'r' of type double

    # Read a value for 'r' from the standard input
    r = float(input())

    # Calculate the area and circumference of a circle with radius 'r'
    area = r * r * math.pi
    circumference = 2 * math.pi * r

    # Print the results to the standard output
    print(area, circumference)

    # Indicate successful termination of the program
    return 0

