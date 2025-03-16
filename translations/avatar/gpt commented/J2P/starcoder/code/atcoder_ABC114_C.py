import sys

# Declare a static Scanner object for input
scanner = sys.stdin

# Read an integer N from the user
N = int(input())

# Initialize a long variable i starting from 357
i = 357

# Initialize a counter to keep track of valid numbers
c = 0

# Loop until i exceeds N
while i <= N:
    # Convert the current number i to a String
    s = str(i)

    # Check if the string contains '3', '5', and '7'
    if '3' in s and '5' in s and '7' in s:
        c += 1  # Increment the counter if all digits are present

    # Create a StringBuilder to construct a new number
    sb = ''
    f = False  # Flag to indicate if a replacement has occurred

    # Iterate through the digits of the number in reverse order
    for j in range(len(s) - 1, -1, -1):
        a = s[j]  # Get the current digit

        # If a replacement has occurred, append the digit as is
        if f:
            sb += a
        else:
            # Replace '3' with '5' and set the flag
            if a == '3':
                sb += '5'
                f = True
            # Replace '5' with '7' and set the flag
            elif a == '5':
                sb += '7'
                f = True
            # If it's neither, append '3'
            else:
                sb += '3'

    # If no replacement occurred, append '3' to the StringBuilder
    if not f:
        sb += '3'

    # Reverse the constructed number and parse it back to long
    sb2 = sb[::-1]
    i = int(sb2)

    # Print the total count of valid numbers found
print(c)

# 