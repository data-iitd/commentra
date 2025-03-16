
# <START-OF-CODE>

# Create a BufferedReader to read input from the console
import sys
import io

# Read the maximum allowed length of messages
n = int(input())

# Read the input string containing messages
input = input()

# Initialize variables to track the maximum message length and store lengths of individual messages
max = -1
msgLength = [0] * (len(input) // 2)
count = 0
idx = 0

# Iterate through each character in the input string
for i in range(len(input)):
    c = input[i]

    # Check if the character is a message delimiter (.,?, or!)
    if c == '.' or c == '?' or c == '!':
        # Store the length of the current message and update the maximum length if necessary
        msgLength[idx] = count + 1
        if count > max:
            max = count

        # Move to the next character after the delimiter
        i += 1
        count = 0  # Reset count for the next message
    else:
        # Increment the count for the current message length
        count += 1

# Check if the maximum message length exceeds the allowed length
if max > n:
    print("Impossible")
else:
    # Calculate the number of messages that can fit within the allowed length
    ans = 0
    for i in range(idx):
        l = msgLength[i]

        # Combine consecutive messages if they fit within the allowed length
        while i < idx - 1 and l + msgLength[i + 1] + 1 <= n:
            l += msgLength[i + 1] + 1
            i += 1
        ans += 1  # Increment the count of messages

    # Output the total number of messages that can be sent
    print(ans)

# 