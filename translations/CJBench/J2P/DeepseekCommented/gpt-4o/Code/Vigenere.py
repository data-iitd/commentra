class Cipher:
    def __init__(self, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        self.key = key

    def encrypt(self, message):
        result = []
        key_index = 0
        for char in message:
            if char.isalpha():
                shift = ord(self.key[key_index].upper()) if char.isupper() else ord(self.key[key_index].lower())
                new_char = chr((ord(char) + shift - 2 * ord('A')) % 26 + ord('A')) if char.isupper() else chr((ord(char) + shift - 2 * ord('a')) % 26 + ord('a'))
                result.append(new_char)
                key_index = (key_index + 1) % len(self.key)
            else:
                result.append(char)
        return ''.join(result)

    def decrypt(self, message):
        result = []
        key_index = 0
        for char in message:
            if char.isalpha():
                shift = ord(self.key[key_index].upper()) if char.isupper() else ord(self.key[key_index].lower())
                new_char = chr(ord('A') + (25 - (ord(char) - shift) % 26) if char.isupper() else ord('a') + (25 - (ord(char) - shift) % 26))
                result.append(new_char)
                key_index = (key_index + 1) % len(self.key)
            else:
                result.append(char)
        return ''.join(result)

def main():
    operation = input().lower()
    key = input()
    if operation == "encrypt":
        plaintext = input()
        cipher = Cipher(key)
        encrypted = cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        cipher = Cipher(key)
        decrypted = cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
