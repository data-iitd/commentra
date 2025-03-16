import sys

# Converts a byte array to a hexadecimal string
def bytes_to_hex(bytes_array):
    return ''.join(f'{b:02x}' for b in bytes_array)

# Converts a hexadecimal string to a byte array
def hex_to_bytes(hex_string):
    return bytes.fromhex(hex_string)

# XOR operation between two byte arrays
def xor(input_bytes, key_bytes):
    return bytes(input_bytes[i] ^ key_bytes[i % len(key_bytes)] for i in range(len(input_bytes)))

# Encrypts a plain text using the provided key
def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    # Convert plain text to byte array
    plain_text_bytes = plain_text.encode('utf-8')
    # Convert key to byte array
    key_bytes = key.encode('utf-8')
    # Perform XOR operation between plain_text_bytes and key_bytes
    xor_result = xor(plain_text_bytes, key_bytes)
    # Convert the XOR result to hexadecimal string
    return bytes_to_hex(xor_result)

# Decrypts a cipher text using the provided key
def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    # Convert cipher text to byte array
    cipher_bytes = hex_to_bytes(cipher_text)
    # Convert key to byte array
    key_bytes = key.encode('utf-8')
    # Perform XOR operation between cipher_bytes and key_bytes
    xor_result = xor(cipher_bytes, key_bytes)
    # Convert the XOR result to a string using UTF-8 encoding
    return xor_result.decode('utf-8')

# Main function to read user input and perform encryption or decryption
def main():
    operation = input().strip().lower()  # Read the operation ('encrypt' or 'decrypt')
    key = input("Enter the key: ")  # Request the user to enter the key

    if operation == "encrypt":  # If the operation is 'encrypt'
        plain_text = input()  # Read the plain text from the user
        try:
            cipher_text = encrypt(plain_text, key)  # Encrypt the plain text using the key
            print("Encrypted Message:", cipher_text)  # Print the encrypted message
        except ValueError as e:
            print(e)  # Print an error message if the key is empty
    elif operation == "decrypt":  # If the operation is 'decrypt'
        cipher_text = input()  # Read the cipher text from the user
        try:
            plain_text = decrypt(cipher_text, key)  # Decrypt the cipher text using the key
            print("Decrypted Message:", plain_text)  # Print the decrypted message
        except ValueError as e:
            print(e)  # Print an error message if the key is empty
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")  # Print an error message for invalid operation

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
