
# Declare empty strings s1, s2, and s3 for user input
s1, s2, s3 = "", "", ""

# Read user input for strings s1, s2, and s3
s1, s2, s3 = input().split()

# Declare slices s1s, s2s, and s3s to store individual characters of strings s1, s2, and s3 respectively
s1s = list(s1)
s2s = list(s2)
s3s = list(s3)

# Print the concatenated uppercase first character of each string
print(s1s[0].upper() + s2s[0].upper() + s3s[0].upper())

# 