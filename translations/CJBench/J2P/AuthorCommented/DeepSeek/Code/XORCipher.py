import base64
import sys

class XORCipher:
    def __init__(self, key):
        self.key = key.encode('utf-8')

    def _xor_bytes(self, input_bytes, key_bytes):
        return bytes(a ^ b for a, b in zip(input_bytes, key_bytes * (len(input_bytes) // len(key_bytes) + 1)))

    def encrypt(self, plain_text):
        plain_bytes = plain_text.encode('utf-8')
        encrypted_bytes = self._xor_bytes(plain_bytes, self.key)
        return encrypted_bytes.hex()

    def decrypt(self, cipher_text):
        cipher_bytes = bytes.fromhex(cipher_text)
        decrypted_bytes = self._xor_bytes(cipher_bytes, self.key)
        return decrypted_bytes.decode('utf-8')

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <encrypt|decrypt> <key>")
        sys.exit(1)

    operation = sys.argv[1].lower()
    key = sys.argv[2]

    cipher = XORCipher(key)

    if operation == 'encrypt':
        plain_text = input("Enter the plaintext: ")
        try:
            cipher_text = cipher.encrypt(plain_text)
            print("Encrypted Message:", cipher_text)
        except Exception as e:
            print(e)
    elif operation == 'decrypt':
        cipher_text = input("Enter the ciphertext: ")
        try:
            plain_text = cipher.decrypt(cipher_text)
            print("Decrypted Message:", plain_text)
        except Exception as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
