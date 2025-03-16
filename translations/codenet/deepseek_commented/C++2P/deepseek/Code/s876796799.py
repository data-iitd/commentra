import sys

# Read the number of elements
N = int(sys.stdin.readline().strip())

# Read the elements into array a
a = list(map(int, sys.stdin.readline().strip().split()))

# Initialize ind_a with the indices of elements in array a
ind_a = [0] * N
for i in range(N):
    ind_a[a[i] - 1] = i

# Set to keep track of used indices
used_inds = set()

# Variable to store the final answer
ans = 0

# Process each element
for i in range(N):
    # Current index of the element being processed
    cur_ind = ind_a[i]
    
    # Find the lower bound of cur_ind in used_inds
    left_it = used_inds.bisect_left(cur_ind)
    
    # Find the lower bound of cur_ind + 1 in used_inds
    right_it = used_inds.bisect_left(cur_ind + 1)
    
    if left_it == 0:
        left_border = -1
    else:
        left_border = list(used_inds)[left_it - 1]
    
    if right_it == len(used_inds):
        right_border = N
    else:
        right_border = list(used_inds)[right_it]
    
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)
    
    # Insert the current index into the set used_inds
    used_inds.add(cur_ind)

# Output the final answer
print(ans)
