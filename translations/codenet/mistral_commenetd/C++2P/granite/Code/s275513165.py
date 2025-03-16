

str = input() # Read a string input from the user and assign it to the'str' variable

# Check if the third and fourth characters of the string are identical
if str[2] == str[3]:
  # If the condition is true, proceed to the next check
  if str[4] == str[5]: # Check if the fifth and sixth characters are identical
    print("Yes") # If both conditions are true, print 'Yes' to the standard output
  else:
    print("No") # If not, print 'No' instead

