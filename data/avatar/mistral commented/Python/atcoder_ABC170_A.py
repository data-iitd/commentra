
# Import the map function from the itertools module
import itertools as it

# Read a list of space-separated integers as input from the standard input
# and convert each integer to its corresponding Python integer type using the int() function
a = list(map(int, input().split()))

# Iterate over the elements of the list a using the enumerate() function
# which returns a tuple containing the index and the value of each element
for index, value in enumerate(a):
    # Check if the current value is equal to zero
    if value == 0:
        # Print the index of the first zero to the standard output
        print(index + 1)
        # Terminate the loop using the break statement
        break