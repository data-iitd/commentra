
import re

class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.matrix = self.generate_matrix()

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext)
        ciphertext = ""
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            if pos1[0] == pos2[0]:
                # If the characters are in the same row, apply the first rule
                ciphertext += self.matrix[pos1[0]][(pos1[1] + 1) % 5]
                ciphertext += self.matrix[pos2[0]][(pos2[1] + 1) % 5]
                # Add comments for the first rule
                # If both characters are in the same row, swap their columns and get the next character from their respective columns
            elif pos1[1] == pos2[1]:
                # If the characters are in the same column, apply the second rule
                ciphertext += self.matrix[(pos1[0] + 1) % 5][pos1[1]]
                ciphertext += self.matrix[(pos2[0] + 1) % 5][pos2[1]]
                # Add comments for the second rule
                # If both characters are in the same column, swap their rows and get the next character from their respective rows
            else:
                # If the characters are not in the same row or column, apply the third rule
                ciphertext += self.matrix[pos1[0]][pos2[1]]
                ciphertext += self.matrix[pos2[0]][pos1[1]]
                # Add comments for the third rule
                # If the characters are not in the same row or column, swap their positions and get the next character from their respective positions
        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ""
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            if pos1[0] == pos2[0]:
                # If the characters are in the same row, apply the first rule
                plaintext += self.matrix[pos1[0]][(pos1[1] + 4) % 5]
                plaintext += self.matrix[pos2[0]][(pos2[1] + 4) % 5]
                # Add comments for the first rule
                # If both characters are in the same row, swap their columns and get the next character from their respective columns, but this time from the opposite sides
            elif pos1[1] == pos2[1]:
                # If the characters are in the same column, apply the second rule
                plaintext += self.matrix[(pos1[0] + 4) % 5][pos1[1]]
                plaintext += self.matrix[(pos2[0] + 4) % 5][pos2[1]]
                # Add comments for the second rule
                # If both characters are in the same column, swap their rows and get the next character from their respective rows, but this time from the opposite sides
            else:
                # If the characters are not in the same row or column, apply the third rule
                plaintext += self.matrix[pos1[0]][pos2[1]]
                plaintext += self.matrix[pos2[0]][pos1[1]]
                # Add comments for the third rule
                # If the characters are not in the same row or column, swap their positions and get the next character from their respective positions, but this time from the opposite sides
        return plaintext

    def generate_matrix(self):
        # Remove duplicate characters from the 'key' and 'matrix'
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")

        # Initialize the 'matrix' with the given size
        matrix = [["" for i in range(5)] for j in range(5)]

        # Populate the 'matrix' with the unique characters from the 'key'
        index = 0
        for i in range(5):
            for j in range(5):
                matrix[i][j] = key_without_duplicates[index]
                index += 1
        return matrix

    def remove_duplicate_chars(self, str):
        # Initialize an empty string for storing the unique characters
        result = ""

        # Iterate through the characters in the given string
        for c in str:
            # If the character is not already in the string, add it
            if c not in result:
                result += c
        return result

    def prepare_text(self, text):
        # Convert the text to uppercase
        text = text.upper()

        # Remove non-alphabetic characters and replace 'J' with 'I'
        text = re.sub("[^A-Z]", "", text)
        text = text.replace("J", "I")

        # Initialize an empty string for storing the prepared text
        prepared_text = ""

        # Iterate through the characters in the prepared text
        prev_char = ""
        for c in text:
            # If the character is different from the previous character, add it to the string
            if c != prev_char:
                prepared_text += c
                prev_char = c
            else:
                # If the character is the same as the previous character, add 'X' and the character to the string
                prepared_text += "X" + c
                prev_char = ""
        return prepared_text

    def find_position(self, c):
        # Initialize an empty list for storing the positions
        pos = []

        # Iterate through the rows and columns of the 'matrix'
        for i in range(5):
            for j in range(5):
                # If the character is found, store its position in the list and return it
                if self.matrix[i][j] == c:
                    pos.append(i)
                    pos.append(j)
                    return pos
        # If the character is not found, return an empty list
        return pos

# Main method for running the program
if __name__ == "__main__":
    # Initialize a Scanner for reading user input
    scanner = input("Enter the key: ")

    # Create an instance of the 'PlayfairCipher' class with the given 'key'
    playfair_cipher = PlayfairCipher(scanner)

    # Read the operation ('encrypt' or 'decrypt') from the user
    operation = input("Enter the operation (encrypt or decrypt): ")

    # Read the plaintext or ciphertext from the user based on the operation
    if operation.lower() == "encrypt":
        plaintext = input("Enter the plaintext: ")
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter the ciphertext: ")
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

# END-OF-CODE
