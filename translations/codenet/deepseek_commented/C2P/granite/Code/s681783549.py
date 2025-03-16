
# Read a string input from the user and store it in S
S = input()

# Loop through each character in the string S
for i in range(len(S)):
    # Check if the current character is 'A' and the next character is 'C'
    if S[i] == 'A' and S[i + 1] == 'C':
        # If the condition is met, print "Yes" and exit the program
        print("Yes")
        exit(0)

# If the condition is not met after the loop completes, print "No" and exit the program
print("No")
