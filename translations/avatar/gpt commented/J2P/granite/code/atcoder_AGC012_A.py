
import sys # Importing the sys module to use the exit() function

# Reading the integer n which determines the size of the array
n = int(input())

# Initializing an empty list to hold the input values
array = []

# Filling the array with user input values
for _ in range(3 * n):
    array.append(int(input()))

# Sorting the array in ascending order
array.sort()

# Setting the head pointer to the second last element of the sorted array
head = len(array) - 2

# Initializing a variable to accumulate the result
res = 0

# Looping n times to sum up the required elements from the sorted array
for _ in range(n):
    res += array[head] # Adding the current element pointed by head to the result
    head -= 2 # Moving the head pointer two positions to the left for the next iteration

# Printing the final result
print(res)

# Ending the program
sys.exit(0)

END-OF-CODE