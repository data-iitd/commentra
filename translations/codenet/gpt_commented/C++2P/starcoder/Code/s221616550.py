# Function to check if a given string is a palindrome
def isPalindrome(s):
  # Loop through the first half of the string
  for i in range(0, len(s)/2):
    # Compare characters from the start and end of the string
    if s[i] == s[len(s)-1-i]:
      continue # If they match, continue to the next iteration
    else:
      return False # If they don't match, return false
  return True # If all characters matched, return true

# Read input from the user
s = raw_input()

# Check if the entire string is a palindrome and if the first half is also a palindrome
if isPalindrome(s) and isPalindrome(s[0:len(s)/2]):
  print "Yes" # Output "Yes" if both conditions are true
else:
  print "No" # Output "No" if either condition is false

# 