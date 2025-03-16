
import string
import sys

class Main:
    def __init__(self):
        self.alphabet = string.ascii_letters

    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")

        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c in self.alphabet:
                if c.isupper():
                    result += chr((ord(c) + ord(key[j].upper()) - 2 * ord('A')) % 26 + ord('A'))
                else:
                    result += chr((ord(c) + ord(key[j].lower()) - 2 * ord('a')) % 26 + ord('a'))
                j = (j + 1) % len(key)
            else:
                result += c
        return result

    def decrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")

        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c in self.alphabet:
                if c.isupper():
                    result += chr(ord('Z') - (25 - (ord(c) - ord(key[j].upper()))) % 26)
                else:
                    result += chr(ord('z') - (25 - (ord(c) - ord(key[j].lower()))) % 26)
                j = (j + 1) % len(key)
            else:
                result += c
        return result

if __name__ == "__main__":
    main = Main()
    operation = sys.stdin.readline().strip().lower()
    key = sys.stdin.readline().strip()

    if operation == "encrypt":
        message = sys.stdin.readline().strip()
        print("Encrypted Message: " + main.encrypt(message, key))
    elif operation == "decrypt":
        message = sys.stdin.readline().strip()
        print("Decrypted Message: " + main.decrypt(message, key))
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

