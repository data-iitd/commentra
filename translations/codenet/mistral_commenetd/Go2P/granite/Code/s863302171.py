
# Declare a variable 'n' of type string
n = input()

# Initialize a loop counter 'i'
for i in range(3):
    # Check if the current character in the string 'n' is equal to '7'
    if n[i] == '7':
        # If yes, print "Yes" and exit the function
        print("Yes")
        break
else:
    # If no '7' is found in the first three characters, print "No"
    print("No")

