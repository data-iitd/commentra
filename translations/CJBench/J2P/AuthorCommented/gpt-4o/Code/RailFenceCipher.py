import numpy as np

class RailFenceCipher:
    # Encrypts the input string using the rail fence cipher method with the given number of rails.
    def encrypt(self, text, rails):
        # Base case of single rail or rails are more than the number of characters in the string
        if rails == 1 or rails >= len(text):
            return text

        # Create a 2D array to represent the rails (rows) and the length of the string (columns).
        str_rail = [['\n' for _ in range(len(text))] for _ in range(rails)]

        row, col = 0
        down = True

        # Fill the rail matrix with characters from the string based on the rail pattern.
        for char in text:
            str_rail[row][col] = char
            col += 1

            # Change direction to down or up
            if down:
                row += 1
            else:
                row -= 1

            # Change direction at the top or bottom rail
            if row == 0 or row == rails - 1:
                down = not down

        # Construct the encrypted string by reading characters row by row.
        encrypted_string = ''.join(''.join(row) for row in str_rail).replace('\n', '')
        return encrypted_string

    # Decrypts the input string using the rail fence cipher method with the given number of rails.
    def decrypt(self, text, rails):
        # Base case of single rail or rails are more than the number of characters in the string
        if rails == 1 or rails >= len(text):
            return text

        # Create a 2D array to represent the rails (rows) and the length of the string (columns).
        str_rail = [['\n' for _ in range(len(text))] for _ in range(rails)]
        row, col = 0
        down = True

        # Mark the pattern on the rail matrix using '*'.
        for i in range(len(text)):
            str_rail[row][col] = '*'
            col += 1

            # Change direction to down or up
            if down:
                row += 1
            else:
                row -= 1

            # Change direction at the top or bottom rail
            if row == 0 or row == rails - 1:
                down = not down

        index = 0
        # Fill the rail matrix with characters from the input string based on the marked pattern.
        for i in range(rails):
            for j in range(len(text)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = text[index]
                    index += 1

        # Construct the decrypted string by following the zigzag pattern.
        decrypted_string = []
        row, col = 0
        for _ in range(len(text)):
            decrypted_string.append(str_rail[row][col])
            col += 1

            # Change direction to down or up
            if down:
                row += 1
            else:
                row -= 1

            # Change direction at the top or bottom rail
            if row == 0 or row == rails - 1:
                down = not down

        return ''.join(decrypted_string)

if __name__ == "__main__":
    operation = input("Enter operation (encrypt/decrypt): ").strip()
    rails = int(input("Enter number of rails: "))

    if operation.lower() == "encrypt":
        plaintext = input("Enter plaintext: ")
        cipher = RailFenceCipher()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter ciphertext: ")
        cipher = RailFenceCipher()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

# <END-OF-CODE>
