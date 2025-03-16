import sys

def main():
    # Read the maximum allowed length of messages
    n = int(input().strip())
    
    # Read the input string containing messages
    input_str = input().strip()
    
    # Initialize variables to track the maximum message length and store lengths of individual messages
    max_length = -1
    msg_lengths = []
    count = 0
    idx = 0
    
    # Iterate through each character in the input string
    for i in range(len(input_str)):
        c = input_str[i]
        
        # Check if the character is a message delimiter (., ?, or !)
        if c == '.' or c == '?' or c == '!':
            # Store the length of the current message and update the maximum length if necessary
            msg_lengths.append(count + 1)
            if count + 1 > max_length:
                max_length = count + 1
            
            # Move to the next character after the delimiter
            i += 1
            count = 0  # Reset count for the next message
        else:
            # Increment the count for the current message length
            count += 1
    
    # Check if the maximum message length exceeds the allowed length
    if max_length > n:
        print("Impossible")
    else:
        # Calculate the number of messages that can fit within the allowed length
        ans = 0
        i = 0
        while i < len(msg_lengths):
            l = msg_lengths[i]
            
            # Combine consecutive messages if they fit within the allowed length
            while i < len(msg_lengths) - 1 and l + msg_lengths[i + 1] + 1 <= n:
                l += msg_lengths[i + 1] + 1
                i += 1
            ans += 1  # Increment the count of messages
            i += 1
        
        # Output the total number of messages that can be sent
        print(ans)

if __name__ == "__main__":
    main()
