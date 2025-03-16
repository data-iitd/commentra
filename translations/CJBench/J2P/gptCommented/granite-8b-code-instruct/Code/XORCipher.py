
import binascii

# Default character set for encoding and decoding
CS_DEFAULT = 'utf-8'

# Converts an array of bytes to a hexadecimal string representation
def bytes_to_hex(bytes):
    return binascii.hexlify(bytes).decode(CS_DEFAULT)

# Converts a hexadecimal string representation back to an array of bytes
def hex_to_bytes(hex):
    return binascii.unhexlify(hex)

# Performs XOR operation between input bytes and key bytes
def xor(input_bytes, key_bytes):
    output_bytes = bytearray(len(input_bytes))
    for i in range(len(input_bytes)):
        output_bytes[i] = input_bytes[i] ^ key_bytes[i % len(key_bytes)]
    return output_bytes

# Encrypts the given plaintext using the specified key
def encrypt(plain_text, key):
    # Check if the key is empty and throw an exception if it is
    if not key:
        raise ValueError("Key must not be empty")
    # Convert plaintext and key to byte arrays
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation on plaintext and key
    xor_result = xor(plain_text_bytes, key_bytes)
    # Convert the XOR result to a hex string and return it
    return bytes_to_hex(xor_result)

# Decrypts the given ciphertext using the specified key
def decrypt(cipher_text, key):
    # Check if the key is empty and throw an exception if it is
    if not key:
        raise ValueError("Key must not be empty")
    # Convert the ciphertext from hex string to byte array
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation on ciphertext and key
    xor_result = xor(cipher_bytes, key_bytes)
    # Convert the result back to a string and return it
    return xor_result.decode(CS_DEFAULT)

# Main method to execute the program
if __name__ == "__main__":
    operation = input("Enter the operation (encrypt/decrypt): ").lower()
    key = input("Enter the key: ")
    
    # Check if the operation is encryption
    if operation == "encrypt":
        plain_text = input("Enter the plaintext: ")
        try:
            # Encrypt the plaintext and display the ciphertext
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            # Handle empty key exception
            print(e)
    # Check if the operation is decryption
    elif operation == "decrypt":
        cipher_text = input("Enter the ciphertext: ")
        try:
            # Decrypt the ciphertext and display the plaintext
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            # Handle empty key exception
            print(e)
    # Handle invalid operation input
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

