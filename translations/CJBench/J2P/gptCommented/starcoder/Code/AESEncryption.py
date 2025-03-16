import base64
import os
import random
import string
import sys
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# Private constructor to prevent instantiation of the utility class
class Main:
    # Hexadecimal character array for converting byte arrays to hex strings
    HEX_ARRAY = "0123456789ABCDEF".encode()

    # Cipher instance for AES encryption
    aesCipher = None

    # Method to generate a secret AES encryption key
    def getSecretEncryptionKey(self):
        # Create a KeyGenerator for AES
        aesKeyGenerator = AES.new(os.urandom(16))

        # Generate and return the secret key
        return aesKeyGenerator.key

    # Method to encrypt plaintext using the provided secret key
    def encryptText(self, plainText, secKey):
        # Initialize the AES cipher in encryption mode
        self.aesCipher = AES.new(secKey, AES.MODE_GCM)

        # Encrypt the plaintext and return the ciphertext
        return self.aesCipher.encrypt(plainText.encode())

    # Method to decrypt ciphertext using the provided secret key
    def decryptText(self, byteCipherText, secKey):
        # Create a new cipher instance for decryption
        decryptionCipher = AES.new(secKey, AES.MODE_GCM, nonce=self.aesCipher.nonce)

        # Decrypt the ciphertext and return the plaintext
        return decryptionCipher.decrypt(byteCipherText).decode()

    # Method to convert a byte array to a hexadecimal string
    def bytesToHex(self, bytes):
        # Create a character array to hold the hex representation
        hexChars = [0] * (len(bytes) * 2)

        # Convert each byte to its corresponding hex representation
        for j in range(len(bytes)):
            v = bytes[j] & 0xFF
            hexChars[j * 2] = self.HEX_ARRAY[v >>> 4]
            hexChars[j * 2 + 1] = self.HEX_ARRAY[v & 0x0F]

        # Return the hex string
        return ''.join(hexChars)

# Main method
if __name__ == "__main__":
    # Create a Main instance
    main = Main()

    # Read plaintext input from the user
    plainText = input("Enter the plaintext: ")

    # Generate a secret AES encryption key
    secKey = main.getSecretEncryptionKey()

    # Display the generated AES key in hexadecimal format
    print("Generated AES Key (Hex Form): " + main.bytesToHex(secKey))

    # Encrypt the plaintext using the generated secret key
    cipherText = main.encryptText(plainText, secKey)

    # Display the encrypted text in hexadecimal format
    print("Encrypted Text (Hex Form): " + main.bytesToHex(cipherText))

    # Decrypt the ciphertext back to plaintext
    decryptedText = main.decryptText(cipherText, secKey)

    # Display the decrypted text
    print("Decrypted Text: " + decryptedText)

