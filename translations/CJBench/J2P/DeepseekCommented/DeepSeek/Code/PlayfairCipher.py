class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.generate_matrix()  # Generate the 5x5 matrix using the key

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext.replace("J", "I"))  # Prepare the plaintext
        ciphertext = ""  # String to build the encrypted message
        for i in range(0, len(plaintext), 2):  # Process the plaintext in pairs
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            pos1 = self.find_position(char1)  # Find the position of char1 in the matrix
            pos2 = self.find_position(char2)  # Find the position of char2 in the matrix
            row1, col1 = pos1
            row2, col2 = pos2
            if row1 == row2:  # If characters are in the same row
                ciphertext += self.matrix[row1][(col1 + 1) % 5]  # Shift right within the row
                ciphertext += self.matrix[row2][(col2 + 1) % 5]  # Shift right within the row
            elif col1 == col2:  # If characters are in the same column
                ciphertext += self.matrix[(row1 + 1) % 5][col1]  # Shift down within the column
                ciphertext += self.matrix[(row2 + 1) % 5][col2]  # Shift down within the column
            else:  # If characters form a rectangle in the matrix
                ciphertext += self.matrix[row1][col2]  # Swap columns
                ciphertext += self.matrix[row2][col1]  # Swap columns
        return ciphertext  # Return the encrypted message

    def decrypt(self, ciphertext):
        plaintext = ""  # String to build the decrypted message
        for i in range(0, len(ciphertext), 2):  # Process the ciphertext in pairs
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            pos1 = self.find_position(char1)  # Find the position of char1 in the matrix
            pos2 = self.find_position(char2)  # Find the position of char2 in the matrix
            row1, col1 = pos1
            row2, col2 = pos2
            if row1 == row2:  # If characters are in the same row
                plaintext += self.matrix[row1][(col1 + 4) % 5]  # Shift left within the row
                plaintext += self.matrix[row2][(col2 + 4) % 5]  # Shift left within the row
            elif col1 == col2:  # If characters are in the same column
                plaintext += self.matrix[(row1 + 4) % 5][col1]  # Shift up within the column
                plaintext += self.matrix[(row2 + 4) % 5][col2]  # Shift up within the column
            else:  # If characters form a rectangle in the matrix
                plaintext += self.matrix[row1][col2]  # Swap columns
                plaintext += self.matrix[row2][col1]  # Swap columns
        return plaintext  # Return the decrypted message

    def generate_matrix(self):
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")  # Remove duplicates from the key
        self.matrix = [list(key_without_duplicates[i * 5:(i + 1) * 5]) for i in range(5)]  # Initialize the matrix

    def remove_duplicate_chars(self, str):
        result = ""
        for char in str:
            if char not in result:  # Check if the character is already in the result
                result += char
        return result  # Return the string without duplicates

    def prepare_text(self, text):
        text = text.upper().replace(" ", "")  # Convert to uppercase and remove spaces
        prepared_text = ""
        prev_char = None
        for char in text:  # Process each character
            if char != prev_char:  # If the character is not a repeat
                prepared_text += char
                prev_char = char
            else:  # If the character is a repeat
                prepared_text += 'X' + char
                prev_char = None
        if len(prepared_text) % 2 != 0:  # If the length of the prepared text is odd
            prepared_text += 'X'  # Append an 'X' to make it even
        return prepared_text  # Return the prepared text

    def find_position(self, c):
        for i in range(5):  # Iterate through the matrix rows
            for j in range(5):  # Iterate through the matrix columns
                if self.matrix[i][j] == c:  # If the character is found in the matrix
                    return (i, j)  # Return the position
        return (None, None)  # Return the position (should never reach here)


# Main function to run the Playfair cipher application
def main():
    key = input()  # Read the key from the user
    playfair_cipher = PlayfairCipher(key)  # Create an instance of the Playfair cipher with the key
    operation = input().strip().lower()  # Read the operation (encrypt/decrypt) from the user
    if operation == "encrypt":  # If the operation is encrypt
        plaintext = input().strip()  # Read the plaintext from the user
        encrypted_message = playfair_cipher.encrypt(plaintext)  # Encrypt the plaintext
        print("Encrypted Message:", encrypted_message)  # Print the encrypted message
    elif operation == "decrypt":  # If the operation is decrypt
        ciphertext = input().strip()  # Read the ciphertext from the user
        decrypted_message = playfair_cipher.decrypt(ciphertext)  # Decrypt the ciphertext
        print("Decrypted Message:", decrypted_message)  # Print the decrypted message
    else:  # If the operation is invalid
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")  # Print an error message


if __name__ == "__main__":
    main()
