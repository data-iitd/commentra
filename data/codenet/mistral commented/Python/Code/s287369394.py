#######
# Code
#######

# Read the number of test cases (N)
N = int(input())

# Read the array A and store it as a list
A = [int(x) for x in input().split()]

# Read the array B and store it as a list
B = [int(x) for x in input().split()]

# Initialize the answer variable to 0
ans = 0

# Iterate through each index i from 0 to N-1
for i in range(N):
    # Find the minimum of A[i] and B[i]
    d = min(A[i], B[i])
    
    # Add the minimum value to the answer
    ans += d
    
    # Subtract the minimum value from both A[i] and B[i]
    A[i] -= d
    B[i] -= d
    
    # Find the minimum of A[i+1] and B[i]
    d = min(A[i+1], B[i])
    
    # Add the minimum value to the answer
    ans += d
    
    # Subtract the minimum value from A[i+1]
    A[i+1] -= d
    
    # Subtract the minimum value from B[i]
    B[i] -= d

# Print the answer
print(ans)
