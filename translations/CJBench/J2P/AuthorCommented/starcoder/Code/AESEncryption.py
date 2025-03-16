
import base64
import os
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

class Main:
    def __init__(self):
        self.key = None
        self.iv = None
        self.cipher = None

    def get_secret_encryption_key(self):
        self.key = get_random_bytes(16)
        return self.key

    def encrypt_text(self, plain_text, secret_key):
        self.iv = get_random_bytes(12)
        self.cipher = AES.new(secret_key, AES.MODE_GCM, nonce=self.iv)
        cipher_text = self.cipher.encrypt(plain_text)
        return cipher_text

    def decrypt_text(self, cipher_text, secret_key):
        self.cipher = AES.new(secret_key, AES.MODE_GCM, nonce=self.iv)
        plain_text = self.cipher.decrypt(cipher_text)
        return plain_text

    def main(self):
        plain_text = input("Enter plain text: ")
        secret_key = self.get_secret_encryption_key()
        cipher_text = self.encrypt_text(plain_text, secret_key)
        print("Encrypted text: " + base64.b64encode(cipher_text).decode("utf-8"))
        print("Encrypted key: " + base64.b64encode(secret_key).decode("utf-8"))
        print("Decrypted text: " + self.decrypt_text(cipher_text, secret_key).decode("utf-8"))

if __name__ == "__main__":
    Main().main()

