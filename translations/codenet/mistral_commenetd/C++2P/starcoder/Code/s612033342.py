
# Function to calculate 2 raised to the power of a given number
def pow2(a):
  ret = 1 # Initialize result to 1
  for i in range(a): ret *= 2 # Multiply result by 2 for each iteration of the loop
  return ret # Return the final result

# Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
def count(hw, a, b):
  sum = 0 # Initialize sum to 0
  for i in range(len(hw)): # Iterate through each row of the 2D grid
    for j in range(len(hw[0])): # Iterate through each column of the current row
      if ((a & (1 << i)) and (b & (1 << j)) and hw[i][j] == 1): sum += 1 # If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
  return sum # Return the final sum

h, w, k = map(int, input().split()) # Read input values for height, width, and target count from standard input
hw = [[0 for j in range(w)] for i in range(h)] # Initialize 2D grid with zeroes
for i in range(h): # Iterate through each row of the 2D grid
  for j in range(w): # Iterate through each column of the current row
    c = input() # Read the character from standard input
    if c == '#': hw[i][j] = 1 # If the character is '#', set the corresponding cell in the grid to 1

sum = 0 # Initialize sum to 0
for i in range(pow2(h)): # Iterate through all possible binary combinations of height
  for j in range(pow2(w)): # Iterate through all possible binary combinations of width
    if count(hw, i, j) == k: sum += 1 # If the number of 1's in the current combination matches the target count, increment sum

print(sum) # Output the final sum to standard output

