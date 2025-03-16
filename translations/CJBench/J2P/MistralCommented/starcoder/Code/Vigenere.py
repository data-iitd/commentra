import java.util.Scanner; // Importing the Scanner class for user input

class Main: // Defining the Main class
    def encrypt(self, message, key): # Defining the encrypt method that takes a message and a key as arguments
        if key.isEmpty(): # Checking if the key is empty
            raise Exception("Key cannot be empty."); # Throwing an exception if the key is empty
        result = ""; # Creating an empty string to store the encrypted message
        j = 0; # Initializing a variable j to keep track of the key index
        for i in range(len(message)): # Iterating through each character in the message
            c = message[i]; # Storing the current character in the message
            if c.isalpha(): # Checking if the current character is a letter
                if c.isupper(): # Checking if the current character is an uppercase letter
                    result += chr((ord(c) + ord(key.upper()[j]) - 2 * ord('A')) % 26 + ord('A')); # Encrypting uppercase letters
                    j = (j + 1) % len(key); # Incrementing j and making it wrap around the key length
                else: # If the current character is a lowercase letter
                    result += chr((ord(c) + ord(key.lower()[j]) - 2 * ord('a')) % 26 + ord('a')); # Encrypting lowercase letters
                    j = (j + 1) % len(key); # Incrementing j and making it wrap around the key length
            else: # If the current character is not a letter
                result += c; # Adding the character to the result as it is
        return result; # Returning the encrypted message as a String
    def decrypt(self, message, key): # Defining the decrypt method that takes a message and a key as arguments
        if key.isEmpty(): # Checking if the key is empty
            raise Exception("Key cannot be empty."); # Throwing an exception if the key is empty
        result = ""; # Creating an empty string to store the decrypted message
        j = 0; # Initializing a variable j to keep track of the key index
        for i in range(len(message)): # Iterating through each character in the message
            c = message[i]; # Storing the current character in the message
            if c.isalpha(): # Checking if the current character is a letter
                if c.isupper(): # Checking if the current character is an uppercase letter
                    result += chr(ord('Z') - (25 - (ord(c) - ord(key.upper()[j]))) % 26); # Decrypting uppercase letters
                    j = (j + 1) % len(key); # Incrementing j and making it wrap around the key length
                else: # If the current character is a lowercase letter
                    result += chr(ord('z') - (25 - (ord(c) - ord(key.lower()[j]))) % 26); # Decrypting lowercase letters
                    j = (j + 1) % len(key); # Incrementing j and making it wrap around the key length
            else: # If the current character is not a letter
                result += c; # Adding the character to the result as it is
        return result; # Returning the decrypted message as a String
    def main(self): # Defining the main method
        scanner = Scanner(System.in); # Creating a new Scanner object for user input
        operation = scanner.nextLine().lower(); # Reading the user's operation ('encrypt' or 'decrypt') and converting it to lowercase
        key = scanner.nextLine(); # Reading the user's key
        if operation.equals("encrypt"): # Checking if the user wants to encrypt a message
            plaintext = scanner.nextLine(); # Reading the user's plaintext message
            cipher = Main(); # Creating a new instance of the Main class
            encrypted = cipher.encrypt(plaintext, key); # Encrypting the plaintext message using the given key
            print("Encrypted Message: " + encrypted); # Printing the encrypted message to the console
        elif operation.equals("decrypt"): # Checking if the user wants to decrypt a message
            ciphertext = scanner.nextLine(); # Reading the user's ciphertext message
            cipher = Main(); # Creating a new instance of the Main class
            decrypted = cipher.decrypt(ciphertext, key); # Decrypting the ciphertext message using the given key
            print("Decrypted Message: " + decrypted); # Printing the decrypted message to the console
        else: # If the user entered an invalid operation
            print("Invalid operation. Please choose 'encrypt' or 'decrypt'."); # Printing an error message to the console
        scanner.close(); # Closing the Scanner object

