
# Read two strings from user input
str1 = input()
str2 = input()

# Get the length of the first string and calculate the last index
i = len(str1)
t = i - 1

# Check if the lengths of the two strings are different
if len(str1)!= len(str2):
    # If lengths are different, they cannot be anagrams
    print("NO")
else:
    # Reverse the first string and store it in the temporary array
    temp = str1[::-1]

    # Reset counters for comparison
    t = 0
    i = 0

    # Compare the reversed string with the second string
    while i < len(temp):
        if temp[i] == str2[i]:
            t += 1  # Count matching characters
        i += 1

    # Check if all characters matched
    if len(str2) == t:
        # If all characters match, the strings are anagrams
        print("YES")
    else:
        # If not all characters match, they are not anagrams
        print("NO")

