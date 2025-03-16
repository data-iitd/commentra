import base64
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# The code imports necessary libraries for security and input operations.
def get_secret_encryption_key():
    # Generates a 128-bit AES key.
    return AES.generate(128)

def encrypt_text(plain_text, sec_key):
    # Encrypts the input text using AES in GCM mode.
    aes_cipher = AES.new(sec_key, AES.MODE_GCM)
    return aes_cipher.encrypt(plain_text.encode())

def decrypt_text(byte_cipher_text, sec_key):
    # Decrypts the cipher text using AES in GCM mode with the same parameters used during encryption.
    aes_cipher = AES.new(sec_key, AES.MODE_GCM, nonce=aes_cipher.nonce)
    return aes_cipher.decrypt(byte_cipher_text).decode()

def bytes_to_hex(bytes):
    # Converts byte arrays to hexadecimal strings.
    return binascii.hexlify(bytes).decode()

def main():
    plain_text = input("Enter plain text: ")
    sec_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form): " + bytes_to_hex(sec_key.key))
    cipher_text = encrypt_text(plain_text, sec_key)
    print("Encrypted Text (Hex Form): " + bytes_to_hex(cipher_text))
    decrypted_text = decrypt_text(cipher_text, sec_key)
    print("Decrypted Text: " + decrypted_text)

if __name__ == "__main__":
    main()

# END-OF-CODE
