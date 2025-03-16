import numpy as np

class RailFenceCipher:
    def encrypt(self, text, rails):
        if rails == 1 or rails >= len(text):
            return text

        # Create a 2D array to store the encrypted string
        str_rail = [['\n' for _ in range(len(text))] for _ in range(rails)]

        row, col = 0
        down = True

        # Fill the 2D array with the given string
        for char in text:
            str_rail[row][col] = char
            col += 1

            if row == 0:
                down = True
            elif row == rails - 1:
                down = False

            row += 1 if down else -1

        # Build the encrypted string from the 2D array
        encrypted_string = ''.join(char for row in str_rail for char in row if char != '\n')
        return encrypted_string

    def decrypt(self, text, rails):
        if rails == 1 or rails >= len(text):
            return text

        # Create a 2D array to store the decrypted string
        str_rail = [['*' for _ in range(len(text))] for _ in range(rails)]

        index = 0

        # Fill the 2D array with the given string
        for i in range(rails):
            for j in range(len(text)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = text[index]
                    index += 1

        decrypted_string = []
        row, col = 0
        down = True

        # Fill the decrypted string from the 2D array
        for _ in range(len(text)):
            decrypted_string.append(str_rail[row][col])
            col += 1

            if row == 0:
                down = True
            elif row == rails - 1:
                down = False

            row += 1 if down else -1

        return ''.join(decrypted_string)

if __name__ == "__main__":
    operation = input("Enter operation (encrypt/decrypt): ")
    rails = int(input("Enter number of rails: "))
    text = input("Enter text: ")

    cipher = RailFenceCipher()

    if operation.lower() == "encrypt":
        encrypted = cipher.encrypt(text, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == "decrypt":
        decrypted = cipher.decrypt(text, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
        
# <END-OF-CODE>
