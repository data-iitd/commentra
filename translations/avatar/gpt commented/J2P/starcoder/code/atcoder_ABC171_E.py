
# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of elements in the array
n = sc.nextInt()

# Initialize an array to hold the input integers
a = [0] * n

# Variable to hold the cumulative XOR of all elements
r = 0

# Read each integer from input and compute the cumulative XOR
for i in range(n):
    a[i] = sc.nextInt()
    r ^= a[i] # Update the cumulative XOR with the current element

# For each element in the array, print the result of XORing the cumulative XOR with the element
for i in range(n):
    if i!= 0:
        print(" ", end="") # Print a space before the next number if it's not the first element
    print(r ^ a[i]) # Print the result of XORing the cumulative XOR with the current element

# 