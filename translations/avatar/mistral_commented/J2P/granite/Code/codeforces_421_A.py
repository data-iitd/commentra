
# Import necessary modules
import sys

# Read input from the command line
n, a, b = map(int, sys.argv[1:])

# Create lists to store the input elements
list1 = list(map(int, sys.argv[2:a+2]))
list2 = list(map(int, sys.argv[a+2:a+b+2]))

# Iterate through the input array and print the corresponding number based on the presence of the element in list1
for i in range(n):
    if i+1 in list1: # Check if the current input element is present in list1
        print(1, end=" ") # If present, print 1
    else:
        print(2, end=" ") # If not present, print 2

# End the program
print("