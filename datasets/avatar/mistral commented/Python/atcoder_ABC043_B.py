# Ask the user for a string input
s = str(input())

# Initialize an empty string variable to store the binary string
my_str = ''

# Iterate through each character in the user input string
for c in s:
    # If the character is '0' or '1', append it to the binary string
    if c == '0' or c == '1':
        my_str += c
    # If the character is 'B', remove the last character from the binary string before 'B' was encountered
    elif c == 'B' and len(my_str) != 0:
        my_str = my_str[:len(my_str)-1]

# Print the final binary string
print(my_str)
