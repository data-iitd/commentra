# Assign the string input to a list named 's'
s = list(str(input()))

# Sort the list 's' in ascending order
s.sort()

# Check if the first element of the sorted list is equal to the second element
# and if the second element is equal to the third element
if s[0] == s[1] and s[1] == s[2]:
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")
