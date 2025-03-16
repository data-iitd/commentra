def are_anagrams(str1, str2):
    if len(str1) != len(str2):
        return "NO"
    
    # Reverse the first string
    temp = str1[::-1]
    
    # Compare the reversed string with the second string
    if temp == str2:
        return "YES"
    else:
        return "NO"

# Read two strings from user input
str1 = input().strip()
str2 = input().strip()

# Check if the strings are anagrams
result = are_anagrams(str1, str2)

# Print the result
print(result)
