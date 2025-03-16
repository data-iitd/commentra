class Main:
    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        result = []
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c.isalpha():
                if c.isupper():
                    result.append(chr((ord(c) + ord(key[j].upper()) - 2 * ord('A')) % 26 + ord('A')))
                else:
                    result.append(chr((ord(c) + ord(key[j].lower()) - 2 * ord('a')) % 26 + ord('a')))
                j = (j + 1) % len(key)
            else:
                result.append(c)
        return ''.join(result)

    def decrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        result = []
        j = 0
        for i in range(len(message)):
            c = message[i]
            if c.isalpha():
                if c.isupper():
                    result.append(chr(ord('Z') - (25 - (ord(c) - ord(key[j].upper()))) % 26))
                else:
                    result.append(chr(ord('z') - (25 - (ord(c) - ord(key[j].lower()))) % 26))
                j = (j + 1) % len(key)
            else:
                result.append(c)
        return ''.join(result)

if __name__ == "__main__":
    operation = input().strip().lower()
    key = input().strip()
    cipher = Main()
    if operation == "encrypt":
        plaintext = input().strip()
        encrypted = cipher.encrypt(plaintext, key)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input().strip()
        decrypted = cipher.decrypt(ciphertext, key)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
        
# <END-OF-CODE>
