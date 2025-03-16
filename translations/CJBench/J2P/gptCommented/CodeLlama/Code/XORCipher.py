import sys

# Default character set for encoding and decoding
CS_DEFAULT = "utf-8"

# Private constructor to prevent instantiation of the utility class
class Main:
    def __init__(self):
        pass

    # Converts an array of bytes to a hexadecimal string representation
    @staticmethod
    def bytes_to_hex(bytes):
        hex_string = ""
        # Iterate through each byte in the array
        for b in bytes:
            # Convert byte to hex string and ensure two characters
            hex = hex(b)[2:]
            if len(hex) == 1:
                hex_string += "0"
            hex_string += hex
        return hex_string

    # Converts a hexadecimal string representation back to an array of bytes
    @staticmethod
    def hex_to_bytes(hex):
        data = bytearray()
        # Iterate through the hex string two characters at a time
        for i in range(0, len(hex), 2):
            # Convert each pair of hex characters to a byte
            data.append(int(hex[i:i+2], 16))
        return data

    # Performs XOR operation between input bytes and key bytes
    @staticmethod
    def xor(input_bytes, key_bytes):
        output_bytes = bytearray()
        # Iterate through each byte in the input
        for i in range(len(input_bytes)):
            # XOR the input byte with the corresponding key byte (cyclically)
            output_bytes.append(input_bytes[i] ^ key_bytes[i % len(key_bytes)])
        return output_bytes

    # Encrypts the given plaintext using the specified key
    @staticmethod
    def encrypt(plain_text, key):
        # Check if the key is empty and throw an exception if it is
        if key == "":
            raise ValueError("Key must not be empty")
        # Convert plaintext and key to byte arrays
        plain_text_bytes = plain_text.encode(CS_DEFAULT)
        key_bytes = key.encode(CS_DEFAULT)
        # Perform XOR operation on plaintext and key
        xor_result = Main.xor(plain_text_bytes, key_bytes)
        # Convert the XOR result to a hex string and return it
        return Main.bytes_to_hex(xor_result)

    # Decrypts the given ciphertext using the specified key
    @staticmethod
    def decrypt(cipher_text, key):
        # Check if the key is empty and throw an exception if it is
        if key == "":
            raise ValueError("Key must not be empty")
        # Convert the ciphertext from hex string to byte array
        cipher_bytes = Main.hex_to_bytes(cipher_text)
        key_bytes = key.encode(CS_DEFAULT)
        # Perform XOR operation on ciphertext and key
        xor_result = Main.xor(cipher_bytes, key_bytes)
        # Convert the result back to a string and return it
        return xor_result.decode(CS_DEFAULT)

    # Main method to execute the program
    @staticmethod
    def main():
        # Read the operation type (encrypt or decrypt) from user input
        operation = input().lower()
        key = input("Enter the key: ")

        # Check if the operation is encryption
        if operation == "encrypt":
            plain_text = input()
            try:
                # Encrypt the plaintext and display the ciphertext
                cipher_text = Main.encrypt(plain_text, key)
                print("Encrypted Message: " + cipher_text)
            except ValueError as e:
                # Handle empty key exception
                print(e)

        # Check if the operation is decryption
        elif operation == "decrypt":
            cipher_text = input()
            try:
                # Decrypt the ciphertext and display the plaintext
                plain_text = Main.decrypt(cipher_text, key)
                print("Decrypted Message: " + plain_text)
            except ValueError as e:
                # Handle empty key exception
                print(e)

        # Handle invalid operation input
        else:
            print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    Main.main()

