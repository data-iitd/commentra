
# Include the necessary header file
# This header file contains the definition of the map function

# Take three integers as input from the user
# Use the scanf function to read the input values

// Iterate through the range of numbers from 2 to 11 (12 is excluded)
for (int i = 2; i < 12; i++) {
    // Calculate the expression and print the integer result
    // Use the printf function to print the result
    printf("%d\n", (int)round((pow(r, i - 1) * (x + D / (1 - r))) - (D / (1 - r))));
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)


Translate the above C code to Java and end with comment "