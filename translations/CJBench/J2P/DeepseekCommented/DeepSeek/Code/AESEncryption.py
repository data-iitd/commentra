import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend

# The code imports necessary classes for security and input operations.

# Private constructor to prevent instantiation of the Main class.
class Main:
    def __init__(self):
        pass

    # Utility array to convert byte arrays to hexadecimal strings.
    HEX_ARRAY = "0123456789ABCDEF".encode()

    # Cipher object for AES encryption/decryption is declared but not instantiated.
    backend = default_backend()

    @staticmethod
    def main():
        plain_text = input()
        sec_key = Main.get_secret_encryption_key()
        print("Generated AES Key (Hex Form): " + Main.bytes_to_hex(sec_key))
        cipher_text = Main.encrypt_text(plain_text, sec_key)
        print("Encrypted Text (Hex Form): " + Main.bytes_to_hex(cipher_text))
        decrypted_text = Main.decrypt_text(cipher_text, sec_key)
        print("Decrypted Text: " + decrypted_text)

    # Generates a 128-bit AES key.
    @staticmethod
    def get_secret_encryption_key():
        key = os.urandom(16)  # AES-128
        return key

    # Encrypts the input text using AES in GCM mode.
    @staticmethod
    def encrypt_text(plain_text, sec_key):
        iv = os.urandom(12)  # GCM mode requires a 96-bit IV
        cipher = Cipher(algorithms.AES(sec_key), modes.GCM(iv), backend=default_backend())
        encryptor = cipher.encryptor()
        padder = padding.PKCS7(128).padder()
        padded_data = padder.update(plain_text.encode()) + padder.finalize()
        encrypted_data = encryptor.update(padded_data) + encryptor.finalize()
        return iv + encrypted_data

    # Decrypts the cipher text using AES in GCM mode with the same parameters used during encryption.
    @staticmethod
    def decrypt_text(cipher_text, sec_key):
        iv = cipher_text[:12]
        encrypted_data = cipher_text[12:]
        cipher = Cipher(algorithms.AES(sec_key), modes.GCM(iv), backend=default_backend())
        decryptor = cipher.decryptor()
        unpadder = padding.PKCS7(128).unpadder()
        decrypted_data = decryptor.update(encrypted_data) + decryptor.finalize()
        return unpadder.update(decrypted_data).decode() + unpadder.finalize().decode()

    # Converts byte arrays to hexadecimal strings.
    @staticmethod
    def bytes_to_hex(bytes):
        hex_chars = bytearray(2 * len(bytes))
        for j in range(len(bytes)):
            byte = bytes[j]
            hex_chars[2 * j] = Main.HEX_ARRAY[byte >> 4]
            hex_chars[2 * j + 1] = Main.HEX_ARRAY[byte & 0x0F]
        return hex_chars.decode()


if __name__ == "__main__":
    Main.main()
