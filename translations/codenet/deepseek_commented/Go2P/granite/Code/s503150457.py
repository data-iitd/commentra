
import sys

# Read input values for s1, s2, and s3 from the standard input
s1, s2, s3 = sys.stdin.read().split()

# Print the uppercase version of the first character of each input string
print(s1[0].upper() + s2[0].upper() + s3[0].upper())
