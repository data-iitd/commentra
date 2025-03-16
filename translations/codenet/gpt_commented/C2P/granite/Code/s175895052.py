
# Read a string from standard input and store it in the variable 'n'
n = input()

# Check if the first three characters are the same or if the last three characters are the same
if ((n[0] == n[1]) and (n[1] == n[2])) or ((n[1] == n[2]) and (n[2] == n[3])):
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")

# End of code
