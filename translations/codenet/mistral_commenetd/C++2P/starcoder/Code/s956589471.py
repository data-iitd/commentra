
# Include the iostream library for input and output
# Include the vector library, but we don't use it here
# Include the string library, but we don't use it here
# Include the algorithm library, but we don't use it here
# Include the standard input and output library
# Include the string manipulation library
# Include the mathematical functions library
from sys import stdin, stdout # Import the standard input and output library
from math import ceil # Import the mathematical functions library

# Declare and initialize six integer variables
a, b, c, d, e, k = map(int, stdin.readline().split())

# Perform a simple condition check using the relational operator <=
if e - a <= k:
    stdout.write("Yay!\n") # If the condition is true, print "Yay!" to the standard output
else:
    stdout.write(":(\n") # If the condition is false, print ":" and a sad face "(" to the standard output

# Indicate that the program has finished running successfully
stdout.flush()

