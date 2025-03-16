import re

class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.matrix = self.generateMatrix(key)

    def generateMatrix(self, key):
        key = key.upper() + "ABCDEFGHIKLMNOPQRSTUVWXYZ"
        key = "".join(sorted(set(key), key=key.index))
        matrix = [[key[5 * i + j] for j in range(5)] for i in range(5)]
        return matrix

    def encrypt(self, plaintext):
        plaintext = self.prepareText(plaintext)
        ciphertext = ""
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            pos1 = self.findPosition(char1)
            pos2 = self.findPosition(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]
            if row1 == row2:
                ciphertext += self.matrix[row1][(col1 + 1) % 5]
                ciphertext += self.matrix[row2][(col2 + 1) % 5]
            elif col1 == col2:
                ciphertext += self.matrix[(row1 + 1) % 5][col1]
                ciphertext += self.matrix[(row2 + 1) % 5][col2]
            else:
                ciphertext += self.matrix[row1][col2]
                ciphertext += self.matrix[row2][col1]
        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ""
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            pos1 = self.findPosition(char1)
            pos2 = self.findPosition(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]
            if row1 == row2:
                plaintext += self.matrix[row1][(col1 + 4) % 5]
                plaintext += self.matrix[row2][(col2 + 4) % 5]
            elif col1 == col2:
                plaintext += self.matrix[(row1 + 4) % 5][col1]
                plaintext += self.matrix[(row2 + 4) % 5][col2]
            else:
                plaintext += self.matrix[row1][col2]
                plaintext += self.matrix[row2][col1]
        return plaintext

    def prepareText(self, text):
        text = text.upper()
        text = re.sub("[^A-Z]", "", text)
        text = text + "X" if len(text) % 2!= 0 else text
        return text

    def findPosition(self, c):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == c:
                    return [i, j]
        return [-1, -1]

if __name__ == "__main__":
    key = input()
    playfairCipher = PlayfairCipher(key)
    operation = input()
    if operation.lower() == "encrypt":
        plaintext = input()
        encryptedMessage = playfairCipher.encrypt(plaintext)
        print("Encrypted Message: " + encryptedMessage)
    elif operation.lower() == "decrypt":
        ciphertext = input()
        decryptedMessage = playfairCipher.decrypt(ciphertext)
        print("Decrypted Message: " + decryptedMessage)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

