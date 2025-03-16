# Declare a variable to store the input string
n = input()

# Loop through the first three characters of the input string
for i in range(3):
    # Check if the character at the current position is '7'
    if n[i] == '7':
        # If '7' is found, print "Yes" and exit the program
        print("Yes")
        break
else:
    # If the loop completes without finding a '7', print "No"
    print("No")

# <END-OF-CODE>
