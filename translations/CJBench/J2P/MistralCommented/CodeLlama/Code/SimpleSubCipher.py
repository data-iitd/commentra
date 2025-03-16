
import sys

def encode(message, cipherSmall):
    encoded = "" # Initialize an empty string to store the encoded message

    cipherMap = {} # Create an empty dictionary to store the cipher mapping

    beginSmallLetter = 'a' # Initialize the small letter index to 'a'
    beginCapitalLetter = 'A' # Initialize the capital letter index to 'A'

    # Set the cipher alphabet for small and capital letters
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()

    # Build the cipher map by iterating through the cipher alphabet
    for i in range(len(cipherSmall)):
        cipherMap[beginSmallLetter] = cipherSmall[i] # Map small letters
        cipherMap[beginCapitalLetter] = cipherCapital[i] # Map capital letters
        beginSmallLetter = chr(ord(beginSmallLetter) + 1) # Increment the small letter index
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1) # Increment the capital letter index

    # Iterate through the message and encode each character
    for i in range(len(message)):
        if message[i].isalpha(): # If the character is alphabetic
            encoded += cipherMap[message[i]] # Append the encoded character to the string
        else:
            encoded += message[i] # If the character is not alphabetic, append it as is

    # Return the encoded message as a string
    return encoded

def decode(encryptedMessage, cipherSmall):
    decoded = "" # Initialize an empty string to store the decoded message

    cipherMap = {} # Create an empty dictionary to store the cipher mapping

    beginSmallLetter = 'a' # Initialize the small letter index to 'a'
    beginCapitalLetter = 'A' # Initialize the capital letter index to 'A'

    # Set the cipher alphabet for small and capital letters
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()

    # Build the cipher map by iterating through the cipher alphabet
    for i in range(len(cipherSmall)):
        cipherMap[cipherSmall[i]] = beginSmallLetter # Map small letters
        cipherMap[cipherCapital[i]] = beginCapitalLetter # Map capital letters
        beginSmallLetter = chr(ord(beginSmallLetter) + 1) # Increment the small letter index
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1) # Increment the capital letter index

    # Iterate through the encrypted message and decode each character
    for i in range(len(encryptedMessage)):
        if encryptedMessage[i].isalpha(): # If the character is alphabetic
            decoded += cipherMap[encryptedMessage[i]] # Append the decoded character to the string
        else:
            decoded += encryptedMessage[i] # If the character is not alphabetic, append it as is

    # Return the decoded message as a string
    return decoded

# Main method to read user input and call the appropriate encoding or decoding method
if __name__ == "__main__":
    cipherAlphabet = sys.stdin.readline().strip() # Read the cipher alphabet from user input
    operation = sys.stdin.readline().strip() # Read the operation ('encode' or 'decode') from user input

    if operation == "encode": # If the operation is 'encode'
        message = sys.stdin.readline().strip() # Read the message to be encoded from user input
        encryptedMessage = encode(message, cipherAlphabet) # Call the encode method and store the result
        print("Encrypted Message: " + encryptedMessage) # Print the encrypted message to the console
    elif operation == "decode": # If the operation is 'decode'
        encryptedMessage = sys.stdin.readline().strip() # Read the encrypted message from user input
        decryptedMessage = decode(encryptedMessage, cipherAlphabet) # Call the decode method and store the result
        print("Decrypted Message: " + decryptedMessage) # Print the decrypted message to the console
    else: # If the operation is not 'encode' or 'decode'
        print("Invalid operation. Please enter 'encode' or 'decode'.") # Print an error message to the console

