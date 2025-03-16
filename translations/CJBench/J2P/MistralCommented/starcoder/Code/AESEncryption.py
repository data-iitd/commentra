
import base64
import os
import secrets
import sys
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# Declare a character array for Hex conversion
HEX_ARRAY = "0123456789ABCDEF".encode()

# Initialize the AES cipher for encryption and decryption
aesCipher = None

def main():
    # Read a line of plain text input from the user
    plainText = sys.stdin.readline().strip()

    # Generate a new AES secret key
    secKey = getSecretEncryptionKey()

    # Print the generated key in hexadecimal format
    print("Generated AES Key (Hex Form): " + bytesToHex(secKey.encode()))

    # Encrypt the plain text using the generated secret key
    cipherText = encryptText(plainText, secKey)

    # Print the encrypted text in hexadecimal format
    print("Encrypted Text (Hex Form): " + bytesToHex(cipherText))

    # Decrypt the encrypted text using the generated secret key
    decryptedText = decryptText(cipherText, secKey)

    # Print the decrypted text
    print("Decrypted Text: " + decryptedText)

# Generate a new AES secret key using the KeyGenerator
def getSecretEncryptionKey():
    aesKeyGenerator = AES.new(get_random_bytes(16)) # Initialize the AES key generator
    return aesKeyGenerator.key # Generate a new secret key

# Encrypt the plain text using the AES cipher in GCM mode
def encryptText(plainText, secKey):
    global aesCipher
    aesCipher = AES.new(secKey, AES.MODE_GCM) # Initialize the AES cipher for encryption
    return aesCipher.encrypt(plainText.encode()) # Encrypt the plain text and return the ciphertext

# Decrypt the ciphertext using the AES cipher in GCM mode
def decryptText(byteCipherText, secKey):
    global aesCipher
    aesCipher = AES.new(secKey, AES.MODE_GCM, nonce=aesCipher.nonce) # Initialize the AES cipher for decryption
    return aesCipher.decrypt(byteCipherText).decode() # Decrypt the ciphertext and return the plaintext

# Convert a byte array to a hexadecimal string
def bytesToHex(bytes):
    return base64.b16encode(bytes).decode() # Convert the byte array to a hexadecimal string and return it

if __name__ == "__main__":
    main()

