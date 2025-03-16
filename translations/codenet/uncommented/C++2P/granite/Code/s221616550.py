
def isPalindrome(s):
  for i in range(len(s)//2):
    if s[i]==s[-1-i]: continue
    else: return False
  return True

s = input()
if isPalindrome(s) and isPalindrome(s[:len(s)//2]):
  print("Yes")
else:
  print("No")

