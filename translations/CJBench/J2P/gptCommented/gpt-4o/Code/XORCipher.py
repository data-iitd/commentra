import sys

# Default character set for encoding and decoding
CS_DEFAULT = 'utf-8'

# Converts an array of bytes to a hexadecimal string representation
def bytes_to_hex(bytes_array):
    return ''.join(f'{b:02x}' for b in bytes_array)

# Converts a hexadecimal string representation back to an array of bytes
def hex_to_bytes(hex_string):
    return bytes.fromhex(hex_string)

# Performs XOR operation between input bytes and key bytes
def xor(input_bytes, key_bytes):
    return bytes(input_bytes[i] ^ key_bytes[i % len(key_bytes)] for i in range(len(input_bytes)))

# Encrypts the given plaintext using the specified key
def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(plain_text_bytes, key_bytes)
    return bytes_to_hex(xor_result)

# Decrypts the given ciphertext using the specified key
def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode(CS_DEFAULT)

# Main function to execute the program
def main():
    operation = input().strip().lower()
    key = input("Enter the key: ").strip()
    
    if operation == "encrypt":
        plain_text = input()  # Read plaintext from user
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        cipher_text = input()  # Read ciphertext from user
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
