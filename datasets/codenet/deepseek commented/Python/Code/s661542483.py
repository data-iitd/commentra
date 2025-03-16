
H = int(input())  # Take an integer input H

count = 0  # Initialize a variable count to 0

def dfs(h):  # Define a recursive function dfs(h)
  if h == 1:  # If h is 1, return 1
    return 1

  return dfs(h // 2) * 2 + 1  # Otherwise, return dfs(h // 2) * 2 + 1

print(dfs(H))  # Print the result of dfs(H)

