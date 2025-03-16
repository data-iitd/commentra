N = int(input())  # Read the number of elements N
A = list(map(int, input().split()))  # Read N elements into the list A

i = 0  # Initialize index i to 0
ans = 0  # Initialize answer variable ans to 0
count = 0  # Initialize count variable to 0

while i < N - 1:  # Continue the loop until the next element is out of bounds
    if A[i] == A[i + 1]:  # Check if the current element is equal to the next element
        count += 1  # Increment the count
        if count % 2 != 0:  # Check if the count is odd
            ans += 1  # Increment the answer variable ans
    else:
        count = 0  # Reset the count to 0 if the current element is not equal to the next element
    i += 1  # Increment the index i

print(ans)  # Print the value of ans
# <END-OF-CODE>
