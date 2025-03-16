# Declare a character array to store the input string
S = input()

# Loop through each character in the string S
for i in range(len(S) - 1):
    # Check if the current character is 'A' and the next character is 'C'
    if S[i] == 'A' and S[i + 1] == 'C':
        # If the condition is met, print "Yes" and exit the program
        print("Yes")
        break
else:
    # If the condition is not met after the loop completes, print "No"
    print("No")

# <END-OF-CODE>
