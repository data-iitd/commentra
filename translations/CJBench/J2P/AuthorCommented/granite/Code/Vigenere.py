

import string

class VigenereCipher:
    def __init__(self, key):
        self.key = key
        self.key_index = 0

    def encrypt(self, message):
        result = []
        for char in message:
            if char in string.ascii_letters:
                shift = (ord(char) - ord(self.key[self.key_index % len(self.key)].upper())) % 26
                if char.isupper():
                    result.append(chr((ord('A') + shift) % 26 + ord('A')))
                else:
                    result.append(chr((ord('a') + shift) % 26 + ord('a')))
                self.key_index += 1
            else:
                result.append(char)
        return ''.join(result)

    def decrypt(self, message):
        result = []
        for char in message:
            if char in string.ascii_letters:
                shift = (ord(self.key[self.key_index % len(self.key)].upper()) - ord(char)) % 26
                if char.isupper():
                    result.append(chr((ord('Z') - shift) % 26 + ord('A')))
                else:
                    result.append(chr((ord('z') - shift) % 26 + ord('a')))
                self.key_index += 1
            else:
                result.append(char)
        return ''.join(result)

if __name__ == "__main__":
    operation = input().lower()
    key = input()

    if operation == "encrypt":
        plaintext = input()
        cipher = VigenereCipher(key)
        encrypted = cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        cipher = VigenereCipher(key)
        decrypted = cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

