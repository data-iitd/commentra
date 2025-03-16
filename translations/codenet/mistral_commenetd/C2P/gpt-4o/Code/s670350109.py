# Include standard input/output library
# Include string manipulation library

str1 = input("Enter the first string: ")  # Read the first string from the user
print("First string:", str1)  # Print the first string for verification

str2 = input("Enter the second string: ")  # Read the second string from the user
print("Second string:", str2)  # Print the second string for verification

# Check if the lengths of the two strings are equal
if len(str1) != len(str2):
    print("NO")  # If the lengths are not equal, print "NO"
else:
    # Reverse the first string
    temp = str1[::-1]  # Reverse the first string using slicing

    # Compare the reversed first string with the second string
    if temp == str2:  # Check if the reversed string is equal to the second string
        print("YES")  # If they are equal, print "YES"
    else:
        print("NO")  # If they are not equal, print "NO"

# End of main function
# <END-OF-CODE>
