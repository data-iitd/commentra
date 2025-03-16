#include <stdio.h>

# Declare variables to hold the dimensions and calculated values
a, b, mawari, menseki = 0, 0, 0, 0

# Read two integer inputs from the user representing the dimensions
a, b = input("Enter the dimensions of the rectangle: ").split()

# Calculate the perimeter (mawari) of the rectangle
mawari = 2 * (int(a) + int(b))

# Calculate the area (menseki) of the rectangle
menseki = int(a) * int(b)

# Print the area and perimeter to the console
print("The area of the rectangle is: ", menseki)
print("The perimeter of the rectangle is: ", mawari)

# Return 0 to indicate successful completion of the program
return 0

