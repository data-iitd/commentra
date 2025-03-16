
# Declare a string variable to store user input
s = input()

# Check if the length of `s` is at least 4 and if the first four characters are "YAKI"
if len(s) >= 4 and s[:4] == "YAKI":
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # Otherwise, print "No"
    print("No")

