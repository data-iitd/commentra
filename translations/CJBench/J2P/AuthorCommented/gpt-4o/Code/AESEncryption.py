import os
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import unpad

def bytes_to_hex(byte_array):
    return binascii.hexlify(byte_array).decode('utf-8').upper()

def get_secret_encryption_key():
    return get_random_bytes(16)  # AES key size in bytes (128 bits)

def encrypt_text(plain_text, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(plain_text.encode('utf-8'))
    return cipher.nonce + tag + cipher_text  # Prepend nonce and tag for decryption

def decrypt_text(cipher_text, sec_key):
    nonce = cipher_text[:16]  # First 16 bytes are the nonce
    tag = cipher_text[16:32]  # Next 16 bytes are the tag
    encrypted_message = cipher_text[32:]  # The rest is the encrypted message
    cipher = AES.new(sec_key, AES.MODE_GCM, nonce=nonce)
    plain_text = cipher.decrypt_and_verify(encrypted_message, tag)
    return plain_text.decode('utf-8')

def main():
    plain_text = input("Enter the text to encrypt: ")

    sec_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form):", bytes_to_hex(sec_key))

    # Encrypt text
    cipher_text = encrypt_text(plain_text, sec_key)
    print("Encrypted Text (Hex Form):", bytes_to_hex(cipher_text))

    # Decrypt text
    decrypted_text = decrypt_text(cipher_text, sec_key)
    print("Decrypted Text:", decrypted_text)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
