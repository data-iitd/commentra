import sys

# Read the number of elements (N) and the size of the subset (K)
N, K = map(int, input().split())

# Initialize an array to store the input integers
S = []

# Read N integers into the array S
for i in range(N):
    S.append(int(input()))

# Initialize temporary variable and answer variable with a large number
temp = 0
ans = 1000000000

# Case when K is 1: Find the minimum absolute value in the array
if K == 1:
    for i in range(N):
        temp = S[i]
        ans = min(abs(temp), ans) # Update ans with the minimum absolute value
    # Output the result
    print(ans)
# Case when K is not equal to N: Calculate the minimum value based on subsets of size K
elif N - K!= 0:
    for i in range(N - K + 1):
        min = S[i] # Minimum value in the current subset
        max = S[i + K - 1] # Maximum value in the current subset
        
        # Calculate temp based on the values of min and max
        if min < 0 and max > 0:
            # If the subset contains both negative and positive values
            temp = min(2 * (-min) + max, (-min) + 2 * max)
        else:
            # If the subset contains only negative or only positive values
            temp = max(abs(min), abs(max))
        
        # Update the answer with the minimum value found
        ans = min(ans, temp)
    # Output the result
    print(ans)
# Case when K is equal to N: Handle the entire array as a single subset
else:
    min = S[0] # Minimum value in the array
    max = S[N - 1] # Maximum value in the array
    
    # Check if the array contains both negative and positive values
    if min < 0 and max > 0:
        # Calculate and print the minimum value based on the formula
        print(min(2 * (-min) + max, (-min) + 2 * max))
    else:
        # Print the maximum absolute value
        print(max(abs(min), abs(max)))

# 