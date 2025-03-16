# Read the number of test cases
N = int(input())

# Read the array V of size N
V = input().split()
# Convert each element of V to an integer
V = [int(i) for i in V]

# Read the array C of size N
C = input().split()
# Convert each element of C to an integer
C = [int(i) for i in C]

# Initialize an empty list to store the differences between V and C
list = []

# Initialize variables to store the current difference and the sum of differences
ans = 0
X = 0
Y = 0

# Iterate through each index i from 0 to N-1
for i in range(N):
    # If the difference between V[i] and C[i] is positive
    if V[i] - C[i] > 0:
        # Update X and Y with the respective values from V and C at index i
        X = V[i]
        Y = C[i]
        # Append the difference X-Y to the list
        list.append(X - Y)
        # Update the sum of differences
        ans += X - Y

# Print the sum of all the elements in the list
print(sum(list))
# Print the sum of all the differences between V and C
print(ans)
