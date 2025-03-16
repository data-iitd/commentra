
import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# The code imports necessary modules for security and input operations.

# The code defines the necessary functions for AES encryption/decryption.

# Generates a 128-bit AES key.
def get_secret_encryption_key():
    key = get_random_bytes(16)
    return key

# Encrypts the input text using AES in GCM mode.
def encrypt_text(plain_text, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(plain_text.encode('utf-8'))
    return cipher_text, tag, cipher.nonce

# Decrypts the cipher text using AES in GCM mode with the same parameters used during encryption.
def decrypt_text(cipher_text, tag, nonce, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM, nonce=nonce)
    plain_text = cipher.decrypt_and_verify(cipher_text, tag)
    return plain_text.decode('utf-8')

# The code reads the input text, generates an AES key, encrypts the text, and decrypts the result.
if __name__ == "__main__":
    plain_text = input("Enter the text to be encrypted: ")
    sec_key = get_secret_encryption_key()
    cipher_text, tag, nonce = encrypt_text(plain_text, sec_key)
    decrypted_text = decrypt_text(cipher_text, tag, nonce, sec_key)
    print("Generated AES Key (Hex Form):", sec_key.hex())
    print("Encrypted Text (Hex Form):", base64.b64encode(cipher_text).decode('utf-8'))
    print("Decrypted Text:", decrypted_text)

# The code ends with the comment "