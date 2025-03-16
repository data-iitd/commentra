# Read the length of the string from user input
n = int(input())

# Read the string from user input
s = input()

# Initialize a counter to count the number of distinct segments
cnt = 0

# Iterate through each character in the string
i = 0
while i < n:
    # Increment the counter for each new segment found
    cnt += 1

    # Initialize a variable j to find the end of the current segment
    j = i + 1

    # Continue moving j forward as long as the characters are the same
    while j < n and s[i] == s[j]:
        j += 1

    # Move i to the end of the current segment
    i = j

# Output the total count of distinct segments
print(cnt)

# <END-OF-CODE>
