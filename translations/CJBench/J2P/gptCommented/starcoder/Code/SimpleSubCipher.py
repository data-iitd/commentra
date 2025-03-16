import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

def encode(message, cipherSmall):
    encoded = "" # StringBuilder to hold the encoded message
    cipherMap = {} # Map to hold the character mapping for encoding
    beginSmallLetter = 'a' # Starting character for lowercase letters
    beginCapitalLetter = 'A' # Starting character for uppercase letters
    
    # Convert the cipher to lowercase and uppercase
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()
    
    # Populate the cipherMap with character mappings for both lowercase and uppercase letters
    for i in range(0, cipherSmall.length()):
        cipherMap[beginSmallLetter] = cipherSmall[i]
        cipherMap[beginCapitalLetter] = cipherCapital[i]
        beginSmallLetter += 1
        beginCapitalLetter += 1
    
    # Encode the message using the cipherMap
    for i in range(0, message.length()):
        if (message[i].isalpha()): # Check if the character is alphabetic
            encoded += cipherMap[message[i]] # Append the encoded character
        else:
            encoded += message[i] # Append non-alphabetic characters unchanged
    return encoded # Return the encoded message

def decode(encryptedMessage, cipherSmall):
    decoded = "" # StringBuilder to hold the decoded message
    cipherMap = {} # Map to hold the character mapping for decoding
    beginSmallLetter = 'a' # Starting character for lowercase letters
    beginCapitalLetter = 'A' # Starting character for uppercase letters
    
    # Convert the cipher to lowercase and uppercase
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()
    
    # Populate the cipherMap with character mappings for decoding
    for i in range(0, cipherSmall.length()):
        cipherMap[cipherSmall[i]] = beginSmallLetter
        cipherMap[cipherCapital[i]] = beginCapitalLetter
        beginSmallLetter += 1
        beginCapitalLetter += 1
    
    # Decode the encrypted message using the cipherMap
    for i in range(0, encryptedMessage.length()):
        if (encryptedMessage[i].isalpha()): # Check if the character is alphabetic
            decoded += cipherMap[encryptedMessage[i]] # Append the decoded character
        else:
            decoded += encryptedMessage[i] # Append non-alphabetic characters unchanged
    return decoded # Return the decoded message

def main():
    sc = Scanner(System.in) # Create a Scanner object for user input
    cipherAlphabet = sc.nextLine() # Read the cipher alphabet from user input
    operation = sc.nextLine() # Read the operation (encode/decode) from user input
    
    # Check if the operation is to encode
    if ("encode".equalsIgnoreCase(operation)):
        message = sc.nextLine() # Read the message to encode
        encryptedMessage = encode(message, cipherAlphabet) # Encode the message
        print("Encrypted Message: " + encryptedMessage) # Output the encoded message
    # Check if the operation is to decode
    elif ("decode".equalsIgnoreCase(operation)):
        encryptedMessage = sc.nextLine() # Read the encrypted message to decode
        decryptedMessage = decode(encryptedMessage, cipherAlphabet) # Decode the message
        print("Decrypted Message: " + decryptedMessage) # Output the decoded message
    # Handle invalid operation input
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")
    
    sc.close() # Close the scanner to prevent resource leaks

if __name__ == "__main__":
    main()

