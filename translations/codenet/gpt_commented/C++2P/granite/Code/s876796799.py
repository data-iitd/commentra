
# Read the number of elements
N = int(input())

# Input the elements into array 'a'
a = list(map(int, input().split()))

# Populate 'ind_a' with the indices of the elements in 'a'
ind_a = {val: i for i, val in enumerate(a)}

# Set to keep track of used indices
used_inds = set()
ans = 0  # Variable to accumulate the final answer

# Iterate through each element's index
for i in range(N):
    left_border = -1  # Variable to store the left border index
    right_border = N  # Variable to store the right border index
    cur_ind = ind_a[a[i]]  # Current index of the element being processed

    # Find the first used index that is not less than cur_ind
    left_it = next((j for j in used_inds if j < cur_ind), None)
    # Find the first used index that is greater than cur_ind
    right_it = next((j for j in used_inds if j > cur_ind), None)

    # Determine the left border
    if left_it is None:
        left_border = -1  # No used index to the left
    else:
        left_border = left_it

    # Determine the right border
    if right_it is None:
        right_border = N  # No used index to the right
    else:
        right_border = right_it

    # Calculate the contribution of the current index to the answer
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

    # Uncomment the lines below for debugging purposes
    # print(i, left_border, right_border)
    # print(ans)

    # Insert the current index into the set of used indices
    used_inds.add(cur_ind)

# Output the final answer
print(ans)

