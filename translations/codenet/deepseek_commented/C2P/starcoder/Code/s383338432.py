# Include the standard input-output library for printf and scanf
import sys

# Read the height and width from the user input
height = int(sys.stdin.readline())
width = int(sys.stdin.readline())

# Print the top border of the output
for i in range(width + 2):
    print("#", end="")
print()

# Read and print each line of input with borders
for i in range(height):
    input_str = sys.stdin.readline()
    print("#" + input_str.strip() + "#")

# Print the bottom border of the output
for i in range(width + 2):
    print("#", end="")
print()

# 