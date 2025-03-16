
# Declare an array to hold the input values and an array to store their indices
a = []
ind_a = []

# Read the number of elements
N = int(input())

# Input the elements into array 'a'
for i in range(N):
  a.append(int(input()))

# Populate 'ind_a' with the indices of the elements in 'a'
for i in range(N):
  ind_a.append(i)

# Set to keep track of used indices
used_inds = set()
ans = 0 # Variable to accumulate the final answer

# Iterate through each element's index
for i in range(N):
  left_border = -1 # Variable to store the left border index
  right_border = N # Variable to store the right border index
  cur_ind = ind_a[i] # Current index of the element being processed

  # Find the first used index that is not less than cur_ind
  left_it = used_inds.lower_bound(cur_ind)
  # Find the first used index that is greater than cur_ind
  right_it = used_inds.lower_bound(cur_ind + 1)

  # Determine the left border
  if(left_it == used_inds.begin()):
    left_border = -1 # No used index to the left
  else:
    if(left_it == used_inds.end() or *left_it > cur_ind):
      left_it -= 1 # Move to the previous index
    left_border = *left_it # Set the left border to the found index

  # Determine the right border
  if(right_it == used_inds.end()):
    right_border = N # No used index to the right
  else:
    right_border = *right_it # Set the right border to the found index

  # Calculate the contribution of the current index to the answer
  ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1)

  # Uncomment the lines below for debugging purposes
  # print(i, left_border, right_border)
  # print(ans)

  # Insert the current index into the set of used indices
  used_inds.add(cur_ind)

# Output the final answer
print(ans)

