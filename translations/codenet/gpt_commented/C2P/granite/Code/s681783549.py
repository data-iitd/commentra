
# Read a string input from the user
S = input()

# Iterate through each character in the string until the null terminator is reached
for i in range(len(S)):
    # Check if the current character is 'A' and the next character is 'C'
    if S[i] == 'A' and S[i + 1] == 'C':
        # If the condition is met, print "Yes" and exit the program
        print("Yes")
        exit(0)

# If the loop completes without finding "AC", print "No"
print("No")

