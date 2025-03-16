# Take input from the user for string s
s = input()

# Take input from the user for string t
t = input()

# Check if all characters of t except the last one are equal to s
if t[:-1] == s:
    # If the condition is true, print 'Yes'
    print('Yes')
else:
    # If the condition is false, print 'No'
    print('No')
