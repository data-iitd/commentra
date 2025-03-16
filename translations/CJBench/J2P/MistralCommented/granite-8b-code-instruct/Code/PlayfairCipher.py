

import string

class Main:
    # Declare a private 2D character array'matrix' and a private String 'key'
    def __init__(self, key):
        self.key = key
        self.generate_matrix()

    # Encrypts the given plaintext using the Playfair Cipher algorithm
    def encrypt(self, plaintext):
        # Prepare the plaintext for encryption by converting it to uppercase and removing non-alphabetic characters
        plaintext = self.prepare_text(plaintext.replace("J", "I"))

        # Initialize an empty StringBuilder for storing the encrypted characters
        ciphertext = ""

        # Iterate through the plaintext in pairs of two characters
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]

            # Find the positions of 'char1' and 'char2' in the'matrix'
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)

            # Determine the encryption rule based on the positions of 'char1' and 'char2'
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]

            if row1 == row2:
                # If the characters are in the same row, apply the first rule
                ciphertext += self.matrix[row1][(col1 + 1) % 5]
                ciphertext += self.matrix[row2][(col2 + 1) % 5]
                # Add comments for the first rule
                # If both characters are in the same row, swap their columns and get the next character from their respective columns
            elif col1 == col2:
                # If the characters are in the same column, apply the second rule
                ciphertext += self.matrix[(row1 + 1) % 5][col1]
                ciphertext += self.matrix[(row2 + 1) % 5][col2]
                # Add comments for the second rule
                # If both characters are in the same column, swap their rows and get the next character from their respective rows
            else:
                # If the characters are not in the same row or column, apply the third rule
                ciphertext += self.matrix[row1][col2]
                ciphertext += self.matrix[row2][col1]
                # Add comments for the third rule
                # If the characters are not in the same row or column, swap their positions and get the next character from their respective positions

        # Return the encrypted message as a String
        return ciphertext

    # Decrypts the given ciphertext using the Playfair Cipher algorithm
    def decrypt(self, ciphertext):
        # Initialize an empty StringBuilder for storing the decrypted characters
        plaintext = ""

        # Iterate through the ciphertext in pairs of two characters
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]

            # Find the positions of 'char1' and 'char2' in the'matrix'
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)

            # Determine the decryption rule based on the positions of 'char1' and 'char2'
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]

            if row1 == row2:
                # If the characters are in the same row, apply the first rule
                plaintext += self.matrix[row1][(col1 + 4) % 5]
                plaintext += self.matrix[row2][(col2 + 4) % 5]
                # Add comments for the first rule
                # If both characters are in the same row, swap their columns and get the next character from their respective columns, but this time from the opposite sides
            elif col1 == col2:
                # If the characters are in the same column, apply the second rule
                plaintext += self.matrix[(row1 + 4) % 5][col1]
                plaintext += self.matrix[(row2 + 4) % 5][col2]
                # Add comments for the second rule
                # If both characters are in the same column, swap their rows and get the next character from their respective rows, but this time from the opposite sides
            else:
                # If the characters are not in the same row or column, apply the third rule
                plaintext += self.matrix[row1][col2]
                plaintext += self.matrix[row2][col1]
                # Add comments for the third rule
                # If the characters are not in the same row or column, swap their positions and get the next character from their respective positions, but this time from the opposite sides

        # Return the decrypted message as a String
        return plaintext

    # Generates the'matrix' based on the given 'key'
    def generate_matrix(self):
        # Remove duplicate characters from the 'key' and'matrix'
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")

        # Initialize the'matrix' with the given size
        self.matrix = [[0 for _ in range(5)] for _ in range(5)]

        # Populate the'matrix' with the unique characters from the 'key'
        index = 0
        for i in range(5):
            for j in range(5):
                self.matrix[i][j] = key_without_duplicates[index]
                index += 1

    # Removes duplicate characters from the given String
    def remove_duplicate_chars(self, str):
        # Initialize an empty StringBuilder for storing the unique characters
        result = ""

        # Iterate through the characters in the given String
        for char in str:
            if char not in result:
                result += char

        # Return the StringBuilder as a String
        return result

    # Prepares the given text for encryption by converting it to uppercase and removing non-alphabetic characters
    def prepare_text(self, text):
        # Convert the text to uppercase
        text = text.upper()

        # Remove non-alphabetic characters and replace 'J' with 'I'
        text = text.replace(" ", "")
        text = text.replace("J", "I")

        # Initialize an empty StringBuilder for storing the prepared text
        prepared_text = ""

        # Iterate through the characters in the prepared text
        prev_char = ""
        for char in text:
            if char!= prev_char:
                prepared_text += char
                prev_char = char
            else:
                prepared_text += "X" + char
                prev_char = ""

        # If the length of the prepared text is odd, add an extra 'X' at the end
        if len(prepared_text) % 2!= 0:
            prepared_text += "X"

        # Return the prepared text as a String
        return prepared_text

    # Finds the positions of the given character in the'matrix'
    def find_position(self, char):
        # Initialize an empty integer array for storing the positions
        pos = [0, 0]

        # Iterate through the rows and columns of the'matrix'
        for i in range(5):
            for j in range(5):
                # If the character is found, store its position in the integer array and return it
                if self.matrix[i][j] == char:
                    pos[0] = i
                    pos[1] = j
                    return pos

        # If the character is not found, return an empty integer array
        return pos

# Main method for running the program
if __name__ == "__main__":
    # Initialize a Scanner for reading user input
    scanner = input()

    # Read the 'key' from the user
    key = scanner.nextLine()

    # Create an instance of the 'Main' class with the given 'key'
    playfair_cipher = Main(key)

    # Read the operation ('encrypt' or 'decrypt') from the user
    operation = scanner.nextLine()

    # Read the plaintext or ciphertext from the user based on the operation
    if operation.lower() == "encrypt":
        plaintext = scanner.nextLine()
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print("Encrypted Message: " + encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = scanner.nextLine()
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print("Decrypted Message: " + decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

    # Close the Scanner
    scanner.close()

