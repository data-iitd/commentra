
# Read input string from the user
str = input()

# Initialize variables to track the maximum length of valid characters and the current count
max = 0
cnt = 0

# Iterate through each character in the input string
for sc in str:
    # Check if the character is one of the valid DNA bases
    if sc in ['A', 'C', 'G', 'T']:
        # Increment the count for consecutive valid characters
        cnt += 1
    else:
        # Reset the count if an invalid character is encountered
        cnt = 0
    # Update the maximum length if the current count exceeds the previous maximum
    max = max if max > cnt else cnt

# Output the maximum length of consecutive valid characters found
print(max)

