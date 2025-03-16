# Declare a variable to hold the input string
n = input()

# Loop through the first three characters of the input string
for i in range(3):
    # Check if the current character is '7'
    if n[i] == '7':
        # If '7' is found, print "Yes" and exit the program
        print("Yes")
        break
else:
    # If '7' is not found in the first three characters, print "No"
    print("No")

# <END-OF-CODE>
