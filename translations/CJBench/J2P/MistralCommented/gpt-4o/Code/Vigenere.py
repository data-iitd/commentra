class Main:  # Defining the Main class
    def encrypt(self, message: str, key: str) -> str:  # Defining the encrypt method
        if not key:  # Checking if the key is empty
            raise ValueError("Key cannot be empty.")  # Raising an exception if the key is empty
        result = []  # Creating an empty list to store the encrypted message
        j = 0  # Initializing a variable j to keep track of the key index
        for i in range(len(message)):  # Iterating through each character in the message
            c = message[i]  # Storing the current character in the message
            if c.isalpha():  # Checking if the current character is a letter
                if c.isupper():  # Checking if the current character is an uppercase letter
                    result.append(chr((ord(c) + ord(key[j].upper()) - 2 * ord('A')) % 26 + ord('A')))  # Encrypting uppercase letters
                    j = (j + 1) % len(key)  # Incrementing j and making it wrap around the key length
                else:  # If the current character is a lowercase letter
                    result.append(chr((ord(c) + ord(key[j].lower()) - 2 * ord('a')) % 26 + ord('a')))  # Encrypting lowercase letters
                    j = (j + 1) % len(key)  # Incrementing j and making it wrap around the key length
            else:  # If the current character is not a letter
                result.append(c)  # Adding the character to the result as it is
        return ''.join(result)  # Returning the encrypted message as a string

    def decrypt(self, message: str, key: str) -> str:  # Defining the decrypt method
        if not key:  # Checking if the key is empty
            raise ValueError("Key cannot be empty.")  # Raising an exception if the key is empty
        result = []  # Creating an empty list to store the decrypted message
        j = 0  # Initializing a variable j to keep track of the key index
        for i in range(len(message)):  # Iterating through each character in the message
            c = message[i]  # Storing the current character in the message
            if c.isalpha():  # Checking if the current character is a letter
                if c.isupper():  # Checking if the current character is an uppercase letter
                    result.append(chr(ord('Z') - (25 - (ord(c) - ord(key[j].upper())) % 26)))  # Decrypting uppercase letters
                    j = (j + 1) % len(key)  # Incrementing j and making it wrap around the key length
                else:  # If the current character is a lowercase letter
                    result.append(chr(ord('z') - (25 - (ord(c) - ord(key[j].lower())) % 26)))  # Decrypting lowercase letters
                    j = (j + 1) % len(key)  # Incrementing j and making it wrap around the key length
            else:  # If the current character is not a letter
                result.append(c)  # Adding the character to the result as it is
        return ''.join(result)  # Returning the decrypted message as a string

if __name__ == "__main__":  # Defining the main method
    operation = input().strip().lower()  # Reading the user's operation ('encrypt' or 'decrypt') and converting it to lowercase
    key = input().strip()  # Reading the user's key
    cipher = Main()  # Creating a new instance of the Main class
    if operation == "encrypt":  # Checking if the user wants to encrypt a message
        plaintext = input()  # Reading the user's plaintext message
        encrypted = cipher.encrypt(plaintext, key)  # Encrypting the plaintext message using the given key
        print("Encrypted Message:", encrypted)  # Printing the encrypted message to the console
    elif operation == "decrypt":  # Checking if the user wants to decrypt a message
        ciphertext = input()  # Reading the user's ciphertext message
        decrypted = cipher.decrypt(ciphertext, key)  # Decrypting the ciphertext message using the given key
        print("Decrypted Message:", decrypted)  # Printing the decrypted message to the console
    else:  # If the user entered an invalid operation
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")  # Printing an error message to the console
