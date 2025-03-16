import os
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import unpad

def get_secret_encryption_key():
    return get_random_bytes(16)  # AES-128 key size is 16 bytes

def encrypt_text(plain_text, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(plain_text.encode('utf-8'))
    return cipher.nonce + tag + cipher_text  # Prepend nonce and tag for decryption

def decrypt_text(byte_cipher_text, sec_key):
    nonce = byte_cipher_text[:16]  # First 16 bytes are the nonce
    tag = byte_cipher_text[16:32]   # Next 16 bytes are the tag
    cipher_text = byte_cipher_text[32:]  # The rest is the cipher text
    cipher = AES.new(sec_key, AES.MODE_GCM, nonce=nonce)
    plain_text = cipher.decrypt_and_verify(cipher_text, tag)
    return plain_text.decode('utf-8')

def bytes_to_hex(byte_array):
    return binascii.hexlify(byte_array).decode('utf-8').upper()

if __name__ == "__main__":
    plain_text = input()
    sec_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form):", bytes_to_hex(sec_key))
    cipher_text = encrypt_text(plain_text, sec_key)
    print("Encrypted Text (Hex Form):", bytes_to_hex(cipher_text))
    decrypted_text = decrypt_text(cipher_text, sec_key)
    print("Decrypted Text:", decrypted_text)

# <END-OF-CODE>
