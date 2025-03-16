
# Import the necessary modules
import sys

# Create a function to read input from standard input
def read_input():
    return sys.stdin.readline().strip()

# Create a function to sort a list of integers
def sort_list(my_list):
    return sorted(my_list)

# Create a function to calculate the sum of a list of integers
def sum_list(my_list):
    return sum(my_list)

# Create a function to calculate the second largest integer from a list of integers
def second_largest(my_list):
    return my_list[len(my_list)-2]

# Create a function to calculate the sum of the second largest integer from each group of three
def calculate_sum(my_list):
    sum = 0
    for i in range(0, len(my_list), 3):
        sum += second_largest(sort_list(my_list[i:i+3]))
    return sum

# Read the number of groups of three integers
n = int(read_input())

# Initialize a list to hold 3*n integers
ar = []

# Populate the list with integers from input
for i in range(0, 3*n):
    ar.append(int(read_input()))

# Sort the list of integers in ascending order
ar = sort_list(ar)

# Calculate the sum of the second largest integer from each group of three
sum = calculate_sum(ar)

# Print the final computed sum
print(sum)

