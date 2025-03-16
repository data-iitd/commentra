
s = input()  # Take the first input and store it in variable `s`
t = input()  # Take the second input and store it in variable `t`

# Check if the substring of `t` excluding the last character is equal to `s`
if t[:-1] == s:
  print('Yes')  # If they are equal, print 'Yes'
else:
  print('No')  # If they are not equal, print 'No'

