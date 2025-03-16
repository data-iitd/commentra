import base64
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

# Helper function to convert bytes to hexadecimal string
def bytes_to_hex(bytes):
    return bytes.hex()

# Function to generate a secret key for AES encryption
def get_secret_encryption_key():
    return get_random_bytes(16)  # AES-128 uses 16-byte keys

# Function to encrypt text using AES
def encrypt_text(plain_text, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM)
    cipher_text, tag = cipher.encrypt_and_digest(pad(plain_text.encode('utf-8'), AES.block_size))
    return cipher_text, cipher.nonce, tag

# Function to decrypt text using AES
def decrypt_text(cipher_text, nonce, tag, sec_key):
    cipher = AES.new(sec_key, AES.MODE_GCM, nonce=nonce)
    decrypted_text = unpad(cipher.decrypt(cipher_text), AES.block_size)
    try:
        return decrypted_text.decode('utf-8')
    except UnicodeDecodeError:
        return "Error: Unable to decode the decrypted text."

# Main function to demonstrate AES encryption and decryption
def main():
    plain_text = input()
    sec_key = get_secret_encryption_key()
    print("Generated AES Key (Hex Form): " + bytes_to_hex(sec_key))

    # Encrypt text
    cipher_text, nonce, tag = encrypt_text(plain_text, sec_key)
    print("Encrypted Text (Hex Form): " + bytes_to_hex(cipher_text))

    # Decrypt text
    decrypted_text = decrypt_text(cipher_text, nonce, tag, sec_key)
    print("Decrypted Text: " + decrypted_text)

if __name__ == "__main__":
    main()
