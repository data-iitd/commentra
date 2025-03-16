
# Import modules
import string

# Define cipher alphabet
cipherAlphabet = 'abcdefghijklmnopqrstuvwxyz'

# Define cipher map
cipherMap = {}

# Create cipher map for encoding
for i in range(len(cipherAlphabet)):
    cipherMap[cipherAlphabet[i]] = cipherAlphabet[i + 1]

# Create cipher map for decoding
for i in range(len(cipherAlphabet)):
    cipherMap[cipherAlphabet[i + 1]] = cipherAlphabet[i]

# Define operation
operation = input("Enter 'encode' or 'decode': ")

# Define message
message = input("Enter message: ")

# Define encrypted message
encryptedMessage = ''

# Define decrypted message
decryptedMessage = ''

# Encode message
if operation.lower() == 'encode':
    for i in range(len(message)):
        if message[i].isalpha():
            encryptedMessage += cipherMap[message[i]]
        else:
            encryptedMessage += message[i]

    print("Encrypted Message: " + encryptedMessage)

# Decode message
elif operation.lower() == 'decode':
    for i in range(len(message)):
        if message[i].isalpha():
            decryptedMessage += cipherMap[message[i]]
        else:
            decryptedMessage += message[i]

    print("Decrypted Message: " + decryptedMessage)

# Invalid operation
else:
    print("Invalid operation. Please enter 'encode' or 'decode'.")

