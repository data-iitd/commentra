import sys

# Read the operation type (encode, decode, bruteforce) from the user input
operation = sys.stdin.readline().strip().lower()

# Check if the operation is to encode a message
if "encode" == operation:
    # Read the plaintext message to be encoded
    plaintext = sys.stdin.readline().strip()
    # Read the shift value for encoding
    shift = int(sys.stdin.readline().strip())
    # Output the encoded message
    print("Encoded Message: " + encode(plaintext, shift))

# Check if the operation is to decode a message
elif "decode" == operation:
    # Read the encrypted message to be decoded
    encryptedText = sys.stdin.readline().strip()
    # Read the shift value for decoding
    shift = int(sys.stdin.readline().strip())
    # Output the decoded message
    print("Decoded Message: " + decode(encryptedText, shift))

# Check if the operation is to perform a brute force attack
elif "bruteforce" == operation:
    # Read the encrypted message for brute force decoding
    encryptedText = sys.stdin.readline().strip()
    # Get all possible decoded messages using brute force
    possibleSolutions = bruteforce(encryptedText)
    # Print all possible solutions with their respective shift values
    for i in range(len(possibleSolutions)):
        print("Shift " + str(i) + ": " + possibleSolutions[i])

# Handle invalid operation input
else:
    print("Invalid operation. Please enter encode, decode, or bruteforce.")

# Close the scanner to prevent resource leaks
sys.stdin.close()

# END-OF-CODE
