# Read the number of elements
N = int(input())

# Read two lists of integers A and B from input
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

# Initialize the answer variable to accumulate the result
ans = 0

# Iterate through each index from 0 to N-1
for i in range(N):
    # Determine the minimum value between A[i] and B[i]
    d = min(A[i], B[i])
    
    # Add the minimum value to the answer
    ans += d
    
    # Decrease A[i] and B[i] by the minimum value found
    A[i] -= d
    B[i] -= d
    
    # Determine the minimum value between A[i + 1] and the updated B[i]
    d = min(A[i + 1], B[i])
    
    # Add this minimum value to the answer
    ans += d
    
    # Decrease A[i + 1] and B[i] by the minimum value found
    A[i + 1] -= d
    B[i] -= d

# Print the final accumulated answer
print(ans)
