# Ask the user for the number of elements in the list
N = int(input())

# Initialize a variable x with the value 1
x = 1

# Generate a list N_list containing the numbers from 1 to N
N_list = [x+1 for x in range(N)]

# Use the product function from the itertools module to generate all possible combinations of 3 elements from N_list
n = list(product(N_list, repeat=3))

# Calculate the length of the list n
m = len(n)

# Print the value of m
print(m)
