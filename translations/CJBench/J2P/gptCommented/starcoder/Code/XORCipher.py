import binascii
import sys

# Default character set for encoding and decoding
CS_DEFAULT = "utf-8"

# Private constructor to prevent instantiation of the utility class
def __init__(self):
    pass

# Converts an array of bytes to a hexadecimal string representation
def bytesToHex(bytes):
    hexString = ""
    # Iterate through each byte in the array
    for b in bytes:
        # Convert byte to hex string and ensure two characters
        hex = hex(b & 0xFF)
        if len(hex) == 1:
            hexString += "0" # Append leading zero for single hex digits
        hexString += hex[2:] # Append the hex value to the string
    return hexString # Return the complete hex string

# Converts a hexadecimal string representation back to an array of bytes
def hexToBytes(hex):
    len = hex.length
    data = bytearray(len / 2) # Create byte array of half the hex string length
    # Iterate through the hex string two characters at a time
    for i in range(0, len, 2):
        # Convert each pair of hex characters to a byte
        data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                            + Character.digit(hex.charAt(i + 1), 16))
    return data # Return the byte array

# Performs XOR operation between input bytes and key bytes
def xor(inputBytes, keyBytes):
    outputBytes = bytearray(inputBytes.length) # Create output byte array
    # Iterate through each byte in the input
    for i in range(0, inputBytes.length):
        # XOR the input byte with the corresponding key byte (cyclically)
        outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length])
    return outputBytes # Return the result of the XOR operation

# Encrypts the given plaintext using the specified key
def encrypt(plainText, key):
    # Check if the key is empty and throw an exception if it is
    if key.isEmpty():
        raise Exception("Key must not be empty")
    # Convert plaintext and key to byte arrays
    plainTextBytes = plainText.getBytes(CS_DEFAULT)
    keyBytes = key.getBytes(CS_DEFAULT)
    # Perform XOR operation on plaintext and key
    xorResult = xor(plainTextBytes, keyBytes)
    # Convert the XOR result to a hex string and return it
    return bytesToHex(xorResult)

# Decrypts the given ciphertext using the specified key
def decrypt(cipherText, key):
    # Check if the key is empty and throw an exception if it is
    if key.isEmpty():
        raise Exception("Key must not be empty")
    # Convert the ciphertext from hex string to byte array
    cipherBytes = hexToBytes(cipherText)
    keyBytes = key.getBytes(CS_DEFAULT)
    # Perform XOR operation on ciphertext and key
    xorResult = xor(cipherBytes, keyBytes)
    # Convert the result back to a string and return it
    return xorResult.decode(CS_DEFAULT)

# Main method to execute the program
def main():
    # Read the operation type (encrypt or decrypt) from user input
    operation = input("Enter the operation (encrypt or decrypt): ").lower()
    key = input("Enter the key: ")
    
    # Check if the operation is encryption
    if operation == "encrypt":
        plainText = input("Enter the plaintext: ") # Read plaintext from user
        try:
            # Encrypt the plaintext and display the ciphertext
            cipherText = encrypt(plainText, key)
            print("Encrypted Message: " + cipherText)
        except Exception as e:
            # Handle empty key exception
            print(e)
    # Check if the operation is decryption
    elif operation == "decrypt":
        cipherText = input("Enter the ciphertext: ") # Read ciphertext from user
        try:
            # Decrypt the ciphertext and display the plaintext
            plainText = decrypt(cipherText, key)
            print("Decrypted Message: " + plainText)
        except Exception as e:
            # Handle empty key exception
            print(e)
    # Handle invalid operation input
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()

