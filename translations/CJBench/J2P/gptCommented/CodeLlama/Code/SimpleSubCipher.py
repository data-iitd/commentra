import string

def encode(message, cipher):
    encoded = ""
    cipherMap = {}
    beginSmallLetter = 'a'
    beginCapitalLetter = 'A'
    
    # Convert the cipher to lowercase and uppercase
    cipher = cipher.lower()
    cipherCapital = cipher.upper()
    
    # Populate the cipherMap with character mappings for encoding
    for i in range(len(cipher)):
        cipherMap[beginSmallLetter] = cipher[i]
        cipherMap[beginCapitalLetter] = cipherCapital[i]
        beginSmallLetter = chr(ord(beginSmallLetter) + 1)
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1)
    
    # Encode the message using the cipherMap
    for i in range(len(message)):
        if message[i].isalpha():
            encoded += cipherMap[message[i]]
        else:
            encoded += message[i]
    
    return encoded

def decode(encryptedMessage, cipher):
    decoded = ""
    cipherMap = {}
    beginSmallLetter = 'a'
    beginCapitalLetter = 'A'
    
    # Convert the cipher to lowercase and uppercase
    cipher = cipher.lower()
    cipherCapital = cipher.upper()
    
    # Populate the cipherMap with character mappings for decoding
    for i in range(len(cipher)):
        cipherMap[cipher[i]] = beginSmallLetter
        cipherMap[cipherCapital[i]] = beginCapitalLetter
        beginSmallLetter = chr(ord(beginSmallLetter) + 1)
        beginCapitalLetter = chr(ord(beginCapitalLetter) + 1)
    
    # Decode the encrypted message using the cipherMap
    for i in range(len(encryptedMessage)):
        if encryptedMessage[i].isalpha():
            decoded += cipherMap[encryptedMessage[i]]
        else:
            decoded += encryptedMessage[i]
    
    return decoded

# Main method to execute the program
if __name__ == "__main__":
    cipherAlphabet = input()
    operation = input()
    
    # Check if the operation is to encode
    if operation.lower() == "encode":
        message = input()
        encryptedMessage = encode(message, cipherAlphabet)
        print("Encrypted Message:", encryptedMessage)
    # Check if the operation is to decode
    elif operation.lower() == "decode":
        encryptedMessage = input()
        decryptedMessage = decode(encryptedMessage, cipherAlphabet)
        print("Decrypted Message:", decryptedMessage)
    # Handle invalid operation input
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

