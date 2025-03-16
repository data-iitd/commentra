import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend

# Private constructor to prevent instantiation of the utility class
class Main:
    def __init__(self):
        pass

    # Hexadecimal character array for converting byte arrays to hex strings
    HEX_ARRAY = "0123456789ABCDEF".encode()

    # Cipher instance for AES encryption
    aes_cipher = None

    @staticmethod
    def main():
        # Create a scanner to read user input
        plain_text = input()

        # Generate a secret AES encryption key
        sec_key = Main.get_secret_encryption_key()

        # Display the generated AES key in hexadecimal format
        print("Generated AES Key (Hex Form): " + Main.bytes_to_hex(sec_key.encode()))

        # Encrypt the plaintext using the generated secret key
        cipher_text = Main.encrypt_text(plain_text, sec_key)

        # Display the encrypted text in hexadecimal format
        print("Encrypted Text (Hex Form): " + Main.bytes_to_hex(cipher_text))

        # Decrypt the ciphertext back to plaintext
        decrypted_text = Main.decrypt_text(cipher_text, sec_key)

        # Display the decrypted text
        print("Decrypted Text: " + decrypted_text)

    @staticmethod
    def get_secret_encryption_key():
        # Generate a random secret key
        return os.urandom(16)

    @staticmethod
    def encrypt_text(plain_text, sec_key):
        # Initialize the AES cipher in encryption mode
        Main.aes_cipher = Cipher(algorithms.AES(sec_key), modes.GCM(os.urandom(12)), backend=default_backend())
        encryptor = Main.aes_cipher.encryptor()

        # Encrypt the plaintext and return the ciphertext
        padder = padding.PKCS7(128).padder()
        padded_data = padder.update(plain_text.encode()) + padder.finalize()
        return encryptor.update(padded_data) + encryptor.finalize()

    @staticmethod
    def decrypt_text(cipher_text, sec_key):
        # Create a new cipher instance for decryption
        decryptor = Cipher(algorithms.AES(sec_key), modes.GCM(Main.aes_cipher.nonce), backend=default_backend()).decryptor()

        # Decrypt the ciphertext and return the plaintext
        unpadder = padding.PKCS7(128).unpadder()
        decrypted_data = decryptor.update(cipher_text) + decryptor.finalize()
        return unpadder.update(decrypted_data).decode() + unpadder.finalize().decode()

    @staticmethod
    def bytes_to_hex(bytes):
        # Create a character array to hold the hex representation
        hex_chars = bytearray(len(bytes) * 2)

        # Convert each byte to its corresponding hex representation
        for j in range(len(bytes)):
            v = bytes[j]
            hex_chars[j * 2] = Main.HEX_ARRAY[v >> 4]
            hex_chars[j * 2 + 1] = Main.HEX_ARRAY[v & 0x0F]

        # Return the hex string
        return bytes(hex_chars).decode()

# Call the main method
Main.main()
