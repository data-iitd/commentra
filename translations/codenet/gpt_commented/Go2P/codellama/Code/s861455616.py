
# Declare a variable to hold the input string
s = input()

# Check if the length of the string is at least 4 characters 
# and if the first four characters are "YAKI"
if len(s) >= 4 and s[:4] == "YAKI":
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")

