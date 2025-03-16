
import string

class Main:
    def __init__(self):
        self.alphabet = string.ascii_lowercase + string.ascii_uppercase

    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")

        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c in self.alphabet:
                if c.isupper():
                    result += self.alphabet[(self.alphabet.index(c) + self.alphabet.index(key[j].upper())) % 26]
                    j = (j + 1) % len(key)
                else:
                    result += self.alphabet[(self.alphabet.index(c) + self.alphabet.index(key[j].lower())) % 26]
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
                    result += self.alphabet[25 - (25 - self.alphabet.index(c) + self.alphabet.index(key[j].upper())) % 26]
                    j = (j + 1) % len(key)
                else:
                    result += self.alphabet[25 - (25 - self.alphabet.index(c) + self.alphabet.index(key[j].lower())) % 26]
                    j = (j + 1) % len(key)
            else:
                result += c

        return result

if __name__ == "__main__":
    operation = input().lower()
    key = input()

    if operation == "encrypt":
        plaintext = input()
        cipher = Main()
        encrypted = cipher.encrypt(plaintext, key)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        cipher = Main()
        decrypted = cipher.decrypt(ciphertext, key)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

