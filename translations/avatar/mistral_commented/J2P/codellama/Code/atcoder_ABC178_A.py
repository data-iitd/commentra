# Importing necessary Python libraries for this program
import sys

# Reading an integer value from the standard input
x = int(sys.stdin.readline())

# Determining a boolean value based on the condition x equals to 1
bool = x == 1

# Calculating the result based on the boolean value
result = 1 if not bool else 0

# Writing the result to the standard output
print(result)

# End of code
