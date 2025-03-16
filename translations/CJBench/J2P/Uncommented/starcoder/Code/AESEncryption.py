
import base64
import os
import random
import string
import sys
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def get_secret_encryption_key():
    return AES.new(get_random_bytes(16)).key

def encrypt_text(plain_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(pad(plain_text.encode(), AES.block_size))
    return cipher_text + tag

def decrypt_text(cipher_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM)
    plain_text = cipher.decrypt(cipher_text[:-16])
    return unpad(plain_text, AES.block_size).decode()

def main():
    plain_text = input("Enter plain text: ")
    secret_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form): " + secret_key.hex())
    cipher_text = encrypt_text(plain_text, secret_key)
    print("Encrypted Text (Hex Form): " + cipher_text.hex())
    decrypted_text = decrypt_text(cipher_text, secret_key)
    print("Decrypted Text: " + decrypted_text)

if __name__ == "__main__":
    main()

