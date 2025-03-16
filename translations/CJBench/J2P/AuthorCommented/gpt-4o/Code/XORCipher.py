import binascii

class XORCipher:
    @staticmethod
    def bytes_to_hex(byte_array):
        return binascii.hexlify(byte_array).decode('utf-8')

    @staticmethod
    def hex_to_bytes(hex_string):
        return binascii.unhexlify(hex_string)

    @staticmethod
    def xor(input_bytes, key_bytes):
        return bytes(input_byte ^ key_bytes[i % len(key_bytes)] for i, input_byte in enumerate(input_bytes))

    @staticmethod
    def encrypt(plain_text, key):
        if not key:
            raise ValueError("Key must not be empty")

        plain_text_bytes = plain_text.encode('utf-8')
        key_bytes = key.encode('utf-8')
        xor_result = XORCipher.xor(plain_text_bytes, key_bytes)
        return XORCipher.bytes_to_hex(xor_result)

    @staticmethod
    def decrypt(cipher_text, key):
        if not key:
            raise ValueError("Key must not be empty")

        cipher_bytes = XORCipher.hex_to_bytes(cipher_text)
        key_bytes = key.encode('utf-8')
        xor_result = XORCipher.xor(cipher_bytes, key_bytes)
        return xor_result.decode('utf-8')

if __name__ == "__main__":
    operation = input().strip().lower()

    key = input("Enter the key: ")

    if operation == "encrypt":
        plain_text = input()
        try:
            cipher_text = XORCipher.encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        cipher_text = input()
        try:
            plain_text = XORCipher.decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

# <END-OF-CODE>
