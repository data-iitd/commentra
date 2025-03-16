
# Importing the utility package for using Scanner and Arrays
from java.util import *

# Importing static methods from the Math class
from static java.lang.Math import *

# Creating a Scanner object to read input from the console
sc = Scanner(System.in)

# Reading the integer n which determines the size of the array
n = sc.nextInt()

# Initializing an array of size 3*n to hold the input values
array = [0] * (3 * n)

# Filling the array with user input values
for i in range(len(array)):
    array[i] = sc.nextInt()

# Sorting the array in ascending order
Arrays.sort(array)

# Setting the head pointer to the second last element of the sorted array
head = len(array) - 2

# Initializing a variable to accumulate the result
res = 0

# Looping n times to sum up the required elements from the sorted array
for i in range(n):
    res += array[head] # Adding the current element pointed by head to the result
    head -= 2 # Moving the head pointer two positions to the left for the next iteration

# Printing the final result
print(res)

