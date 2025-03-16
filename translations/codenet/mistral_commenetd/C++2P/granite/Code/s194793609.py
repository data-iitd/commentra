

n = int(input()) # Read the number of elements in the vector 'a'
a = [0] * n # Initialize a vector 'a' of size 'n' and fill it with zeros
for i in range(n):
    a[i] = int(input()) # Read the elements of the vector 'a' from the standard input
abs_a = a[:] # Create a copy of the vector 'a' named 'abs_a' to store the absolute values of its elements
for i in range(n):
    if abs_a[i] < 0: # Check if the current element is negative
        abs_a[i] = -abs_a[i] # Make it positive by negating it
ans = sum(abs_a) # Initialize the variable 'ans' with the sum of the absolute values of the elements in 'abs_a'
min_val = min(abs_a) # Initialize the variable'min' with the minimum value in 'abs_a'
num_negative = sum(1 for e in a if e < 0) # Count the number of negative elements in the vector 'a'
if num_negative % 2: # Check if the number of negative elements is odd
    ans -= min_val * 2 # Subtract twice the minimum if the number of negative elements is odd
print(ans) # Print the final answer 'ans' to the standard output
