import java.util.HashMap; // Importing HashMap and Map for creating a cipher map
import java.util.Map; // Importing Map for creating a cipher map
import java.util.Scanner; // Importing Scanner for reading input from the user

def encode(message, cipherSmall): # Method to encode a message using a cipher alphabet
    encoded = "" # String to build the encoded message
    cipherMap = {} # Map to store the cipher alphabet
    beginSmallLetter = 'a' # Starting character for small letters
    beginCapitalLetter = 'A' # Starting character for capital letters
    cipherSmall = cipherSmall.lower() # Converting cipherSmall to lowercase
    cipherCapital = cipherSmall.upper() # Creating an uppercase version of cipherSmall
    for i in range(0, cipherSmall.length()): # Populating the cipher map
        cipherMap[beginSmallLetter] = cipherSmall[i] # Mapping small letters
        cipherMap[beginCapitalLetter] = cipherCapital[i] # Mapping capital letters
        beginSmallLetter += 1 # Incrementing the starting character for small letters
        beginCapitalLetter += 1 # Incrementing the starting character for capital letters
    for i in range(0, message.length()): # Iterating through the message
        if message[i].isalpha(): # Checking if the character is alphabetic
            encoded += cipherMap[message[i]] # Appending the encoded character
        else:
            encoded += message[i] # Appending non-alphabetic characters unchanged
    return encoded # Returning the encoded message

def decode(encryptedMessage, cipherSmall): # Method to decode an encrypted message using a cipher alphabet
    decoded = "" # String to build the decoded message
    cipherMap = {} # Map to store the cipher alphabet
    beginSmallLetter = 'a' # Starting character for small letters
    beginCapitalLetter = 'A' # Starting character for capital letters
    cipherSmall = cipherSmall.lower() # Converting cipherSmall to lowercase
    cipherCapital = cipherSmall.upper() # Creating an uppercase version of cipherSmall
    for i in range(0, cipherSmall.length()): # Populating the cipher map
        cipherMap[cipherSmall[i]] = beginSmallLetter # Mapping small letters
        cipherMap[cipherCapital[i]] = beginCapitalLetter # Mapping capital letters
        beginSmallLetter += 1 # Incrementing the starting character for small letters
        beginCapitalLetter += 1 # Incrementing the starting character for capital letters
    for i in range(0, encryptedMessage.length()): # Iterating through the encrypted message
        if encryptedMessage[i].isalpha(): # Checking if the character is alphabetic
            decoded += cipherMap[encryptedMessage[i]] # Appending the decoded character
        else:
            decoded += encryptedMessage[i] # Appending non-alphabetic characters unchanged
    return decoded # Returning the decoded message

if __name__ == "__main__": # Main method - entry point of the program
    sc = Scanner(System.in) # Creating a Scanner object to read input
    cipherAlphabet = sc.nextLine() # Reading the cipher alphabet from the user
    operation = sc.nextLine() # Reading the operation type (encode or decode) from the user
    if "encode".equalsIgnoreCase(operation): # Checking if the operation is encode
        message = sc.nextLine() # Reading the message to be encoded
        encryptedMessage = encode(message, cipherAlphabet) # Encoding the message
        print("Encrypted Message: " + encryptedMessage) # Printing the encrypted message
    elif "decode".equalsIgnoreCase(operation): # Checking if the operation is decode
        encryptedMessage = sc.nextLine() # Reading the encrypted message to be decoded
        decryptedMessage = decode(encryptedMessage, cipherAlphabet) # Decoding the message
        print("Decrypted Message: " + decryptedMessage) # Printing the decrypted message
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.") # Printing an error message for invalid operation
    sc.close() # Closing the Scanner

