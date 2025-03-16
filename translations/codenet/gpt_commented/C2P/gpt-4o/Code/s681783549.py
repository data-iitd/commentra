# Declare a character array to store input
S = input()

# Iterate through each character in the string until the end is reached
for i in range(len(S) - 1):
    # Check if the current character is 'A' and the next character is 'C'
    if S[i] == 'A' and S[i + 1] == 'C':
        # If the condition is met, print "Yes" and exit the program
        print("Yes")
        break
else:
    # If the loop completes without finding "AC", print "No"
    print("No")

# <END-OF-CODE>
