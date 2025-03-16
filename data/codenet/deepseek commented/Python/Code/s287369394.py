
N = int(input())  # Read the number of elements
A = [int(x) for x in input().split()]  # Read list A
B = [int(x) for x in input().split()]  # Read list B

ans = 0  # Initialize the answer variable to store the final result

# Loop through each element from 0 to N-1
for i in range(N):
    # Calculate the minimum of A[i] and B[i] and add it to ans
    d = min(A[i], B[i])
    ans += d
    # Subtract the value of d from A[i] and B[i]
    A[i] -= d
    B[i] -= d
    # Calculate the minimum of A[i+1] and B[i] and add it to ans
    d = min(A[i + 1], B[i])
    ans += d
    # Subtract the value of d from A[i+1] and B[i]
    A[i + 1] -= d
    B[i] -= d

print(ans)  # Print the final answer

