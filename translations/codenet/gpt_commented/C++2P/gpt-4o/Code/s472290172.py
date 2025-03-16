# Declare a string variable to hold the input
str_input = input()

# Initialize variables to track the maximum length of valid characters and the current count
max_length = 0
count = 0

# Iterate through each character in the input string
for char in str_input:
    # Check if the character is one of the valid DNA bases
    if char in 'ACGT':
        # Increment the count for consecutive valid characters
        count += 1
    else:
        # Reset the count if an invalid character is encountered
        count = 0
    # Update the maximum length if the current count exceeds the previous maximum
    max_length = max(max_length, count)

# Output the maximum length of consecutive valid characters found
print(max_length)

# <END-OF-CODE>
