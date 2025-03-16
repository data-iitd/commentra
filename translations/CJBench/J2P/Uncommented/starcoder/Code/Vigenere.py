
import sys

class Main:
    def __init__(self):
        self.key = ""
        self.message = ""
        self.result = ""
        self.j = 0

    def encrypt(self):
        if self.key == "":
            raise Exception("Key cannot be empty.")
        for i in range(len(self.message)):
            c = self.message[i]
            if c.isalpha():
                if c.isupper():
                    self.result += chr((ord(c) + ord(self.key[self.j].upper()) - 2 * ord('A')) % 26 + ord('A'))
                else:
                    self.result += chr((ord(c) + ord(self.key[self.j].lower()) - 2 * ord('a')) % 26 + ord('a'))
                self.j = (self.j + 1) % len(self.key)
            else:
                self.result += c
        return self.result

    def decrypt(self):
        if self.key == "":
            raise Exception("Key cannot be empty.")
        for i in range(len(self.message)):
            c = self.message[i]
            if c.isalpha():
                if c.isupper():
                    self.result += chr(ord('Z') - (25 - (ord(c) - ord(self.key[self.j].upper()))) % 26)
                else:
                    self.result += chr(ord('z') - (25 - (ord(c) - ord(self.key[self.j].lower()))) % 26)
                self.j = (self.j + 1) % len(self.key)
            else:
                self.result += c
        return self.result

if __name__ == "__main__":
    main = Main()
    operation = sys.stdin.readline().strip().lower()
    main.key = sys.stdin.readline().strip()
    if operation == "encrypt":
        main.message = sys.stdin.readline().strip()
        print("Encrypted Message: " + main.encrypt())
    elif operation == "decrypt":
        main.message = sys.stdin.readline().strip()
        print("Decrypted Message: " + main.decrypt())
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

