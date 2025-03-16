

import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

def main():
    plain_text = input("Enter plain text: ")
    secret_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form):", secret_key.hex())
    cipher_text = encrypt_text(plain_text, secret_key)
    print("Encrypted Text (Hex Form):", cipher_text.hex())
    decrypted_text = decrypt_text(cipher_text, secret_key)
    print("Decrypted Text:", decrypted_text)

def get_secret_encryption_key():
    key = get_random_bytes(16)
    return key

def encrypt_text(plain_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM)
    ciphertext, tag = cipher.encrypt_and_digest(plain_text.encode())
    return ciphertext

def decrypt_text(cipher_text, secret_key):
    cipher = AES.new(secret_key, AES.MODE_GCM, nonce=cipher_text[:12])
    decrypted_text = cipher.decrypt_and_verify(cipher_text[12:], cipher_text[12:])
    return decrypted_text.decode()

if __name__ == "__main__":
    main()

