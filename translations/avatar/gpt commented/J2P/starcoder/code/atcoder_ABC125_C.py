import sys

# Array to hold the input integers
A = []

# Read the number of elements
N = int(sys.stdin.readline())

# Read N integers from input and store them in array A
for i in range(N):
    A.append(int(sys.stdin.readline()))

# Arrays to hold the GCD values from the left and right
M = [0] * N # Not used in the code, can be removed
L = [0] * N # GCD values from the left
R = [0] * N # GCD values from the right

# Initialize the first element of L with the first element of A
L[0] = A[0]

# Calculate GCD from the left side
for i in range(1, N):
    L[i] = gcd(L[i - 1], A[i])

# Initialize the last element of R with the last element of A
R[N - 1] = A[N - 1]

# Calculate GCD from the right side
for i in range(N - 2, -1, -1):
    R[i] = gcd(R[i + 1], A[i])

# Calculate the maximum GCD excluding the last element
answer = max(L[N - 2], R[1])

# Iterate through the array to find the maximum GCD excluding the current element
for i in range(1, N - 1):
    answer = max(answer, gcd(L[i - 1], R[i + 1]))

# Print the final answer
print(answer)

# Method to calculate the GCD of two integers using the Euclidean algorithm
def gcd(a, b):
    # Ensure a is greater than or equal to b
    if b > a:
        tmp = a
        a = b
        b = tmp
    
    # If b is zero, return a as the GCD
    if b == 0:
        return a
    
    # Calculate GCD using the Euclidean algorithm
    r = -1
    while r!= 0:
        r = a % b
        a = b
        b = r
    
    # Return the GCD
    return a

