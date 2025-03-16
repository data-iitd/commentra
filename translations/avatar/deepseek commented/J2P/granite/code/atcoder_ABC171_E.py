

n = int(input()) # Read the number of elements (n) from the user
a = list(map(int, input().split())) # Read the elements of the array 'a' from the user and convert them to integers
r = 0 # Initialize a variable 'r' to store the result of XOR operation

# Perform XOR operation on each element of the array 'a' and store the result in the variable 'r'
for i in range(n):
    r ^= a[i]

# Print the result of XOR operation for each element in the array 'a'
print(*[r ^ a[i] for i in range(n)]) # Print the result of XOR operation for each element in the array 'a'

