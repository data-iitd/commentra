
# Declare three string variables to hold user input
s1 = input()
s2 = input()
s3 = input()

# Split each string into a list of individual characters
s1s = list(s1)
s2s = list(s2)
s3s = list(s3)

# Convert the first character of each string to uppercase and concatenate them
result = s1s[0].upper() + s2s[0].upper() + s3s[0].upper()

# Print the concatenated result
print(result)

