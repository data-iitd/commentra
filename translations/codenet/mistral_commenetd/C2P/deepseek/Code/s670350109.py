# Read the first string from the user
str1 = input()
print("First string:", str1)  # Print the first string for verification

# Read the second string from the user
str2 = input()
print("Second string:", str2)  # Print the second string for verification

# Check if the lengths of the two strings are equal
if len(str1) != len(str2):
    print("NO")  # If the lengths are not equal, print "NO" and exit
else:
    # Reverse the first string and store it in temp array
    temp = str1[::-1]

    # Compare the reversed first string with the second string
    if temp == str2:
        print("YES")  # If all characters are equal, print "YES"
    else:
        print("NO")  # If any character is different, print "NO"

# End-of-code
