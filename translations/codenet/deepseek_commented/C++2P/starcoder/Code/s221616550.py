# Function to check if a string is a palindrome
def isPalindrome(s):
  # Loop through the first half of the string
  for i in range(0,len(s)/2):
    # Compare characters from the start and end of the string
    if s[i]==s[len(s)-1-i]: continue
    # If any characters do not match, return false
    else: return False
  # If all characters match, return true
  return True

# Read the input string from the user
s = raw_input()
# Check if the entire string and its first half are palindromes
if isPalindrome(s) and isPalindrome(s[0:len(s)/2]):
  # Print "Yes" if both conditions are true
  print "Yes"
else:
  # Print "No" if either condition is false
  print "No"

