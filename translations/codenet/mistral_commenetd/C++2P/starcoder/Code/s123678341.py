
# Initialize input variables
X, Y, Z, K = map(int, input().split()) # Number of elements in vectors A, B, C and the limit for output

# Initialize vectors A, B, and C
A = [0] * X # A vector of size X, initialized with zeroes
B = [0] * Y # B vector of size Y, initialized with zeroes
C = [0] * Z # C vector of size Z, initialized with zeroes

# Read input values for vectors A, B, and C from standard input
for i in range(X):
    A[i] = int(input()) # Read each element of vector A
for i in range(Y):
    B[i] = int(input()) # Read each element of vector B
for i in range(Z):
    C[i] = int(input()) # Read each element of vector C

# Sort vectors A, B, and C in descending order
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

# Create a new vector AB by adding each element of A to each element of B
AB = []
for i in range(X):
    for j in range(Y):
        AB.append(A[i] + B[j]) # Add A[i] and B[j] and push the sum into vector AB

# Sort vector AB in descending order
AB.sort(reverse=True)

# Create a new vector ABC by adding each element of AB to each element of C
ABC = []
for i in range(min(K, len(AB))):
    for j in range(Z):
        ABC.append(AB[i] + C[j]) # Add AB[i] and C[j] and push the sum into vector ABC

# Sort vector ABC in descending order
ABC.sort(reverse=True)

# Print K smallest elements of vector ABC
for i in range(K):
    print(ABC[i]) # Print each element of vector ABC

# Main function ends here
