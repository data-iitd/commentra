# Read the number of elements in the array
n = int(input())

# Initialize a list to hold the input integers
a = []

# Variable to hold the cumulative XOR of all elements
r = 0

# Read each integer from input and compute the cumulative XOR
for _ in range(n):
    num = int(input())
    a.append(num)
    r ^= num  # Update the cumulative XOR with the current element

# For each element in the array, print the result of XORing the cumulative XOR with the element
for i in range(n):
    if i != 0:
        print(" ", end="")  # Print a space before the next number if it's not the first element
    print(r ^ a[i], end="")  # Print the result of XORing the cumulative XOR with the current element

# End of code
# <END-OF-CODE>
