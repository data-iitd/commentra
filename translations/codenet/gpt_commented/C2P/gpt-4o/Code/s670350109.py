# Declare character arrays to hold two strings
str1 = input().strip()  # Read first string from user input
str2 = input().strip()  # Read second string from user input

# Get the length of the first string
i = len(str1)
t = i - 1

# Check if the lengths of the two strings are different
if len(str1) != len(str2):
    # If lengths are different, they cannot be anagrams
    print("NO")
else:
    # Reverse the first string
    temp = str1[::-1]  # Reverse str1 using slicing

    # Compare the reversed string with the second string
    if temp == str2:
        # If both strings are equal, they are anagrams
        print("YES")
    else:
        # If not equal, they are not anagrams
        print("NO")

# <END-OF-CODE>
