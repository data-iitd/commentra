
# Read input string from the user
W = input()

# Sort the characters in the string in ascending order
W = ''.join(sorted(W))

# Iterate through the sorted string, checking pairs of characters
for i in range(0, len(W), 2):
    # Check if the current character is not equal to the next character
    if W[i]!= W[i+1]:
        # If they are not equal, print "No" and exit the program
        print("No")
        exit(0)

# If all pairs are equal, print "Yes"
print("Yes")
