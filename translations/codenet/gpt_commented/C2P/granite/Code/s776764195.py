
import sys

# Read the entire input into the string
input_str = sys.stdin.read()

# Initialize variables
n = 0
A = []
B = []
p = 0

# Read the number of elements from the input
while input_str[p] >= '0' and input_str[p] <= '9':
    n = n * 10 + int(input_str[p])
    p += 1
p += 1

# Read each number into the array A
for i in range(1, n + 1):
    while input_str[p] >= '0' and input_str[p] <= '9':
        A.append(int(input_str[p]))
        p += 1
    p += 1

# Perform counting sort on the array A and store the result in B
k = 10001
C = [0] * (k + 1)
for j in range(1, n + 1):
    C[A[j]] += 1
for i in range(1, k + 1):
    C[i] += C[i - 1]
for j in range(n, 0, -1):
    B[C[A[j]]] - 1] = A[j]
    C[A[j]] -= 1

# Write the sorted numbers to the output string
output_str = ""
for i in range(1, n):
    output_str += str(B[i]) + " "
output_str += str(B[n])

# Output the final result
print(output_str)

