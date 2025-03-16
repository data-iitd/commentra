
# 2018-07-29T20:36:21+0800
import sys # Import the sys module for standard input/output operations.

# Read a string input from the standard input and store it in the variable `s`.
s = sys.stdin.readline().strip()

# Replace all occurrences of the string "2017" in the string `s` with the string "2018".
s = s.replace("2017", "2018")

# Print the modified string to the standard output.
print("Modified string:", s)

# End of code.
