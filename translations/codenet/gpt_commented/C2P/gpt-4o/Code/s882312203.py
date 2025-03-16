# Declare a function to check for duplicate characters in a string
def check_duplicates(s):
    # Loop through each character in the string
    for j in range(len(s)):
        # Compare the current character with every other character in the string
        for i in range(len(s)):
            # Check if the characters are the same and they are not the same position
            if i != j and s[i] == s[j]:
                # If a duplicate character is found, print "no" and exit the function
                print("no")
                return
    # If no duplicates were found, print "yes"
    print("yes")

# Read a string from standard input
s = input().strip()

# Call the function with the input string
check_duplicates(s)

# <END-OF-CODE>
