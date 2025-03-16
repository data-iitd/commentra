s = input()  # Take the first string as input from the user
t = input()  # Take the second string as input from the user

if t[:-1] == s:  # Check if the second last character of string 't' is same as the last character of string 's'
  print('Yes')   # If it is, then print 'Yes'
else:
  print('No')   # Otherwise, print 'No'