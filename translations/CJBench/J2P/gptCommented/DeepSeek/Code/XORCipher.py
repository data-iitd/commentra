import base64

class Main:
    # Default character set for encoding and decoding
    CS_DEFAULT = "utf-8"

    # Private constructor to prevent instantiation of the utility class
    def __init__(self):
        pass

    # Converts an array of bytes to a hexadecimal string representation
    @staticmethod
    def bytes_to_hex(bytes_data):
        hex_string = ""
        # Iterate through each byte in the array
        for b in bytes_data:
            # Convert byte to hex string and ensure two characters
            hex_value = format(b & 0xFF, '02x')
            hex_string += hex_value
        return hex_string

    # Converts a hexadecimal string representation back to an array of bytes
    @staticmethod
    def hex_to_bytes(hex_string):
        length = len(hex_string)
        byte_array = bytearray(length // 2)
        # Iterate through the hex string two characters at a time
        for i in range(0, length, 2):
            # Convert each pair of hex characters to a byte
            byte_value = int(hex_string[i:i+2], 16)
            byte_array[i // 2] = byte_value
        return bytes(byte_array)

    # Performs XOR operation between input bytes and key bytes
    @staticmethod
    def xor(input_bytes, key_bytes):
        output_bytes = bytearray(len(input_bytes))
        # Iterate through each byte in the input
        for i in range(len(input_bytes)):
            # XOR the input byte with the corresponding key byte (cyclically)
            output_bytes[i] = input_bytes[i] ^ key_bytes[i % len(key_bytes)]
        return bytes(output_bytes)

    # Encrypts the given plaintext using the specified key
    @staticmethod
    def encrypt(plain_text, key):
        # Check if the key is empty and raise an exception if it is
        if not key:
            raise ValueError("Key must not be empty")
        # Convert plaintext and key to byte arrays
        plain_text_bytes = plain_text.encode(Main.CS_DEFAULT)
        key_bytes = key.encode(Main.CS_DEFAULT)
        # Perform XOR operation on plaintext and key
        xor_result = Main.xor(plain_text_bytes, key_bytes)
        # Convert the XOR result to a hex string and return it
        return Main.bytes_to_hex(xor_result)

    # Decrypts the given ciphertext using the specified key
    @staticmethod
    def decrypt(cipher_text, key):
        # Check if the key is empty and raise an exception if it is
        if not key:
            raise ValueError("Key must not be empty")
        # Convert the ciphertext from hex string to byte array
        cipher_bytes = Main.hex_to_bytes(cipher_text)
        key_bytes = key.encode(Main.CS_DEFAULT)
        # Perform XOR operation on ciphertext and key
        xor_result = Main.xor(cipher_bytes, key_bytes)
        # Convert the result back to a string and return it
        return xor_result.decode(Main.CS_DEFAULT)

    # Main method to execute the program
    @staticmethod
    def main():
        import sys
        import readline

        # Read the operation type (encrypt or decrypt) from user input
        operation = input("Enter operation (encrypt/decrypt): ").lower()
        key = input("Enter the key: ")

        # Check if the operation is encryption
        if operation == "encrypt":
            plain_text = input("Enter plaintext: ")
            try:
                # Encrypt the plaintext and display the ciphertext
                cipher_text = Main.encrypt(plain_text, key)
                print("Encrypted Message:", cipher_text)
            except ValueError as e:
                # Handle empty key exception
                print(e)
        # Check if the operation is decryption
        elif operation == "decrypt":
            cipher_text = input("Enter ciphertext: ")
            try:
                # Decrypt the ciphertext and display the plaintext
                plain_text = Main.decrypt(cipher_text, key)
                print("Decrypted Message:", plain_text)
            except ValueError as e:
                # Handle empty key exception
                print(e)
        # Handle invalid operation input
        else:
            print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    Main.main()
