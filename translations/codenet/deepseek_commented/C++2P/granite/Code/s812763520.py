
n = int(input()) # Read the integer n from standard input
a = input() # Read the first string a from standard input
b = input() # Read the second string b from standard input
c = input() # Read the third string c from standard input

ans = 0 # Initialize ans to 0

# Loop through each character position up to n
for i in range(n):
  # Check if all three characters at position i are the same
  if a[i] == b[i] and b[i] == c[i]:
    # Do nothing
    pass
  # Check if any two characters at position i are the same
  elif a[i] == b[i] or b[i] == c[i] or a[i] == c[i]:
    ans += 1 # Increment ans by 1
  # If all three characters at position i are different
  else:
    ans += 2 # Increment ans by 2

print(ans) # Print the final value of ans
