import string

class Main:
    # Encrypt method to encrypt the given message using the key
    def encrypt(self, message, key):
        if not key: # Check if the key is empty
            raise ValueError("Key cannot be empty.") # Throw an exception if key is empty
        result = "" # Initialize result to build the encrypted message
        j = 0 # Initialize key index
        for i in range(len(message)): # Loop through each character in the message
            c = message[i] # Get the current character
            if c.isalpha(): # Check if the character is a letter
                if c.isupper(): # Check if the character is uppercase
                    result += chr((ord(c) + ord(key.upper()[j]) - 2 * ord('A')) % 26 + ord('A')) # Encrypt uppercase character
                else:
                    result += chr((ord(c) + ord(key.lower()[j]) - 2 * ord('a')) % 26 + ord('a')) # Encrypt lowercase character
                j = (j + 1) % len(key) # Update key index
            else:
                result += c # Append non-letter characters as they are
        return result # Return the encrypted message

    # Decrypt method to decrypt the given message using the key
    def decrypt(self, message, key):
        if not key: # Check if the key is empty
            raise ValueError("Key cannot be empty.") # Throw an exception if key is empty
        result = "" # Initialize result to build the decrypted message
        j = 0 # Initialize key index
        for i in range(len(message)): # Loop through each character in the message
            c = message[i] # Get the current character
            if c.isalpha(): # Check if the character is a letter
                if c.isupper(): # Check if the character is uppercase
                    result += chr('Z' - (25 - (ord(c) - ord(key.upper()[j]))) % 26) # Decrypt uppercase character
                else:
                    result += chr('z' - (25 - (ord(c) - ord(key.lower()[j]))) % 26) # Decrypt lowercase character
                j = (j + 1) % len(key) # Update key index
            else:
                result += c # Append non-letter characters as they are
        return result # Return the decrypted message

# Main method to run the program
def main():
    operation = input().lower() # Read operation from user
    key = input() # Read key from user
    if operation == "encrypt": # Check if the operation is encrypt
        plaintext = input() # Read plaintext message from user
        cipher = Main() # Create an instance of Main
        encrypted = cipher.encrypt(plaintext, key) # Encrypt the plaintext message
        print("Encrypted Message:", encrypted) # Print the encrypted message
    elif operation == "decrypt": # Check if the operation is decrypt
        ciphertext = input() # Read ciphertext message from user
        cipher = Main() # Create an instance of Main
        decrypted = cipher.decrypt(ciphertext, key) # Decrypt the ciphertext message
        print("Decrypted Message:", decrypted) # Print the decrypted message
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.") # Print error message for invalid operation

if __name__ == "__main__":
    main()

