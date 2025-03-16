# Declare a variable named 's' of type string
s = input()

# Initialize a for loop to iterate through each character in the string 's'
for i in range(len(s)):
    # Check if the character at index 'i+1' in the string 's' contains the character at index 'i'
    if s[i+1:] and s[i] in s[i+1:]:
        # If the condition is true, print "no" and exit the program
        print("no")
        exit(0)

# If the for loop completes without finding any matching characters, print "yes"
print("yes")
# <END-OF-CODE>
