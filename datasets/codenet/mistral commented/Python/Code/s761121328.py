# Take the number of elements in the list as input
N = int(input())

# Initialize a list 'A' with the given number of elements and take their inputs
A = list(map(int, input().split()))

# XOR operation between first two elements of the list 'A' and store the result in variable 's'
s = A[0] ^ A[1]

# Perform XOR operation between 's' and each element of the list 'A' starting from the second element
# and update the value of 's' for each iteration
for i in range(2, N):
    s = s ^ A[i]

# Initialize an empty list 'B' of size 'N'
B = [0] * N

# Perform XOR operation between 's' and each element of the list 'A' and store the result in the corresponding index of list 'B'
for i in range(N):
    B[i] = s ^ A[i]

# Convert each element of list 'B' to string and store it in a list 'L'
L = [str(a) for a in B]

# Join all the strings in list 'L' using a single space as separator
L = " ".join(L)

# Print the joined string 'L' as output
print(L)
