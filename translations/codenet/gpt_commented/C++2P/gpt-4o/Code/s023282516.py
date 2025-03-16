# Define the list of substrings to check against
divide = ["dream", "dreamer", "erase", "eraser"]

# Read the input string from the user
S = input()

# Reverse the input string to facilitate checking from the end
S = S[::-1]
# Reverse each of the substrings in the divide list for matching
divide = [d[::-1] for d in divide]

# Initialize a flag to determine if the string can be fully divided
can = True
# Start checking the string from the beginning
i = 0
while i < len(S):
    can2 = False  # Flag to check if we can divide with any of the substrings
    # Iterate through each substring in the divide list
    for d in divide:
        # Check if the current substring matches the beginning of the remaining string
        if S.startswith(d, i):  # If we can divide with d
            can2 = True  # Set the flag to true
            i += len(d)  # Move the index forward by the length of the matched substring
            break  # Break the loop since we found a match
    # If no substring matched, set the can flag to false and break the loop
    if not can2:  # If we couldn't divide the string
        can = False
        break

# Output the result based on whether the string can be fully divided
if can:
    print("YES")  # If it can be divided, print "YES"
else:
    print("NO")  # Otherwise, print "NO"

# <END-OF-CODE>
