# Read an integer N from input, which represents the number of elements in the list
N = int(input())

# Read a list of N integers from input
A = list(map(int, input().split()))

# Initialize variable s with the XOR of the first two elements of the list A
s = A[0] ^ A[1]

# Iterate through the rest of the elements in A and update s with the XOR of each element
for i in range(2, N):
    s = s ^ A[i]

# Create a new list B of the same size as A, initialized with zeros
B = [0] * N

# Populate list B by calculating the XOR of s with each element in A
for i in range(N):
    B[i] = s ^ A[i]

# Convert each integer in list B to a string for output formatting
L = [str(a) for a in B]

# Join the list of strings into a single space-separated string
L = " ".join(L)

# Print the resulting string
print(L)
