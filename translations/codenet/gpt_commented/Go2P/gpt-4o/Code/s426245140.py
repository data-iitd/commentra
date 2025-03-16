# Declare a variable to hold the input string
s = input()

# Check if the first three characters are the same or the last three characters are the same
if (s[0] == s[1] == s[2]) or (s[1] == s[2] == s[3]):
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")

# <END-OF-CODE>
