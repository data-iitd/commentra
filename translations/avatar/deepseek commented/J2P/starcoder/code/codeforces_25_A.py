
# Importing the Scanner class for input
import java.util.Scanner;

# Creating a Scanner object to read input
ob = java.util.Scanner(System.in);

# Reading the number of elements in the array
n = ob.nextInt();

# Initializing an array of size n+1
array = [0] * (n + 1);

# Populating the array with integers from the user input
for i in range(1, n + 1):
    array[i] = ob.nextInt();

# Initializing variables to count odd and even numbers and their indices
odd = 0;
even = 0;
odd_ind = 0;
even_ind = 0;

# Counting the number of odd and even numbers and recording their indices
for i in range(1, n + 1):
    if array[i] % 2 == 0:
        even += 1;
        even_ind = i;
    else:
        odd += 1;
        odd_ind = i;

# Comparing the counts of odd and even numbers and printing the index of the majority
if odd > even:
    print(even_ind);
else:
    print(odd_ind);

# 