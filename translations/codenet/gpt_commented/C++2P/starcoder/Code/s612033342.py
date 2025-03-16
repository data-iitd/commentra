# Define a function to calculate 2 raised to the power of 'a'
def pow2(a):
  ret = 1 # Initialize result to 1
  for i in range(a): ret *= 2 # Multiply by 2, 'a' times
  return ret # Return the result

# Define a function to count the number of '1's in the hw matrix based on the bit patterns of 'a' and 'b'
def count(hw, a, b):
  sum = 0 # Initialize sum to count the valid positions
  # Iterate through each row of the hw matrix
  for i in range(len(hw)):
    # Iterate through each column of the hw matrix
    for j in range(len(hw[0])):
      # Check if the i-th bit of 'a' and the j-th bit of 'b' are set, and if hw[i][j] is 1
      if (a >> i & 1) and (b >> j & 1) and hw[i][j] == 1: sum += 1
  return sum # Return the total count of valid positions

# Read the dimensions of the matrix and the target count 'k'
h, w, k = map(int, input().split())
hw = [[0] * w for i in range(h)] # Initialize a 2D vector with dimensions h x w filled with 0

# Read the matrix input
for i in range(h):
  for j in range(w):
    c = input() # Read each character
    # If the character is '#', mark it as 1 in the hw matrix
    if c == '#': hw[i][j] = 1

sum = 0 # Initialize sum to count the valid configurations
# Iterate through all possible combinations of rows (2^h)
for i in range(pow2(h)):
  # Iterate through all possible combinations of columns (2^w)
  for j in range(pow2(w)):
    # If the count of '1's matches the target 'k', increment the sum
    if count(hw, i, j) == k: sum += 1

print(sum) # Output the total count of valid configurations

