import sys

# Initialize an array 'a' of size N and an array 'ind_a' of size N
N = 200000
a = [0] * N
ind_a = [0] * N

# Read the number of elements N from the standard input
N = int(sys.stdin.readline().strip())

# Read N elements from the standard input and store them in the array 'a'
a[:N] = list(map(int, sys.stdin.readline().strip().split()))

# Initialize an empty set 'used_inds' to keep track of indices already used
used_inds = set()

ans = 0  # Initialize an answer variable 'ans' to 0

# Iterate through each index i from 0 to N-1
for i in range(N):
    left_border = -1  # Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
    right_border = N

    cur_ind = ind_a[i]  # Get the index of the current element a[i] in the array 'ind_a'

    # Find the index of the left neighbor of the current index i in the set 'used_inds'
    left_it = sorted(used_inds)[bisect_left(sorted(used_inds), cur_ind)]

    # If the left neighbor does not exist, set 'left_border' to -1
    if left_it == min(used_inds):
        left_border = -1
    else:
        # If the left neighbor exists and its index is greater than the current index i, move the iterator left to find the index of the actual left neighbor
        left_border = left_it

    # Find the index of the right neighbor of the current index i in the set 'used_inds'
    right_it = sorted(used_inds)[bisect_right(sorted(used_inds), cur_ind)]

    # If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
    if right_it == max(used_inds):
        right_border = N
    else:
        right_border = right_it

    # Calculate the contribution of the current index i to the answer 'ans'
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

    # Insert the index of the current element a[i] into the set 'used_inds'
    used_inds.add(cur_ind)

    # Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
    # print(i, left_border, right_border, ans)

# Print the final answer 'ans' to the standard output
print(ans)

# Return 0 to indicate successful execution of the program
