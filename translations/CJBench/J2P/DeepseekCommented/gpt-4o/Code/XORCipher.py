import base64

class Main:
    # Define the default charset to be used for encoding and decoding
    CS_DEFAULT = "utf-8"
    
    # Private constructor to prevent instantiation
    def __init__(self):
        pass
    
    # Convert byte array to a hexadecimal string
    @staticmethod
    def bytes_to_hex(bytes_data):
        return ''.join(f'{byte:02x}' for byte in bytes_data)
    
    # Convert a hexadecimal string to a byte array
    @staticmethod
    def hex_to_bytes(hex_str):
        return bytearray.fromhex(hex_str)
    
    # Perform a XOR operation between two byte arrays
    @staticmethod
    def xor(input_bytes, key_bytes):
        output_bytes = bytearray(len(input_bytes))
        for i in range(len(input_bytes)):
            output_bytes[i] = input_bytes[i] ^ key_bytes[i % len(key_bytes)]
        return output_bytes
    
    # Encrypt the given plain text using the provided key
    @staticmethod
    def encrypt(plain_text, key):
        if not key:
            raise ValueError("Key must not be empty")
        # Convert plain text to byte array using the default charset
        plain_text_bytes = plain_text.encode(Main.CS_DEFAULT)
        # Convert key to byte array using the default charset
        key_bytes = key.encode(Main.CS_DEFAULT)
        # Perform XOR operation to encrypt the data
        xor_result = Main.xor(plain_text_bytes, key_bytes)
        # Convert the encrypted byte array to a hexadecimal string
        return Main.bytes_to_hex(xor_result)
    
    # Decrypt the given cipher text using the provided key
    @staticmethod
    def decrypt(cipher_text, key):
        if not key:
            raise ValueError("Key must not be empty")
        # Convert cipher text from hexadecimal string to byte array
        cipher_bytes = Main.hex_to_bytes(cipher_text)
        # Convert key to byte array using the default charset
        key_bytes = key.encode(Main.CS_DEFAULT)
        # Perform XOR operation to decrypt the data
        xor_result = Main.xor(cipher_bytes, key_bytes)
        # Convert the decrypted byte array to a string using the default charset
        return xor_result.decode(Main.CS_DEFAULT)
    
    # Main method to handle user input for encryption or decryption
    @staticmethod
    def main():
        import sys
        import readline
        while True:
            operation = input("Enter operation (encrypt/decrypt): ").lower()
            key = input("Enter the key: ")
            if operation == "encrypt":
                plain_text = input("Enter the plain text: ")
                try:
                    cipher_text = Main.encrypt(plain_text, key)
                    print("Encrypted Message:", cipher_text)
                except ValueError as e:
                    print(e)
            elif operation == "decrypt":
                cipher_text = input("Enter the cipher text: ")
                try:
                    plain_text = Main.decrypt(cipher_text, key)
                    print("Decrypted Message:", plain_text)
                except ValueError as e:
                    print(e)
            else:
                print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    Main.main()
