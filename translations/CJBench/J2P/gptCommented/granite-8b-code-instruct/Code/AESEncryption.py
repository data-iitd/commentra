
import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# Global cipher instance for AES encryption
aesCipher = None

def main():
    # Read plaintext input from the user
    plainText = input("Enter the plaintext: ")
    
    # Generate a secret AES encryption key
    secKey = getSecretEncryptionKey()
    
    # Display the generated AES key in hexadecimal format
    print("Generated AES Key (Hex Form):", bytesToHex(secKey))
    
    # Encrypt the plaintext using the generated secret key
    cipherText = encryptText(plainText, secKey)
    
    # Display the encrypted text in hexadecimal format
    print("Encrypted Text (Hex Form):", bytesToHex(cipherText))
    
    # Decrypt the ciphertext back to plaintext
    decryptedText = decryptText(cipherText, secKey)
    
    # Display the decrypted text
    print("Decrypted Text:", decryptedText)

# Method to generate a secret AES encryption key
def getSecretEncryptionKey():
    # Generate a random 128-bit key
    secKey = get_random_bytes(16)
    
    # Return the secret key
    return secKey

# Method to encrypt plaintext using the provided secret key
def encryptText(plainText, secKey):
    # Initialize the AES cipher in encryption mode
    global aesCipher
    aesCipher = AES.new(secKey, AES.MODE_GCM)
    
    # Encrypt the plaintext and return the ciphertext
    cipherText, tag = aesCipher.encrypt_and_digest(plainText.encode())
    return cipherText

# Method to decrypt ciphertext using the provided secret key
def decryptText(byteCipherText, secKey):
    # Create a new cipher instance for decryption
    global aesCipher
    aesCipher = AES.new(secKey, AES.MODE_GCM, nonce=aesCipher.nonce)
    
    # Decrypt the ciphertext and return the plaintext
    decryptedText = aesCipher.decrypt_and_verify(byteCipherText, None)
    return decryptedText.decode()

# Method to convert a byte array to a hexadecimal string
def bytesToHex(bytes):
    # Convert the byte array to a hexadecimal string
    hexString = base64.b16encode(bytes).decode()
    
    # Return the hex string
    return hexString

if __name__ == "__main__":
    main()

