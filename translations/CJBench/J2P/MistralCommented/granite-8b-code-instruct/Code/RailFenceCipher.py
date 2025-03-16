
import sys

class Main:
    def __init__(self):
        pass

    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            # If the number of rails is 1 or equal to the length of the string, return the original string
            return str

        down = True  # Flag to determine the direction of traversing the rail fence
        str_rail = [['\n'] * len(str) for _ in range(rails)]  # 2D array to store the encrypted string

        # Initialize the 2D array with newline character
        for i in range(rails):
            str_rail[i] = ['\n'] * len(str)

        row = 0
        col = 0
        i = 0

        # Fill the 2D array with the given string
        while col < len(str):
            if row == 0:
                down = True  # Reset the direction flag if we start a new row
            elif row == rails - 1:
                down = False  # Change the direction flag if we reach the last row
            str_rail[row][col] = str[i]  # Store the character from the string into the 2D array
            col += 1  # Increment the column index
            if down:
                row += 1  # Increment the row index if moving down
            else:
                row -= 1  # Decrement the row index if moving up
            i += 1

        # Build the encrypted string from the 2D array
        encrypted_str = ''
        for row in str_rail:
            for ch in row:
                if ch!= '\n':  # Skip newline character while building the encrypted string
                    encrypted_str += ch

        # Return the encrypted string
        return encrypted_str

    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            # If the number of rails is 1 or equal to the length of the string, return the original string
            return str

        down = True  # Flag to determine the direction of traversing the rail fence
        str_rail = [['*'] * len(str) for _ in range(rails)]  # 2D array to store the decrypted string

        # Initialize the 2D array with asterisks
        for i in range(rails):
            str_rail[i] = ['*'] * len(str)

        index = 0  # Index to fill the characters from the given string into the 2D array

        # Fill the 2D array with the given string
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]  # Replace the asterisk with the character from the string
                    index += 1

        # Build the decrypted string from the 2D array
        decrypted_str = ''
        row = 0
        col = 0

        # Fill the StringBuilder with the characters from the 2D array
        while col < len(str):
            if row == 0:
                down = True  # Reset the direction flag if we start a new row
            elif row == rails - 1:
                down = False  # Change the direction flag if we reach the last row
            decrypted_str += str_rail[row][col]  # Append the character from the 2D array to the StringBuilder
            col += 1  # Increment the column index
            if down:
                row += 1  # Increment the row index if moving down
            else:
                row -= 1  # Decrement the row index if moving up

        # Return the decrypted string
        return decrypted_str

if __name__ == "__main__":
    operation = input("Enter operation (encrypt/decrypt): ")  # Read the operation from the user
    rails = int(input("Enter number of rails: "))  # Read the number of rails from the user

    cipher = Main()  # Create an instance of the Main class

    if operation.lower() == "encrypt":  # If the user chooses to encrypt
        plaintext = input("Enter plaintext: ")  # Read the plaintext from the user
        encrypted = cipher.encrypt(plaintext, rails)  # Encrypt the plaintext using the rail fence cipher
        print("Encrypted Message:", encrypted)  # Print the encrypted message
    elif operation.lower() == "decrypt":  # If the user chooses to decrypt
        ciphertext = input("Enter ciphertext: ")  # Read the ciphertext from the user
        decrypted = cipher.decrypt(ciphertext, rails)  # Decrypt the ciphertext using the rail fence cipher
        print("Decrypted Message:", decrypted)  # Print the decrypted message
    else:  # If the user enters an invalid operation
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")  # Print an error message