
import sys
import binascii

# Declare the default character set for UTF-8 encoding
CS_DEFAULT = "utf-8"

# Converts a byte array to a hexadecimal string
def bytes_to_hex(bytes):
    hex_string = ""
    for b in bytes:
        # Convert a single byte to hexadecimal string
        hex = hex(b)[2:]
        # Add a leading zero if the hexadecimal string has only one character
        if len(hex) == 1:
            hex_string += "0"
        hex_string += hex
    return hex_string

# Converts a hexadecimal string to a byte array
def hex_to_bytes(hex):
    data = bytearray()
    for i in range(0, len(hex), 2):
        # Extract two hexadecimal digits and convert them to a byte
        data.append(int(hex[i:i+2], 16))
    return bytes(data)

# XOR operation between two byte arrays
def xor(input_bytes, key_bytes):
    output_bytes = bytearray()
    for i in range(len(input_bytes)):
        # Perform XOR operation between each byte of input_bytes and key_bytes
        output_bytes.append(input_bytes[i] ^ key_bytes[i % len(key_bytes)])
    return bytes(output_bytes)

# Encrypts a plain text using the provided key
def encrypt(plain_text, key):
    if key == "":
        raise ValueError("Key must not be empty")
    # Convert plain text to byte array
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    # Convert key to byte array
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation between plain_text_bytes and key_bytes
    xor_result = xor(plain_text_bytes, key_bytes)
    # Convert the XOR result to hexadecimal string
    return bytes_to_hex(xor_result)

# Decrypts a cipher text using the provided key
def decrypt(cipher_text, key):
    if key == "":
        raise ValueError("Key must not be empty")
    # Convert cipher text to byte array
    cipher_bytes = hex_to_bytes(cipher_text)
    # Convert key to byte array
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation between cipher_bytes and key_bytes
    xor_result = xor(cipher_bytes, key_bytes)
    # Convert the XOR result to a string using the default character set
    return xor_result.decode(CS_DEFAULT)

# Main method to read user input and perform encryption or decryption
def main():
    operation = input("Enter the operation (encrypt or decrypt): ").lower() # Read the operation ('encrypt' or 'decrypt')
    key = input("Enter the key: ") # Request the user to enter the key

    if operation == "encrypt": # If the operation is 'encrypt'
        plain_text = input("Enter the plain text: ") # Read the plain text from the user
        try:
            cipher_text = encrypt(plain_text, key) # Encrypt the plain text using the key
            print("Encrypted Message: " + cipher_text) # Print the encrypted message
        except ValueError as e:
            print(e) # Print an error message if the key is empty
    elif operation == "decrypt": # If the operation is 'decrypt'
        cipher_text = input("Enter the cipher text: ") # Read the cipher text from the user
        try:
            plain_text = decrypt(cipher_text, key) # Decrypt the cipher text using the key
            print("Decrypted Message: " + plain_text) # Print the decrypted message
        except ValueError as e:
            print(e) # Print an error message if the key is empty
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.") # Print an error message for invalid operation

if __name__ == "__main__":
    main()

