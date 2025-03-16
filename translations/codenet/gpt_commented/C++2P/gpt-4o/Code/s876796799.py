# Import necessary libraries
from sortedcontainers import SortedSet

# Declare a list to hold the input values and a list to store their indices
a = [0] * 200000
ind_a = [0] * 200000

# Read the number of elements
N = int(input())

# Input the elements into list 'a'
for i in range(N):
    a[i] = int(input())

# Populate 'ind_a' with the indices of the elements in 'a'
for i in range(N):
    ind_a[a[i] - 1] = i  # Store the index of each element based on its value

# Set to keep track of used indices
used_inds = SortedSet()
ans = 0  # Variable to accumulate the final answer

# Iterate through each element's index
for i in range(N):
    left_border = 0  # Variable to store the left border index
    right_border = 0  # Variable to store the right border index
    cur_ind = ind_a[i]  # Current index of the element being processed

    # Find the first used index that is not less than cur_ind
    left_it = used_inds.bisect_left(cur_ind)
    # Find the first used index that is greater than cur_ind
    right_it = used_inds.bisect_right(cur_ind)

    # Determine the left border
    if left_it == 0:
        left_border = -1  # No used index to the left
    else:
        left_border = used_inds[left_it - 1]  # Set the left border to the found index

    # Determine the right border
    if right_it == len(used_inds):
        right_border = N  # No used index to the right
    else:
        right_border = used_inds[right_it]  # Set the right border to the found index

    # Calculate the contribution of the current index to the answer
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

    # Uncomment the lines below for debugging purposes
    # print(i, left_border, right_border)
    # print(ans)

    # Insert the current index into the set of used indices
    used_inds.add(cur_ind)

# Output the final answer
print(ans)
# <END-OF-CODE>
