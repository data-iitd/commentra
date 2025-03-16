
import sys

def main():
    # Read the maximum allowed length of messages
    n = int(input())

    # Read the input string containing messages
    input = input()

    # Initialize variables to track the maximum message length and store lengths of individual messages
    max = -1
    msg_length = []
    count = 0
    idx = 0

    # Iterate through each character in the input string
    for i in range(len(input)):
        c = input[i]

        # Check if the character is a message delimiter (.,?, or!)
        if c in ['.', '?', '!']:
            # Store the length of the current message and update the maximum length if necessary
            msg_length.append(count + 1)
            if count + 1 > max:
                max = count + 1

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
            l = msg_length[i]

            # Combine consecutive messages if they fit within the allowed length
            while i < idx - 1 and l + msg_length[i + 1] + 1 <= n:
                l += msg_length[i + 1] + 1
                i += 1
            ans += 1  # Increment the count of messages

        # Output the total number of messages that can be sent
        print(ans)

if __name__ == "__main__":
    main()
