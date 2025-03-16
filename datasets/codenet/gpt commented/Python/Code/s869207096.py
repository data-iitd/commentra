# Read an integer input representing the length of the string
n = int(input())

# Read the string input
s = input()

# Initialize a counter to keep track of the number of distinct segments
cnt = 1

# Loop through the string from the first character to the second-to-last character
for i in range(n - 1):
    # Check if the current character is the same as the next character
    if s[i] == s[i + 1]:
        # If they are the same, continue to the next iteration (do nothing)
        continue
    else:
        # If they are different, increment the counter for distinct segments
        cnt += 1

# Print the total count of distinct segments
print(cnt)
