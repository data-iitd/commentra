import os
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import unpad

class Main:
    @staticmethod
    def get_secret_encryption_key():
        return get_random_bytes(16)  # Generate a new 128-bit AES key

    @staticmethod
    def encrypt_text(plain_text, sec_key):
        cipher = AES.new(sec_key, AES.MODE_GCM)  # Initialize the AES cipher for encryption
        cipher_text, tag = cipher.encrypt_and_digest(plain_text.encode('utf-8'))  # Encrypt the plain text
        return cipher.nonce + cipher_text  # Return the nonce concatenated with the ciphertext

    @staticmethod
    def decrypt_text(byte_cipher_text, sec_key):
        nonce = byte_cipher_text[:16]  # Extract the nonce from the beginning
        cipher_text = byte_cipher_text[16:]  # Extract the actual ciphertext
        cipher = AES.new(sec_key, AES.MODE_GCM, nonce=nonce)  # Initialize the AES cipher for decryption
        plain_text = cipher.decrypt(cipher_text)  # Decrypt the ciphertext
        return plain_text.decode('utf-8')  # Convert the decrypted byte array to a string

    @staticmethod
    def bytes_to_hex(byte_array):
        return binascii.hexlify(byte_array).decode('utf-8')  # Convert byte array to hex string

if __name__ == "__main__":
    plain_text = input()  # Read a line of plain text input from the user

    # Generate a new AES secret key
    sec_key = Main.get_secret_encryption_key()

    print("Generated AES Key (Hex Form):", Main.bytes_to_hex(sec_key))  # Print the generated key in hexadecimal format

    # Encrypt the plain text using the generated secret key
    cipher_text = Main.encrypt_text(plain_text, sec_key)

    print("Encrypted Text (Hex Form):", Main.bytes_to_hex(cipher_text))  # Print the encrypted text in hexadecimal format

    # Decrypt the encrypted text using the generated secret key
    decrypted_text = Main.decrypt_text(cipher_text, sec_key)

    print("Decrypted Text:", decrypted_text)  # Print the decrypted text

# <END-OF-CODE>
