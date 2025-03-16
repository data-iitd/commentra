# Define the array of substrings to check against
divide = ["dream", "dreamer", "erase", "eraser"]

# Read the input string from the user
S = raw_input()

# Reverse the input string to facilitate checking from the end
S = S[::-1]
# Reverse each of the substrings in the divide array for matching
for i in range(len(divide)): divide[i] = divide[i][::-1]

# Initialize a flag to determine if the string can be fully divided
can = True
# Start checking the string from the beginning
for i in range(len(S)):
    can2 = False # Flag to check if we can divide with any of the substrings
    # Iterate through each substring in the divide array
    for j in range(len(divide)):
        d = divide[j]
        # Check if the current substring matches the beginning of the remaining string
        if S[i:i+len(d)] == d: # If we can divide with d
            can2 = True # Set the flag to true
            i += len(d) # Move the index forward by the length of the matched substring
    # If no substring matched, set the can flag to false and break the loop
    if not can2: # If we couldn't divide the string
        can = False
        break

# Output the result based on whether the string can be fully divided
if can: print "YES" # If it can be divided, print "YES"
else: print "NO" # Otherwise, print "NO"

