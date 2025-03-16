
# Import the "input" function from the "builtins" module to read user input
import builtins

# Define a variable named "s" of type string to store user input
s = builtins.input()

# Check if the first three characters of the string "s" form an identical sequence
if (s[0] == s[1] and s[1] == s[2]) or (s[1] == s[2] and s[2] == s[3]):
  # If the condition is true, print "Yes" to the standard output
  print("Yes")
else:
  # If the condition is false, print "No" to the standard output
  print("No")

# End of code