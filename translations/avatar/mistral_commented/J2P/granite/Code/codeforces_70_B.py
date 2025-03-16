

import sys

def main():
    n = int(input()) # Read the number of messages
    input = sys.stdin.readline().strip() # Read the string of messages

    max = -1 # Initialize max to -1
    msgLength = [] # Initialize msgLength list
    count = 0 # Initialize count to 0
    idx = 0 # Initialize index to 0

    # Loop through each character in the input string
    for i in range(len(input)):
        c = input[i] # Read the character at index i

        if c in ['.', '?', '!']: # If character is a question mark, exclamation mark or period
            msgLength.append(count + 1) # Increment count and store it in msgLength list
            if count > max: max = count # Update max if count is greater than current max
            i += 1 # Increment i as we have read one more character
            count = 0 # Reset count as we have started a new message
        else: count += 1 # Increment count if character is not a question mark, exclamation mark or period

    # Check if the total length of messages is greater than n
    if max > n:
        print("Impossible") # Print "Impossible" if total length is greater than n
        return

    ans = 0 # Initialize answer to 0

    # Loop through each message and find the maximum number of messages that can be sent
    for i in range(len(msgLength)):
        l = msgLength[i] # Initialize length of current message

        while i < len(msgLength) - 1 and l + msgLength[i + 1] + 1 <= n: # While we can add next message to current message
            l += msgLength[i + 1] + 1 # Add length of next message and 1 for separator
            i += 1 # Increment i to move to next message
        ans += 1 # Increment answer as we have added one more message

    print(ans) # Print the answer

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!