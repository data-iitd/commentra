
import sys

# Read the input from the command line argument
S = int(sys.argv[1])

# Print the hours, minutes, and seconds of the given number of seconds
print(f"{S // 3600}:{(S % 3600) // 60}:{S % 60}")

# End of the Python code
# 