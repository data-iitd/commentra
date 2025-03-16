
import binascii
import sys

# Declare the default character set for UTF-8 encoding
CS_DEFAULT = "utf-8"

# Converts a byte array to a hexadecimal string
def bytesToHex(bytes):
    hexString = ""
    for b in bytes:
        # Convert a single byte to hexadecimal string
        hex = hex(b & 0xFF)
        # Add a leading zero if the hexadecimal string has only one character
        if len(hex) == 3:
            hex = "0" + hex[2:]
        hexString += hex[2:]
    return hexString

# Converts a hexadecimal string to a byte array
def hexToBytes(hex):
    len = hex.length
    data = bytearray(len // 2)
    for i in range(0, len, 2):
        # Extract two hexadecimal digits and convert them to a byte
        data[i // 2] = (byte) ((int(hex[i], 16) << 4) + int(hex[i + 1], 16))
    return data

# XOR operation between two byte arrays
def xor(inputBytes, keyBytes):
    outputBytes = bytearray(inputBytes.length)
    for i in range(0, inputBytes.length):
        # Perform XOR operation between each byte of inputBytes and keyBytes
        outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length])
    return outputBytes

# Encrypts a plain text using the provided key
def encrypt(plainText, key):
    if key == "":
        raise Exception("Key must not be empty")
    # Convert plain text to byte array
    plainTextBytes = plainText.encode(CS_DEFAULT)
    # Convert key to byte array
    keyBytes = key.encode(CS_DEFAULT)
    # Perform XOR operation between plainTextBytes and keyBytes
    xorResult = xor(plainTextBytes, keyBytes)
    # Convert the XOR result to hexadecimal string
    return bytesToHex(xorResult)

# Decrypts a cipher text using the provided key
def decrypt(cipherText, key):
    if key == "":
        raise Exception("Key must not be empty")
    # Convert cipher text to byte array
    cipherBytes = hexToBytes(cipherText)
    # Convert key to byte array
    keyBytes = key.encode(CS_DEFAULT)
    # Perform XOR operation between cipherBytes and keyBytes
    xorResult = xor(cipherBytes, keyBytes)
    # Convert the XOR result to a string using the default character set
    return xorResult.decode(CS_DEFAULT)

# Main method to read user input and perform encryption or decryption
def main():
    # Read the operation ('encrypt' or 'decrypt')
    operation = input().lower()
    # Request the user to enter the key
    print("Enter the key: ", end="")
    key = input()

    if operation == "encrypt":
        # Read the plain text from the user
        plainText = input()
        try:
            # Encrypt the plain text using the key
            cipherText = encrypt(plainText, key)
            # Print the encrypted message
            print("Encrypted Message: " + cipherText)
        except Exception as e:
            # Print an error message if the key is empty
            print(e)
    elif operation == "decrypt":
        # Read the cipher text from the user
        cipherText = input()
        try:
            # Decrypt the cipher text using the key
            plainText = decrypt(cipherText, key)
            # Print the decrypted message
            print("Decrypted Message: " + plainText)
        except Exception as e:
            # Print an error message if the key is empty
            print(e)
    else:
        # Print an error message for invalid operation
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()

