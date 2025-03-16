# Reading input from the user
n, s = input().split()

# Variable declaration and initialization for maximum count and current count
max_count = 0
current_count = 0

# Iterating through each character in the string 's'
for char in s:
    # Checking if the character is 'I'
    if char == 'I':
        # Incrementing the current count
        current_count += 1
    else:
        # Decrementing the current count
        current_count -= 1

    # Updating the maximum count if the current count is greater
    if current_count > max_count:
        max_count = current_count

# Printing the maximum count
print(max_count)

