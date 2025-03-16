
#include<iostream>
using namespace std;

# Declare variables
N = 0
ans = 0
i = 0
count = 0

# Read the number of elements in the array from the user
cin >> N

# Declare and initialize an integer array A of size N
A = [0] * N

# Read elements of the array A from the user
for i in range(N):
    cin >> A[i] # Read the i-th element of array A

# Initialize variables i, ans, and count to 0
i = 0
ans = 0
count = 0

# Traverse the array using a while loop
while A[i+1] != '\0': # Assuming NULL is represented by '\0' in the array

    # Check if the current and next elements of the array are equal
    if A[i] == A[i+1]:
        # Increment the count if the current and next elements are equal
        count += 1

        # If the count is odd, increment the answer
        if count % 2 != 0:
            ans += 1

    # Reset the count to 0 if the current and next elements are not equal
    else:
        count = 0

    # Increment the index i to move to the next element of the array
    i += 1

# Print the answer
print(ans)

# Return 0 to indicate successful execution of the program
return 0

