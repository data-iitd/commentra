# Importing sys module and assigning stdin.readline() to input variable
import sys
input = sys.stdin.readline

# Taking input as integers and storing them in variables a and b
a, b = map(int, input().split())

# Checking if a is greater than or equal to 13
if a >= 13:
    # If yes, print the value of b
    print(b)
# If a is less than 13, check if it is greater than or equal to 6
elif a >= 6:
    # If yes, calculate integer division of b by 2 and print the result
    print(int(b/2))
# If a is less than 6, print 0
else:
    # Printing 0
    print(0)
