

import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Protocol.KDF import PBKDF2
from Crypto.Util.Padding import pad, unpad
import binascii

def main():
    plain_text = input("Enter the plain text: ")
    secret_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form):", binascii.hexlify(secret_key).decode())
    cipher_text = encrypt_text(plain_text, secret_key)
    print("Encrypted Text (Hex Form):", binascii.hexlify(cipher_text).decode())
    decrypted_text = decrypt_text(cipher_text, secret_key)
    print("Decrypted Text:", decrypted_text)

def get_secret_encryption_key():
    key = get_random_bytes(16)
    return key

def encrypt_text(plain_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(pad(plain_text.encode(), AES.block_size))
    return cipher_text

def decrypt_text(cipher_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM, nonce=cipher_text[:12])
    decrypted_text = unpad(cipher.decrypt(cipher_text[12:]), AES.block_size)
    return decrypted_text.decode()

if __name__ == "__main__":
    main()

