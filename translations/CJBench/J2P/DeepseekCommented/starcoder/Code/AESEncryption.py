import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

# The code imports necessary classes for security and input operations.
class Main:
    def __init__(self):
        pass

    # Private constructor to prevent instantiation of the Main class.
    def getSecretEncryptionKey(self):
        aesKeyGenerator = AES.new(os.urandom(16), AES.MODE_GCM)
        return aesKeyGenerator.key

    # Encrypts the input text using AES in GCM mode.
    def encryptText(self, plainText, secKey):
        aesCipher = AES.new(secKey, AES.MODE_GCM)
        return aesCipher.encrypt(plainText)

    # Decrypts the cipher text using AES in GCM mode with the same parameters used during encryption.
    def decryptText(self, byteCipherText, secKey):
        aesCipher = AES.new(secKey, AES.MODE_GCM)
        return aesCipher.decrypt(byteCipherText)

    # Converts byte arrays to hexadecimal strings.
    def bytesToHex(self, bytes):
        return ''.join('{:02x}'.format(x) for x in bytes)

# The code is executed only if the file is executed as a script.
if __name__ == "__main__":
    main = Main()
    plainText = input("Enter the text to be encrypted: ")
    secKey = main.getSecretEncryptionKey()
    print("Generated AES Key (Hex Form): " + main.bytesToHex(secKey))
    cipherText = main.encryptText(plainText, secKey)
    print("Encrypted Text (Hex Form): " + main.bytesToHex(cipherText))
    decryptedText = main.decryptText(cipherText, secKey)
    print("Decrypted Text: " + decryptedText)

