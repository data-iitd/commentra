
import base64
import hashlib
import hmac
import os
import random
import string
import sys
import time
import uuid
import json
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def get_secret_encryption_key():
    return os.urandom(16)

def encrypt_text(plain_text, sec_key):
    aes_cipher = AES.new(sec_key, AES.MODE_GCM)
    cipher_text = aes_cipher.encrypt(pad(plain_text.encode(), AES.block_size))
    return cipher_text

def decrypt_text(byte_cipher_text, sec_key):
    aes_cipher = AES.new(sec_key, AES.MODE_GCM, nonce=byte_cipher_text[:16])
    plain_text = unpad(aes_cipher.decrypt(byte_cipher_text[16:]), AES.block_size)
    return plain_text

def bytes_to_hex(bytes):
    return binascii.hexlify(bytes).decode()

def main():
    plain_text = input("Enter plain text: ")
    sec_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form): " + bytes_to_hex(sec_key))
    cipher_text = encrypt_text(plain_text, sec_key)
    print("Encrypted Text (Hex Form): " + bytes_to_hex(cipher_text))
    decrypted_text = decrypt_text(cipher_text, sec_key)
    print("Decrypted Text: " + decrypted_text)

if __name__ == "__main__":
    main()

