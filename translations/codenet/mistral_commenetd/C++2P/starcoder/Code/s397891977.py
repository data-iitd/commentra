
# Include the iostream library for input/output operations
# Include the vector container template for dynamic arrays
# Include the unordered_map container template for hash-based associative arrays
# Include the unordered_set container template for hash-based sets
# Include the algorithm library for various algorithms on sequences
# Include the limits library for constant definitions related to data types
# Include the cmath library for mathematical functions
# Include the map container template for associative arrays

# Use the standard namespace to avoid having to write "std::" before every standard library object or function
from sys import stdin, stdout # Include the standard input/output streams

# Declare an integer variable named "r"
r = 0

# Read the value of "r" from the standard input using cin
r = int(stdin.readline())

# Output the square of "r" to the standard output using cout and the << operator
stdout.write(str(r * r) + "\n")

# Use the endl manipulator to insert a newline character after the output

# The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
return 0

