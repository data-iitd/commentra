import re

class Main:
    # 2D array to hold the Playfair cipher matrix
    matrix = []
    # Key used for generating the cipher matrix
    key = ""

    # Constructor to initialize the key and generate the cipher matrix
    def __init__(self, key):
        self.key = key
        self.generateMatrix()

    # Method to encrypt the plaintext using the Playfair cipher
    def encrypt(self, plaintext):
        # Prepare the plaintext by replacing 'J' with 'I' and formatting it
        plaintext = self.prepareText(plaintext.replace("J", "I"))
        ciphertext = ""

        # Process the plaintext in pairs of characters
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            # Find positions of the characters in the matrix
            pos1 = self.findPosition(char1)
            pos2 = self.findPosition(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]

            # Apply Playfair cipher rules based on the positions of the characters
            if row1 == row2:
                # Same row: shift right
                ciphertext += self.matrix[row1][(col1 + 1) % 5]
                ciphertext += self.matrix[row2][(col2 + 1) % 5]
            elif col1 == col2:
                # Same column: shift down
                ciphertext += self.matrix[(row1 + 1) % 5][col1]
                ciphertext += self.matrix[(row2 + 1) % 5][col2]
            else:
                # Rectangle: swap columns
                ciphertext += self.matrix[row1][col2]
                ciphertext += self.matrix[row2][col1]
        return ciphertext # Return the final ciphertext

    # Method to decrypt the ciphertext using the Playfair cipher
    def decrypt(self, ciphertext):
        plaintext = ""

        # Process the ciphertext in pairs of characters
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            # Find positions of the characters in the matrix
            pos1 = self.findPosition(char1)
            pos2 = self.findPosition(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]

            # Apply Playfair cipher rules based on the positions of the characters
            if row1 == row2:
                # Same row: shift left
                plaintext += self.matrix[row1][(col1 + 4) % 5]
                plaintext += self.matrix[row2][(col2 + 4) % 5]
            elif col1 == col2:
                # Same column: shift up
                plaintext += self.matrix[(row1 + 4) % 5][col1]
                plaintext += self.matrix[(row2 + 4) % 5][col2]
            else:
                # Rectangle: swap columns
                plaintext += self.matrix[row1][col2]
                plaintext += self.matrix[row2][col1]
        return plaintext # Return the final plaintext

    # Method to generate the Playfair cipher matrix based on the key
    def generateMatrix(self):
        # Remove duplicate characters from the key and append the alphabet
        keyWithoutDuplicates = self.removeDuplicateChars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
        self.matrix = [[0 for i in range(5)] for j in range(5)] # Initialize the 5x5 matrix
        index = 0

        # Fill the matrix with characters from the key
        for i in range(5):
            for j in range(5):
                self.matrix[i][j] = keyWithoutDuplicates[index]
                index += 1

    # Method to remove duplicate characters from a string
    def removeDuplicateChars(self, str):
        result = ""
        for i in range(len(str)):
            # Append character if it is not already in the result
            if result.find(str[i]) == -1:
                result += str[i]
        return result # Return the string without duplicates

    # Method to prepare the text for encryption/decryption
    def prepareText(self, text):
        # Convert text to uppercase and remove non-alphabetic characters
        text = text.upper().replace("[^A-Z]", "")
        preparedText = ""
        prevChar = ""

        # Process characters to avoid duplicates and ensure even length
        for c in text:
            if c!= prevChar:
                preparedText += c
                prevChar = c
            else:
                preparedText += "X" + c # Insert 'X' between duplicates
                prevChar = ""
        # Append 'X' if the length is odd
        if len(preparedText) % 2!= 0:
            preparedText += "X"
        return preparedText # Return the prepared text

    # Method to find the position of a character in the matrix
    def findPosition(self, c):
        pos = [0, 0]
        # Search the matrix for the character
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == c:
                    pos[0] = i # Row index
                    pos[1] = j # Column index
                    return pos # Return the position
        return pos # Return default position if not found

if __name__ == "__main__":
    # Read the key from user input
    key = input()
    playfairCipher = Main(key) # Create an instance of Main with the key
    # Read the operation (encrypt/decrypt) from user input
    operation = input()

    # Perform encryption or decryption based on user input
    if operation.lower() == "encrypt":
        plaintext = input() # Read plaintext
        encryptedMessage = playfairCipher.encrypt(plaintext) # Encrypt the plaintext
        print("Encrypted Message: " + encryptedMessage) # Output the encrypted message
    elif operation.lower() == "decrypt":
        ciphertext = input() # Read ciphertext
        decryptedMessage = playfairCipher.decrypt(ciphertext) # Decrypt the ciphertext
        print("Decrypted Message: " + decryptedMessage) # Output the decrypted message
    else:
        # Handle invalid operation input
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

