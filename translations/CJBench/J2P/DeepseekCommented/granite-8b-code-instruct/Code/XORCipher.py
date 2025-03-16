
import binascii

# Define the default charset to be used for encoding and decoding
CS_DEFAULT = 'utf-8'

# Convert byte array to a hexadecimal string
def bytes_to_hex(bytes):
    return binascii.hexlify(bytes).decode(CS_DEFAULT)

# Convert a hexadecimal string to a byte array
def hex_to_bytes(hex):
    return binascii.unhexlify(hex)

# Perform a XOR operation between two byte arrays
def xor(input_bytes, key_bytes):
    output_bytes = bytearray()
    for i in range(len(input_bytes)):
        output_bytes.append(input_bytes[i] ^ key_bytes[i % len(key_bytes)])
    return output_bytes

# Encrypt the given plain text using the provided key
def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    # Convert plain text to byte array using the default charset
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    # Convert key to byte array using the default charset
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation to encrypt the data
    xor_result = xor(plain_text_bytes, key_bytes)
    # Convert the encrypted byte array to a hexadecimal string
    return bytes_to_hex(xor_result)

# Decrypt the given cipher text using the provided key
def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    # Convert cipher text from hexadecimal string to byte array
    cipher_bytes = hex_to_bytes(cipher_text)
    # Convert key to byte array using the default charset
    key_bytes = key.encode(CS_DEFAULT)
    # Perform XOR operation to decrypt the data
    xor_result = xor(cipher_bytes, key_bytes)
    # Convert the decrypted byte array to a string using the default charset
    return xor_result.decode(CS_DEFAULT)

# Main method to handle user input for encryption or decryption
def main():
    operation = input("Enter 'encrypt' or 'decrypt': ").lower()
    key = input("Enter the key: ")
    if operation == 'encrypt':
        plain_text = input("Enter the plain text: ")
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == 'decrypt':
        cipher_text = input("Enter the cipher text: ")
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
