import string // Importing string for creating a cipher map

def encode(message, cipherSmall): // Method to encode a message using a cipher alphabet
    encoded = "" // Initializing the encoded message
    cipherMap = {} // Initializing the cipher map
    beginSmallLetter = 'a' // Starting character for small letters
    beginCapitalLetter = 'A' // Starting character for capital letters
    cipherSmall = cipherSmall.lower() // Converting cipherSmall to lowercase
    cipherCapital = cipherSmall.upper() // Creating an uppercase version of cipherSmall
    for i in range(len(cipherSmall)): // Populating the cipher map
        cipherMap[beginSmallLetter] = cipherSmall[i] // Mapping small letters
        cipherMap[beginCapitalLetter] = cipherCapital[i] // Mapping capital letters
        beginSmallLetter = chr(ord(beginSmallLetter) + 1) // Incrementing the small letter
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1) // Incrementing the capital letter
    for i in range(len(message)): // Iterating through the message
        if message[i].isalpha(): // Checking if the character is alphabetic
            encoded += cipherMap[message[i]] // Appending the encoded character
        else:
            encoded += message[i] // Appending non-alphabetic characters unchanged
    return encoded // Returning the encoded message

def decode(encryptedMessage, cipherSmall): // Method to decode an encrypted message using a cipher alphabet
    decoded = "" // Initializing the decoded message
    cipherMap = {} // Initializing the cipher map
    beginSmallLetter = 'a' // Starting character for small letters
    beginCapitalLetter = 'A' // Starting character for capital letters
    cipherSmall = cipherSmall.lower() // Converting cipherSmall to lowercase
    cipherCapital = cipherSmall.upper() // Creating an uppercase version of cipherSmall
    for i in range(len(cipherSmall)): // Populating the cipher map
        cipherMap[cipherSmall[i]] = beginSmallLetter // Mapping small letters
        cipherMap[cipherCapital[i]] = beginCapitalLetter // Mapping capital letters
        beginSmallLetter = chr(ord(beginSmallLetter) + 1) // Incrementing the small letter
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1) // Incrementing the capital letter
    for i in range(len(encryptedMessage)): // Iterating through the encrypted message
        if encryptedMessage[i].isalpha(): // Checking if the character is alphabetic
            decoded += cipherMap[encryptedMessage[i]] // Appending the decoded character
        else:
            decoded += encryptedMessage[i] // Appending non-alphabetic characters unchanged
    return decoded // Returning the decoded message

if __name__ == "__main__": // Main method - entry point of the program
    cipherAlphabet = input("Enter the cipher alphabet: ") // Reading the cipher alphabet from the user
    operation = input("Enter the operation type (encode or decode): ") // Reading the operation type (encode or decode) from the user
    if operation.lower() == "encode": // Checking if the operation is encode
        message = input("Enter the message to be encoded: ") // Reading the message to be encoded
        encryptedMessage = encode(message, cipherAlphabet) // Encoding the message
        print("Encrypted Message:", encryptedMessage) // Printing the encrypted message
    elif operation.lower() == "decode": // Checking if the operation is decode
        encryptedMessage = input("Enter the encrypted message to be decoded: ") // Reading the encrypted message to be decoded
        decryptedMessage = decode(encryptedMessage, cipherAlphabet) // Decoding the message
        print("Decrypted Message:", decryptedMessage) // Printing the decrypted message
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.") // Printing an error message for invalid operation

