

import sys

class Main:
    def __init__(self):
        pass

    # Encrypts the input string using the rail fence cipher method with the given number of rails.
    def encrypt(self, str, rails):
        # Base case of single rail or rails are more than the number of characters in the string
        if rails == 1 or rails >= len(str):
            return str

        # Boolean flag to determine if the movement is downward or upward in the rail matrix.
        down = True
        # Create a 2D array to represent the rails (rows) and the length of the string (columns).
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]

        # Initialize all positions in the rail matrix with a placeholder character ('\n').
        for i in range(rails):
            for j in range(len(str)):
                str_rail[i][j] = '\n'

        row = 0
        col = 0
        i = 0
        # Fill the rail matrix with characters from the string based on the rail pattern.
        while col < len(str):
            # Change direction to down when at the first row.
            if row == 0:
                down = True
            # Change direction to up when at the last row.
            elif row == rails - 1:
                down = False

            # Place the character in the current position of the rail matrix.
            str_rail[row][col] = str[i]
            col += 1
            # Move to the next row based on the direction.
            if down:
                row += 1
            else:
                row -= 1
            i += 1

        # Construct the encrypted string by reading characters row by row.
        encrypted_string = ''
        for ch_row in str_rail:
            for ch in ch_row:
                if ch!= '\n':
                    encrypted_string += ch

        return encrypted_string

    # Decrypts the input string using the rail fence cipher method with the given number of rails.
    def decrypt(self, str, rails):
        # Base case of single rail or rails are more than the number of characters in the string
        if rails == 1 or rails >= len(str):
            return str

        # Boolean flag to determine if the movement is downward or upward in the rail matrix.
        down = True

        # Create a 2D array to represent the rails (rows) and the length of the string (columns).
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]
        row = 0
        col = 0
        # Mark the pattern on the rail matrix using '*'.
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False

            str_rail[row][col] = '*'
            col += 1
            if down:
                row += 1
            else:
                row -= 1

        index = 0
        # Fill the rail matrix with characters from the input string based on the marked pattern.
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1

        # Construct the decrypted string by following the zigzag pattern.
        decrypted_string = ''
        row = 0
        col = 0

        while col < len(str):
            # Change direction to down when at the first row.
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False

            # Append the character from the rail matrix to the decrypted string.
            decrypted_string += str_rail[row][col]
            col += 1
            if down:
                row += 1
            else:
                row -= 1

        return decrypted_string

if __name__ == "__main__":
    operation = input()

    rails = int(input())

    if operation.lower() == "encrypt":
        plaintext = input()
        cipher = Main()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message: " + encrypted)
    elif operation.lower() == "decrypt":
        ciphertext = input()
        cipher = Main()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message: " + decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

