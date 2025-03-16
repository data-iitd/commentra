import os
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

class Main:
    @staticmethod
    def get_secret_encryption_key():
        # Generate a random 128-bit (16 bytes) AES key
        return get_random_bytes(16)

    @staticmethod
    def encrypt_text(plain_text, sec_key):
        # Generate a random 96-bit (12 bytes) IV for GCM
        iv = get_random_bytes(12)
        cipher = AES.new(sec_key, AES.MODE_GCM, nonce=iv)
        
        # Encrypt the plaintext
        cipher_text, tag = cipher.encrypt_and_digest(plain_text.encode())
        
        # Return the IV and ciphertext concatenated
        return iv + cipher_text

    @staticmethod
    def decrypt_text(byte_cipher_text, sec_key):
        # Extract the IV from the beginning of the ciphertext
        iv = byte_cipher_text[:12]
        cipher_text = byte_cipher_text[12:]
        
        cipher = AES.new(sec_key, AES.MODE_GCM, nonce=iv)
        
        # Decrypt the ciphertext
        plain_text = cipher.decrypt(cipher_text)
        
        return plain_text.decode()

    @staticmethod
    def bytes_to_hex(byte_array):
        # Convert byte array to hexadecimal string
        return binascii.hexlify(byte_array).decode().upper()

if __name__ == "__main__":
    # Read plaintext input from the user
    plain_text = input("Enter plaintext: ")
    
    # Generate a secret AES encryption key
    sec_key = Main.get_secret_encryption_key()
    
    # Display the generated AES key in hexadecimal format
    print("Generated AES Key (Hex Form):", Main.bytes_to_hex(sec_key))
    
    # Encrypt the plaintext using the generated secret key
    cipher_text = Main.encrypt_text(plain_text, sec_key)
    
    # Display the encrypted text in hexadecimal format
    print("Encrypted Text (Hex Form):", Main.bytes_to_hex(cipher_text))
    
    # Decrypt the ciphertext back to plaintext
    decrypted_text = Main.decrypt_text(cipher_text, sec_key)
    
    # Display the decrypted text
    print("Decrypted Text:", decrypted_text)

# <END-OF-CODE>
