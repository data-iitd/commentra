# Import the sys module for standard input
import sys

# Read a value of type int from the standard input and store it in the variable "a"
a = int(sys.stdin.readline().strip())

# Calculate the result of the expression "a + a*a + a*a*a"
result = a + a * a + a * a * a

# Print the result to the standard output
print(result)

# End of code
# <END-OF-CODE>
