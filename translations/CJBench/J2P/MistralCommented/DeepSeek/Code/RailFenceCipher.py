import numpy as np

class RailFenceCipher:
    def encrypt(self, text, rails):
        if rails == 1 or rails >= len(text):
            return text

        rail_matrix = [['' for _ in range(len(text))] for _ in range(rails)]
        row, col = 0, 0
        down = True

        for char in text:
            rail_matrix[row][col] = char
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            if down:
                row += 1
            else:
                row -= 1
            col += 1

        encrypted_text = ''
        for rail in rail_matrix:
            encrypted_text += ''.join(rail)

        return encrypted_text

    def decrypt(self, text, rails):
        if rails == 1 or rails >= len(text):
            return text

        rail_matrix = [['' for _ in range(len(text))] for _ in range(rails)]
        row, col = 0, 0
        down = True

        for _ in range(len(text)):
            rail_matrix[row][col] = '*'
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            if down:
                row += 1
            else:
                row -= 1
            col += 1

        index = 0
        for i in range(rails):
            for j in range(len(text)):
                if rail_matrix[i][j] == '*':
                    rail_matrix[i][j] = text[index]
                    index += 1

        decrypted_text = ''
        row, col = 0, 0
        down = True

        for _ in range(len(text)):
            decrypted_text += rail_matrix[row][col]
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            if down:
                row += 1
            else:
                row -= 1
            col += 1

        return decrypted_text

if __name__ == "__main__":
    cipher = RailFenceCipher()
    operation = input().strip()
    rails = int(input().strip())
    if operation.lower() == 'encrypt':
        text = input().strip()
        encrypted = cipher.encrypt(text, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == 'decrypt':
        text = input().strip()
        decrypted = cipher.decrypt(text, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
