#######
# Code
#######

# Take an integer input H from the user
H = int(input())

# Initialize a counter variable count with a value of 0
count = 0

# Define a recursive function dfs that takes an integer argument h
def dfs(h):
  # Base case: if h is equal to 1, return 1
  if h == 1:
    return 1

  # Recursive case: call the function dfs with the argument h // 2
  # Each recursive call multiplies the result by 2 and adds 1 to it
  return dfs(h // 2) * 2 + 1

# Print the result of the dfs function call with the argument H
print(dfs(H))
