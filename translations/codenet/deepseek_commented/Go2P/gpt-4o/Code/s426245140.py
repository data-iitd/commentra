# Declare a variable to store the input string
s = input()

# Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
if (s[0] == s[1] == s[2]) or (s[1] == s[2] == s[3]):
    # If either condition is true, print "Yes"
    print("Yes")
else:
    # Otherwise, print "No"
    print("No")

# <END-OF-CODE>
