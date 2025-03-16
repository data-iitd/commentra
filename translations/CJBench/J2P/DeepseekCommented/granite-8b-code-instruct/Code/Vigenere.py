
import string

class Main:
    def __init__(self):
        self.alphabet = string.ascii_lowercase + string.ascii_uppercase

    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        result = ""
        key_index = 0
        for char in message:
            if char in self.alphabet:
                char_index = self.alphabet.index(char)
                key_char_index = self.alphabet.index(key[key_index].lower())
                if char.isupper():
                    result += self.alphabet[(char_index + key_char_index - 2 * ord('A')) % 26 + ord('A')]
                else:
                    result += self.alphabet[(char_index + key_char_index - 2 * ord('a')) % 26 + ord('a')]
                key_index = (key_index + 1) % len(key)
            else:
                result += char
        return result

    def decrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        result = ""
        key_index = 0
        for char in message:
            if char in self.alphabet:
                char_index = self.alphabet.index(char)
                key_char_index = self.alphabet.index(key[key_index].lower())
                if char.isupper():
                    result += self.alphabet[25 - (25 - (char_index - key_char_index)) % 26]
                else:
                    result += self.alphabet[25 - (25 - (char_index - key_char_index)) % 26]
                key_index = (key_index + 1) % len(key)
            else:
                result += char
        return result

# Main method to run the program
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

