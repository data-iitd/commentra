import string

class Main:
    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        result = ""
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c.isalpha():
                if c.isupper():
                    result += chr((ord(c) + ord(key.upper()[j]) - 2 * ord('A')) % 26 + ord('A'))
                    j = (j + 1) % len(key)
                else:
                    result += chr((ord(c) + ord(key.lower()[j]) - 2 * ord('a')) % 26 + ord('a'))
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
            if c.isalpha():
                if c.isupper():
                    result += chr(ord('Z') - (25 - (ord(c) - ord(key.upper()[j]))) % 26)
                    j = (j + 1) % len(key)
                else:
                    result += chr(ord('z') - (25 - (ord(c) - ord(key.lower()[j]))) % 26)
                    j = (j + 1) % len(key)
            else:
                result += c
        return result

def main():
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

if __name__ == "__main__":
    main()

