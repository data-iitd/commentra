
import sys

def main():
    n = int(input()) # Reading the maximum length for each message
    input = input() # Reading the input text

    max = -1 # Initializing the maximum message length to -1
    msgLength = [] # Initializing an array to store the lengths of each message
    count = 0 # Initializing a counter for the current message length

    # Iterating through the input string to determine message lengths
    for c in input:
        if c in ['.', '?', '!']:
            msgLength.append(count + 1) # Storing the length of the current message and incrementing the index
            if count + 1 > max: max = count + 1 # Updating the maximum message length if necessary
            count = 0 # Resetting the counter for the next message
        else:
            count += 1 # Incrementing the counter for the current message length

    # Checking if the maximum message length exceeds the allowed maximum
    if max > n:
        print("Impossible") # Printing "Impossible" if the maximum message length is too large
    else:
        ans = 0 # Initializing the answer variable to store the number of messages
        for i in range(len(msgLength)):
            l = msgLength[i] # Getting the length of the current message
            while i < len(msgLength) - 1 and l + msgLength[i + 1] + 1 <= n:
                l += msgLength[i + 1] + 1 # Grouping messages that fit within the maximum length
                i += 1 # Moving to the next message
            ans += 1 # Incrementing the answer as we have a complete message
        print(ans) # Printing the total number of messages required

if __name__ == "__main__":
    main()

