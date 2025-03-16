# Step 1: Import necessary modules
import sys  # For input operations

# Step 2: Read input values
a, b, c, d = map(int, sys.stdin.readline().split())  # Read four integer values from the user

# Step 3: Perform calculations
area = (a - c) * (b - d)  # Calculate the area of the rectangle using the given coordinates

# Step 4: Output the result
print(area)  # Print the calculated area to the console

# <END-OF-CODE>
