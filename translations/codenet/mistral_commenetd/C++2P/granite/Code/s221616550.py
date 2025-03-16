
# Function to check if a given string is a palindrome
def isPalindrome(s):
  # Iterate through the first half of the string
  for i in range(0, len(s)//2):
    # Check if the character at current index is same as its mirror index
    if s[i] == s[len(s)-1-i]:
      # If yes, continue to next character
      continue
    else:
      # If no, return false as the string is not a palindrome
      return False
  # If we reach here, it means all characters in the first half are same as their mirror index
  # So, the string is a palindrome
  return True

# Take user input and store it in the string variable
s = input()
# Check if the given string is a palindrome and its first half is also a palindrome
if isPalindrome(s) and isPalindrome(s[:len(s)//2]):
  # If yes, print "Yes"
  print("Yes")
else:
  # If no, print "No"
  print("No")

