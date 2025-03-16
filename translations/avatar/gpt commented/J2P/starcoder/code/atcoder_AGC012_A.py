
# Importing the utility package for using Scanner and Arrays
import java.util.*;
import static java.lang.Math.*;

# Creating a Scanner object to read input from the console
sc = Scanner(System.in);

# Reading the integer n which determines the size of the array
n = sc.nextInt();

# Initializing an array of size 3*n to hold the input values
array = new int[3 * n];

# Filling the array with user input values
for i in range(0, array.length):
    array[i] = sc.nextInt();

# Sorting the array in ascending order
Arrays.sort(array);

# Setting the head pointer to the second last element of the sorted array
head = array.length - 2;

# Initializing a variable to accumulate the result
res = 0;

# Looping n times to sum up the required elements from the sorted array
for i in range(0, n):
    res += array[head]; # Adding the current element pointed by head to the result
    head -= 2; # Moving the head pointer two positions to the left for the next iteration

# Printing the final result
print(res);

