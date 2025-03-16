import base64
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

class AESCipher:
    def __init__(self, key):
        self.key = key

    def encrypt(self, plain_text):
        iv = get_random_bytes(16)
        cipher = AES.new(self.key, AES.MODE_GCM, nonce=iv)
        cipher_text = cipher.encrypt(pad(plain_text.encode('utf-8'), 16))
        return base64.b64encode(iv + cipher_text).decode('utf-8')

    def decrypt(self, encrypted_text):
        encrypted_text = base64.b64decode(encrypted_text)
        iv = encrypted_text[:16]
        cipher_text = encrypted_text[16:]
        cipher = AES.new(self.key, AES.MODE_GCM, nonce=iv)
        plain_text = unpad(cipher.decrypt(cipher_text), 16)
        return plain_text.decode('utf-8')

def main():
    key = get_random_bytes(16)
    cipher = AESCipher(key)

    plain_text = input()
    encrypted_text = cipher.encrypt(plain_text)
    print("Encrypted Text:", encrypted_text)

    decrypted_text = cipher.decrypt(encrypted_text)
    print("Decrypted Text:", decrypted_text)

if __name__ == "__main__":
    main()
