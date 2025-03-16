

# Read the number of elements in the array from the user
N = int(input())

# Declare and initialize an integer array A of size N
A = list(map(int, input().split()))

# Initialize variables i, ans, and count to 0
i = 0
ans = 0
count = 0

# Traverse the array using a while loop
while i < N-1:
    # Check if the current and next elements of the array are equal
    if A[i] == A[i+1]:
        # Increment the count if the current and next elements are equal
        count += 1

        # If the count is odd, increment the answer
        if count % 2!= 0:
            ans += 1
    # Reset the count to 0 if the current and next elements are not equal
    else:
        count = 0

    # Increment the index i to move to the next element of the array
    i += 1

# Print the answer
print(ans)

