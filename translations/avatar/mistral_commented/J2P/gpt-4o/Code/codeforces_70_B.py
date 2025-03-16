import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of messages
    input_string = sys.stdin.readline().strip()  # Read the string of messages

    max_length = -1  # Initialize max_length to -1
    msg_length = []  # Initialize msg_length list
    count = 0  # Initialize count to 0
    idx = 0  # Initialize index to 0

    # Loop through each character in the input string
    for i in range(len(input_string)):
        c = input_string[i]  # Read the character at index i

        if c in ['.', '?', '!']:  # If character is a question mark, exclamation mark or period
            msg_length.append(count + 1)  # Store the length of the message
            count = 0  # Reset count as we have started a new message
            idx += 1  # Increment index
        else:
            count += 1  # Increment count if character is not a question mark, exclamation mark or period

    # Check if the total length of messages is greater than n
    if max(msg_length, default=0) > n:
        print("Impossible")  # Print "Impossible" if total length is greater than n
        return

    ans = 0  # Initialize answer to 0

    # Loop through each message and find the maximum number of messages that can be sent
    i = 0
    while i < idx:
        l = msg_length[i]  # Initialize length of current message

        while i < idx - 1 and l + msg_length[i + 1] + 1 <= n:  # While we can add next message to current message
            l += msg_length[i + 1] + 1  # Add length of next message and 1 for separator
            i += 1  # Increment i to move to next message
        ans += 1  # Increment answer as we have added one more message
        i += 1  # Move to the next message

    print(ans)  # Print the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
