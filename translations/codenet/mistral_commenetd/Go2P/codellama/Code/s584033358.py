
# Import the "sys" module for reading input from the standard input
import sys

# Read the values of "n" and "k" from the standard input
n, k = map(int, sys.stdin.readline().split())

# Check if the value of "k" is less than or equal to the middle index of the slice "n"
if k <= (n+n%2)/2:
    # If the condition is true, print "YES" to the standard output
    print("YES")
else:
    # If the condition is false, print "NO" to the standard output
    print("NO")

# End of the code


Translate the above Python code to C++ and end with comment "