# Import the Scanner class for user input
import java.util.Scanner;

# Create a Scanner object to read input from the user
in = java.util.Scanner(System.in);

# Declare variables to hold the input values
x, y, a, b;

# Read four integers from the user
x = in.nextInt(); # Upper limit for the first variable
y = in.nextInt(); # Upper limit for the second variable
a = in.nextInt(); # Lower limit for the first variable
b = in.nextInt(); # Lower limit for the second variable

# Initialize a counter to keep track of valid pairs
count = 0;

# First nested loop to iterate through the range [a, x]
for i in range(a, x + 1):
    # Second nested loop to iterate through the range [b, y]
    for j in range(b, y + 1):
        # Skip the iteration if i is less than or equal to j
        if i <= j: continue;
        
        # Increment the count for each valid pair (i, j)
        count += 1;

# Output the total count of valid pairs
print(count);

# Second set of nested loops to print the valid pairs
for i in range(a, x + 1):
    for j in range(b, y + 1):
        # Skip the iteration if i is less than or equal to j
        if i <= j: continue;
        
        # Print the valid pair (i, j)
        print(i, j);

# Close the Scanner object to free resources
in.close();

