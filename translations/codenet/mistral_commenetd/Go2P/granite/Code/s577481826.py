
# Importing required packages
import sys

# Reading the first integer 'a' from stdin
a = int(sys.stdin.readline())

# Reading the second integer 'b' from stdin
b = int(sys.stdin.readline())

# Calculating the sum of 'a' and 'b'
ret = a + b

# Checking if the sum is less than the difference of 'a' and 'b'
if ret < (a - b):
    # If true, then update the value of'ret'
    ret = a - b

# Checking if the sum is less than the product of 'a' and 'b'
if ret < (a * b):
    # If true, then update the value of'ret'
    ret = a * b

# Printing the final value of'ret'
print(ret)

# End of the code
