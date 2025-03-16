
def isPalindrome(s):
  for i in range(0,len(s)/2):
    if s[i]==s[len(s)-1-i]: continue
    else: return False
  return True

s = raw_input()
if isPalindrome(s) and isPalindrome(s[0:len(s)/2]):
  print "Yes"
else:
  print "No"

