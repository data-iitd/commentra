# Declare a string variable to hold the input
str = input()

# Initialize variables to track the maximum length of valid characters and the current count
max = 0
cnt = 0

# Iterate through each character in the input string
for sc in str:
    # Check if the character is one of the valid DNA bases
    if sc == 'A' or sc == 'C' or sc == 'G' or sc == 'T':
        # Increment the count for consecutive valid characters
        cnt += 1
    else:
        # Reset the count if an invalid character is encountered
        cnt = 0
    # Update the maximum length if the current count exceeds the previous maximum
    max = max < cnt and cnt or max

# Output the maximum length of consecutive valid characters found
print(max)

