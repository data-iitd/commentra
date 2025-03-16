# Declare variables
N = int(input())  # Read the number of elements in the array

# Initialize an array of size N
A = list(map(int, input().split()))

# Initialize index and counters
i = 0
ans = 0    # To store the final answer
count = 0  # To count consecutive equal elements

# Loop through the array until the second last element
while i < N - 1:  # Ensure we don't go out of bounds
    # Check if the current element is equal to the next element
    if A[i] == A[i + 1]:
        count += 1  # Increment count for consecutive elements
        
        # If count is odd, increment the answer
        if count % 2 != 0:
            ans += 1
    else:
        # Reset count if elements are not equal
        count = 0
    i += 1  # Move to the next element

# Output the final answer
print(ans)
# End of the program
# <END-OF-CODE>
