# Import the necessary module
import sys

# Read an integer `n` and a string `s` from the standard input
n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()

# Print the number of occurrences of the substring "ABC" in the string `s`
print(s.count("ABC"))

# <END-OF-CODE>
