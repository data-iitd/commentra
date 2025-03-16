import sys

# Read the number of elements
N = int(input().strip())

# Input the elements into array 'a'
a = list(map(int, input().strip().split()))

# Populate 'ind_a' with the indices of the elements in 'a'
ind_a = [0] * N
for i in range(N):
    ind_a[a[i] - 1] = i

# Set to keep track of used indices
used_inds = set()
ans = 0

# Iterate through each element's index
for i in range(N):
    cur_ind = ind_a[i]

    # Find the first used index that is not less than cur_ind
    left_it = used_inds.bisect_left(cur_ind)
    # Find the first used index that is greater than cur_ind
    right_it = used_inds.bisect_right(cur_ind)

    # Determine the left border
    if left_it == 0:
        left_border = -1
    else:
        left_border = list(used_inds)[left_it - 1]

    # Determine the right border
    if right_it == len(used_inds):
        right_border = N
    else:
        right_border = list(used_inds)[right_it]

    # Calculate the contribution of the current index to the answer
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

    # Insert the current index into the set of used indices
    used_inds.add(cur_ind)

# Output the final answer
print(ans)
