import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the maximum length for each message
    input_text = sys.stdin.readline().strip()  # Reading the input text

    max_length = -1  # Initializing the maximum message length to -1
    msg_length = []  # List to store the lengths of each message
    count = 0  # Initializing a counter for the current message length

    # Iterating through the input string to determine message lengths
    for c in input_text:
        if c in {'.', '?', '!'}:  # Check for message delimiters
            msg_length.append(count + 1)  # Storing the length of the current message
            max_length = max(max_length, count + 1)  # Updating the maximum message length if necessary
            count = 0  # Resetting the counter for the next message
        else:
            count += 1  # Incrementing the counter for the current message length

    # Checking if the maximum message length exceeds the allowed maximum
    if max_length > n:
        print("Impossible")  # Printing "Impossible" if the maximum message length is too large
    else:
        ans = 0  # Initializing the answer variable to store the number of messages
        i = 0  # Index for the msg_length list
        while i < len(msg_length):
            l = msg_length[i]  # Getting the length of the current message
            while i < len(msg_length) - 1 and l + msg_length[i + 1] + 1 <= n:
                l += msg_length[i + 1] + 1  # Grouping messages that fit within the maximum length
                i += 1  # Moving to the next message
            ans += 1  # Incrementing the answer as we have a complete message
            i += 1  # Move to the next message

        print(ans)  # Printing the total number of messages required

if __name__ == "__main__":
    main()

# <END-OF-CODE>
