
N = int(input())  # Read the integer input N
A = list(map(int, input().split()))  # Read the list of integers A

# Initialize variables to track the minimum and maximum indices where the condition is true
mn, mx = N + 1, -1

# Iterate over the range of N to find the indices where the condition is true
for i in range(N):
    if (i + 1 != A[i]):
        mn = min(mn, i)  # Update mn if a smaller index is found
        mx = max(mx, i)  # Update mx if a larger index is found

# Check if no indices satisfy the condition
if (mx == -1):
    print('0 0')  # Print '0 0' if no indices satisfy the condition
else:
    # Reverse the sublist from index mn to mx + 1 and update A
    A = A[:mn] + A[mn:(mx + 1)][::-1] + A[(mx + 1):]
    
    # Check if the list A is sorted
    if (sorted(A) == A):
        print(mn + 1, mx + 1)  # Print the indices if A is sorted
    else:
        print('0 0')  # Print '0 0' if A is not sorted

