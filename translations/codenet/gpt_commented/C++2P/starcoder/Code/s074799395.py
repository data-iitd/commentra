# Include the input-output stream library
import sys

# Read a character input from the user
B = sys.stdin.read(1)

# Determine the output character based on the input character
if B == 'A':
    OUT = 'T'
elif B == 'T':
    OUT = 'A'
elif B == 'C':
    OUT = 'G'
else:
    OUT = 'C'

# Output the result to the console
print(OUT)

# 