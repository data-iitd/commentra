
import sys

# Read the number of elements N from the standard input
N = int(input())

# Read N elements from the standard input and store them in the array 'a'
a = list(map(int, input().split()))

# Initialize an empty set 'used_inds' to keep track of indices already used
used_inds = set()

ans = 0 # Initialize an answer variable 'ans' to 0

# Iterate through each index i from 0 to N-1
for i in range(N):
    left_border = -1 # Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
    right_border = N

    cur_ind = a[i] # Get the index of the current element a[i] in the array 'a'

    # Find the index of the left neighbor of the current index i in the set 'used_inds'
    left_border = max(left_border, next((x for x in used_inds if x < cur_ind), -1))

    # Find the index of the right neighbor of the current index i in the set 'used_inds'
    right_border = min(right_border, next((x for x in used_inds if x > cur_ind), N))

    # Calculate the contribution of the current index i to the answer 'ans'
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

    # Insert the index of the current element a[i] into the set 'used_inds'
    used_inds.add(cur_ind)

    # Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
    # print(i, left_border, right_border)
    # print(ans)

# Print the final answer 'ans' to the standard output
print(ans)

