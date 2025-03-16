class Main:
    def encrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        
        result = []
        key_index = 0
        
        for char in message:
            if char.isalpha():
                shift = ord(key[key_index % len(key)].lower()) - ord('a')
                if char.isupper():
                    new_char = chr((ord(char) + shift - ord('A')) % 26 + ord('A'))
                else:
                    new_char = chr((ord(char) + shift - ord('a')) % 26 + ord('a'))
                result.append(new_char)
                key_index += 1
            else:
                result.append(char)
        
        return ''.join(result)

    def decrypt(self, message, key):
        if not key:
            raise ValueError("Key cannot be empty.")
        
        result = []
        key_index = 0
        
        for char in message:
            if char.isalpha():
                shift = ord(key[key_index % len(key)].lower()) - ord('a')
                if char.isupper():
                    new_char = chr(ord('A') + (ord('Z') - ord(char) + shift) % 26)
                else:
                    new_char = chr(ord('a') + (ord('z') - ord(char) + shift) % 26)
                result.append(new_char)
                key_index += 1
            else:
                result.append(char)
        
        return ''.join(result)

# Main function to execute the program
def main():
    import sys
    operation = sys.stdin.readline().strip().lower()
    key = sys.stdin.readline().strip()
    
    if operation == "encrypt":
        plaintext = sys.stdin.readline().strip()
        cipher = Main()
        encrypted = cipher.encrypt(plaintext, key)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = sys.stdin.readline().strip()
        cipher = Main()
        decrypted = cipher.decrypt(ciphertext, key)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
