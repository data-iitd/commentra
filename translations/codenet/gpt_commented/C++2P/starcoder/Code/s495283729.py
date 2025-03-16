
# Declare a character array to hold the input string
s = [None] * 1000

# Read a string from standard input
s = raw_input()

# Initialize variables: i for iteration and flag to track validity
i = 0
flag = 0

# Iterate through each character in the string
while i < len(s):
  # Check if the index is even
  if i % 2 == 0:
    # Switch case for characters at even indices
    if s[i] == 'R':
      # 'R' is valid, do nothing
      pass
    elif s[i] == 'U':
      # 'U' is valid, do nothing
      pass
    elif s[i] == 'D':
      # 'D' is valid, do nothing
      pass
    else:
      # If character is not valid, set flag to indicate an error
      flag = 1
      break
  else:
    # Switch case for characters at odd indices
    if s[i] == 'L':
      # 'L' is valid, do nothing
      pass
    elif s[i] == 'U':
      # 'U' is valid, do nothing
      pass
    elif s[i] == 'D':
      # 'D' is valid, do nothing
      pass
    else:
      # If character is not valid, set flag to indicate an error
      flag = 1
      break
  i += 1

# Check the flag to determine if the input string was valid
if flag == 0:
  # If flag is still 0, print "Yes" indicating valid input
  print "Yes"
else:
  # If flag is set, print "No" indicating invalid input
  print "No"

