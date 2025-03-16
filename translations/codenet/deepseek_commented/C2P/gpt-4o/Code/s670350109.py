# Read the first string from the user input
str1 = input()
# Read the second string from the user input
str2 = input()

# Calculate the length of the first string
i = len(str1)

# Check if the lengths of the two strings are not equal
if len(str1) != len(str2):
    # Print "NO" if the lengths are not equal
    print("NO")
else:
    # Reverse the first string
    temp = str1[::-1]
    
    # Check if the reversed string matches the second string
    if temp == str2:
        # Print "YES" if all characters match
        print("YES")
    else:
        # Print "NO" if not all characters match
        print("NO")

# <END-OF-CODE>
