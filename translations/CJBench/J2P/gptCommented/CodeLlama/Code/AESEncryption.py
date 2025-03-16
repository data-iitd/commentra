import base64
import binascii
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# Hexadecimal character array for converting byte arrays to hex strings
HEX_ARRAY = "0123456789ABCDEF"

# Cipher instance for AES encryption
aes_cipher = None

def get_secret_encryption_key():
    # Generate a secret AES encryption key
    sec_key = AES.generate_key(128)
    
    # Display the generated AES key in hexadecimal format
    print("Generated AES Key (Hex Form): " + bytes_to_hex(sec_key.encode()))
    
    # Return the secret key
    return sec_key

def encrypt_text(plain_text, sec_key):
    # Initialize the AES cipher in encryption mode
    global aes_cipher
    aes_cipher = AES.new(sec_key, AES.MODE_GCM)
    
    # Encrypt the plaintext and return the ciphertext
    return aes_cipher.encrypt(plain_text.encode())

def decrypt_text(byte_cipher_text, sec_key):
    # Create a new cipher instance for decryption
    decryption_cipher = AES.new(sec_key, AES.MODE_GCM, nonce=aes_cipher.nonce)
    
    # Decrypt the ciphertext and return the plaintext
    return decryption_cipher.decrypt(byte_cipher_text).decode()

def bytes_to_hex(byte_array):
    # Create a character array to hold the hex representation
    hex_chars = [None] * (len(byte_array) * 2)
    
    # Convert each byte to its corresponding hex representation
    for j in range(len(byte_array)):
        v = byte_array[j]
        hex_chars[j * 2] = HEX_ARRAY[(v >> 4) & 0x0F]
        hex_chars[j * 2 + 1] = HEX_ARRAY[v & 0x0F]
    
    # Return the hex string
    return "".join(hex_chars)

def main():
    # Read plaintext input from the user
    plain_text = input("Enter plaintext: ")
    
    # Generate a secret AES encryption key
    sec_key = get_secret_encryption_key()
    
    # Encrypt the plaintext using the generated secret key
    byte_cipher_text = encrypt_text(plain_text, sec_key)
    
    # Display the encrypted text in hexadecimal format
    print("Encrypted Text (Hex Form): " + bytes_to_hex(byte_cipher_text))
    
    # Decrypt the ciphertext back to plaintext
    decrypted_text = decrypt_text(byte_cipher_text, sec_key)
    
    # Display the decrypted text
    print("Decrypted Text: " + decrypted_text)

if __name__ == "__main__":
    main()

