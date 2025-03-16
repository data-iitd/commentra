# Read two strings from the user
str_input, p = input().split()

# Duplicate and concatenate the string
tmp = str_input
str_concatenated = str_input + tmp

# Calculate the lengths of the strings
slen = len(str_concatenated)
plen = len(p)

# Initialize flag to 0 (not found)
flag = 0

# Check if the pattern exists in the concatenated string
for i in range(slen - plen + 1):
    if str_concatenated[i:i + plen] == p:
        flag = 1
        break

# Output the result
if flag:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
