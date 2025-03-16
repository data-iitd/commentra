
import string

class Main:
    def __init__(self, key):
        self.key = key
        self.generate_matrix()

    def encrypt(self, plaintext):
        # Prepare the plaintext by replacing 'J' with 'I' and formatting it
        plaintext = self.prepare_text(plaintext.replace("J", "I"))
        ciphertext = ""

        # Process the plaintext in pairs of characters
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            # Find positions of the characters in the matrix
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
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

        return ciphertext  # Return the final ciphertext

    def decrypt(self, ciphertext):
        plaintext = ""

        # Process the ciphertext in pairs of characters
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            # Find positions of the characters in the matrix
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
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

        return plaintext  # Return the final plaintext

    def generate_matrix(self):
        # Remove duplicate characters from the key and append the alphabet
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
        self.matrix = [[0 for _ in range(5)] for _ in range(5)]  # Initialize the 5x5 matrix
        index = 0

        # Fill the matrix with characters from the key
        for i in range(5):
            for j in range(5):
                self.matrix[i][j] = key_without_duplicates[index]
                index += 1

    def remove_duplicate_chars(self, str):
        result = ""
        for char in str:
            if char not in result:
                result += char
        return result  # Return the string without duplicates

    def prepare_text(self, text):
        # Convert text to uppercase and remove non-alphabetic characters
        text = text.upper().replace(" ", "")
        prepared_text = ""
        prev_char = ""

        # Process characters to avoid duplicates and ensure even length
        for char in text:
            if char!= prev_char:
                prepared_text += char
                prev_char = char
            else:
                prepared_text += "X" + char  # Insert 'X' between duplicates
                prev_char = ""

        # Append 'X' if the length is odd
        if len(prepared_text) % 2!= 0:
            prepared_text += "X"

        return prepared_text  # Return the prepared text

    def find_position(self, char):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == char:
                    return [i, j]  # Return the position
        return [0, 0]  # Return default position if not found

# Main method to run the Playfair cipher program
if __name__ == "__main__":
    key = input("Enter the key: ")
    playfair_cipher = Main(key)  # Create an instance of Main with the key
    operation = input("Enter the operation (encrypt/decrypt): ")

    # Perform encryption or decryption based on user input
    if operation.lower() == "encrypt":
        plaintext = input("Enter the plaintext: ")
        encrypted_message = playfair_cipher.encrypt(plaintext)  # Encrypt the plaintext
        print("Encrypted Message:", encrypted_message)  # Output the encrypted message
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter the ciphertext: ")
        decrypted_message = playfair_cipher.decrypt(ciphertext)  # Decrypt the ciphertext
        print("Decrypted Message:", decrypted_message)  # Output the decrypted message
    else:
        # Handle invalid operation input
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

