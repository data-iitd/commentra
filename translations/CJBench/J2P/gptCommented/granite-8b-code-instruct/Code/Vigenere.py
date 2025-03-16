
import string

class Main:
    # Method to encrypt a given message using a specified key
    def encrypt(self, message, key):
        # Check if the key is empty and throw an exception if it is
        if not key:
            raise ValueError("Key cannot be empty.")
        
        # Initialize variables for encryption
        result = []
        j = 0  # Index for the key
        
        # Iterate through each character of the message
        for i in range(len(message)):
            c = message[i]
            # Check if the character is a letter
            if c in string.ascii_letters:
                # Encrypt uppercase letters
                if c.isupper():
                    result.append(chr((ord(c) + ord(key.upper()[j]) - 2 * ord('A')) % 26 + ord('A')))
                # Encrypt lowercase letters
                else:
                    result.append(chr((ord(c) + ord(key.lower()[j]) - 2 * ord('a')) % 26 + ord('a')))
                # Move to the next character in the key, wrapping around if necessary
                j = (j + 1) % len(key)
            else:
                # If not a letter, append the character as is
                result.append(c)
        
        # Return the encrypted message as a string
        return ''.join(result)
    
    # Method to decrypt a given message using a specified key
    def decrypt(self, message, key):
        # Check if the key is empty and throw an exception if it is
        if not key:
            raise ValueError("Key cannot be empty.")
        
        # Initialize variables for decryption
        result = []
        j = 0  # Index for the key
        
        # Iterate through each character of the message
        for i in range(len(message)):
            c = message[i]
            # Check if the character is a letter
            if c in string.ascii_letters:
                # Decrypt uppercase letters
                if c.isupper():
                    result.append(chr(ord('Z') - (25 - (ord(c) - ord(key.upper()[j]))) % 26))
                # Decrypt lowercase letters
                else:
                    result.append(chr(ord('z') - (25 - (ord(c) - ord(key.lower()[j]))) % 26))
                # Move to the next character in the key, wrapping around if necessary
                j = (j + 1) % len(key)
            else:
                # If not a letter, append the character as is
                result.append(c)
        
        # Return the decrypted message as a string
        return ''.join(result)

# Main method to execute the program
if __name__ == "__main__":
    # Read the operation type (encrypt or decrypt)
    operation = input().lower()
    
    # Read the key for encryption/decryption
    key = input()
    
    # Perform encryption if the operation is "encrypt"
    if operation == "encrypt":
        plaintext = input()  # Read the plaintext message
        cipher = Main()  # Create an instance of Main
        encrypted = cipher.encrypt(plaintext, key)  # Encrypt the message
        print("Encrypted Message:", encrypted)  # Output the encrypted message
    # Perform decryption if the operation is "decrypt"
    elif operation == "decrypt":
        ciphertext = input()  # Read the ciphertext message
        cipher = Main()  # Create an instance of Main
        decrypted = cipher.decrypt(ciphertext, key)  # Decrypt the message
        print("Decrypted Message:", decrypted)  # Output the decrypted message
    # Handle invalid operation input
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

