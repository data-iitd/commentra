s = input()  # Read input from the user and store it in the variable 's'

# Iterate over each character in the string 's'
for i in range(len(s)):
    # Check if the current character exists in the substring that follows it
    if s[i] in s[i + 1:]:
        # If the character is found in the remaining substring, print "no" and exit
        print("no")
        exit()

# If no duplicate characters were found, print "yes"
print("yes")
# <END-OF-CODE>
