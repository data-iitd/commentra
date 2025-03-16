
s = str(input())  # Take a string input from the user
my_str = ''  # Initialize an empty string to build the result

# Iterate over each character in the input string `s`
for c in s:
    if c == '0' or c == '1':  # Check if the character is '0' or '1'
        my_str += c  # Append the character to `my_str`
    elif c == 'B' and len(my_str) != 0:  # Check if the character is 'B' and `my_str` is not empty
        my_str = my_str[:len(my_str) - 1]  # Remove the last character from `my_str`

print(my_str)  # Print the content of `my_str`


