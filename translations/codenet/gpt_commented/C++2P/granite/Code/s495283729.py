
# Read a string from standard input
s = input()

# Initialize variables: i for iteration and flag to track validity
i = 0
flag = 0

# Iterate through each character in the string
while i < len(s):
  # Check if the index is even
  if i % 2 == 0:
    # Switch case for characters at even indices
    if s[i] == 'R' or s[i] == 'U' or s[i] == 'D':
      # If character is valid, do nothing
      pass
    else:
      # If character is not valid, set flag to indicate an error
      flag = 1
      break
  else:
    # Switch case for characters at odd indices
    if s[i] == 'L' or s[i] == 'U' or s[i] == 'D':
      # If character is valid, do nothing
      pass
    else:
      # If character is not valid, set flag to indicate an error
      flag = 1
      break
  i += 1

# Check the flag to determine if the input string was valid
if flag == 0:
  # If flag is still 0, print "Yes" indicating valid input
  print("Yes")
else:
  # If flag is set, print "No" indicating invalid input
  print("No")
