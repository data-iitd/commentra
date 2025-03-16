
import string

class CaesarCipher:
    def __init__(self, key):
        self.key = key

    def encrypt(self, message):
        if not self.key:
            raise ValueError("Key cannot be empty.")
        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c.isalpha():
                if c.isupper():
                    result += chr((ord(c) + ord(self.key.upper()[j]) - 2 * ord('A')) % 26 + ord('A'))
                else:
                    result += chr((ord(c) + ord(self.key.lower()[j]) - 2 * ord('a')) % 26 + ord('a'))
                j = (j + 1) % len(self.key)
            else:
                result += c
        return result

    def decrypt(self, message):
        if not self.key:
            raise ValueError("Key cannot be empty.")
        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c.isalpha():
                if c.isupper():
                    result += chr('Z' - (25 - (ord(c) - ord(self.key.upper()[j]))) % 26)
                else:
                    result += chr('z' - (25 - (ord(c) - ord(self.key.lower()[j]))) % 26)
                j = (j + 1) % len(self.key)
            else:
                result += c
        return result

if __name__ == "__main__":
    operation = input().lower()
    key = input()
    if operation == "encrypt":
        plaintext = input()
        cipher = CaesarCipher(key)
        encrypted = cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        cipher = CaesarCipher(key)
        decrypted = cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

