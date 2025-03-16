# Convert the user input into a list of characters
s = list(str(input()))

# Sort the list of characters in ascending order
s.sort()

# Check if the first two characters are the same, the third character is different,
# and the last two characters are the same
if s[0] == s[1] and s[0] != s[2] and s[2] == s[3]:
    # If the condition is met, print "Yes"
    print("Yes")
else:
    # If the condition is not met, print "No"
    print("No")
