# Declare character arrays for input strings and temporary storage
str_input = input().strip()  # Read the first string
p = input().strip()           # Read the second string

# Copy the original string into a temporary variable and concatenate it with itself
tmp = str_input
str_concatenated = str_input + tmp

# Calculate the lengths of the concatenated string and the pattern string
slen = len(str_concatenated)
plen = len(p)

# Initialize a flag to indicate if the pattern is found
flag = False

# Loop through the concatenated string to search for the pattern
for i in range(slen - plen + 1):  # Adjusted to include the last possible starting index
    # Compare the substring of str_concatenated with the pattern p
    if str_concatenated[i:i + plen] == p:
        flag = True  # Set flag if a match is found
        break  # Exit the loop as we found a match

# Output "Yes" if the pattern was found, otherwise output "No"
if flag:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
