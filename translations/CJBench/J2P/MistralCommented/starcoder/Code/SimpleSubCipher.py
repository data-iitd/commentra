
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

def encode(message, cipherSmall):
    encoded = "" # Initialize an empty string to store the encoded message

    cipherMap = {} # Create an empty HashMap to store the cipher mapping

    beginSmallLetter = 'a' # Initialize the small letter index to 'a'
    beginCapitalLetter = 'A' # Initialize the capital letter index to 'A'

    # Set the cipher alphabet for small and capital letters
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()

    # Build the cipher map by iterating through the cipher alphabet
    for i in range(0, cipherSmall.length()):
        cipherMap[beginSmallLetter] = cipherSmall[i] # Map small letters
        cipherMap[beginCapitalLetter] = cipherCapital[i] # Map capital letters
        beginSmallLetter += 1
        beginCapitalLetter += 1

    # Iterate through the message and encode each character
    for i in range(0, message.length()):
        if (message[i].isalpha()): # If the character is alphabetic
            encoded += cipherMap[message[i]] # Append the encoded character to the StringBuilder
        else:
            encoded += message[i] # If the character is not alphabetic, append it as is

    # Return the encoded message as a String
    return encoded

def decode(encryptedMessage, cipherSmall):
    decoded = "" # Initialize an empty string to store the decoded message

    cipherMap = {} # Create an empty HashMap to store the cipher mapping

    beginSmallLetter = 'a' # Initialize the small letter index to 'a'
    beginCapitalLetter = 'A' # Initialize the capital letter index to 'A'

    # Set the cipher alphabet for small and capital letters
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()

    # Build the cipher map by iterating through the cipher alphabet
    for i in range(0, cipherSmall.length()):
        cipherMap[cipherSmall[i]] = beginSmallLetter # Map small letters
        cipherMap[cipherCapital[i]] = beginCapitalLetter # Map capital letters
        beginSmallLetter += 1
        beginCapitalLetter += 1

    # Iterate through the encrypted message and decode each character
    for i in range(0, encryptedMessage.length()):
        if (encryptedMessage[i].isalpha()): # If the character is alphabetic
            decoded += cipherMap[encryptedMessage[i]] # Append the decoded character to the StringBuilder
        else:
            decoded += encryptedMessage[i] # If the character is not alphabetic, append it as is

    # Return the decoded message as a String
    return decoded

if __name__ == "__main__":
    sc = Scanner(System.in) # Initialize a Scanner to read user input

    cipherAlphabet = sc.nextLine() # Read the cipher alphabet from user input
    operation = sc.nextLine() # Read the operation ('encode' or 'decode') from user input

    if ("encode".equalsIgnoreCase(operation)): # If the operation is 'encode'
        message = sc.nextLine() # Read the message to be encoded from user input
        encryptedMessage = encode(message, cipherAlphabet) # Call the encode method and store the result
        print("Encrypted Message: " + encryptedMessage) # Print the encrypted message to the console
    elif ("decode".equalsIgnoreCase(operation)): # If the operation is 'decode'
        encryptedMessage = sc.nextLine() # Read the encrypted message from user input
        decryptedMessage = decode(encryptedMessage, cipherAlphabet) # Call the decode method and store the result
        print("Decrypted Message: " + decryptedMessage) # Print the decrypted message to the console
    else: # If the operation is not 'encode' or 'decode'
        print("Invalid operation. Please enter 'encode' or 'decode'.") # Print an error message to the console

    sc.close() # Close the Scanner to free system resources

