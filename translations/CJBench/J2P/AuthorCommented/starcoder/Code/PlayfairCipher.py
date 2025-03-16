
import string

class Main:

    def __init__(self, key):
        self.key = key
        self.matrix = self.generateMatrix()

    def generateMatrix(self):
        keyWithoutDuplicates = self.removeDuplicateChars(self.key + string.ascii_uppercase)
        matrix = [[0 for x in range(5)] for y in range(5)]
        index = 0

        # Fill the matrix row by row
        for i in range(5):
            for j in range(5):
                matrix[i][j] = keyWithoutDuplicates[index]
                index += 1
        return matrix

    def removeDuplicateChars(self, str):
        result = ""
        for i in range(len(str)):
            if result.find(str[i]) == -1:
                result += str[i]
        return result

    def prepareText(self, text):
        text = text.upper().replace('J', 'I').replace('[^A-Z]', '')
        preparedText = ""
        prevChar = ''
        for c in text:
            if c!= prevChar:
                preparedText += c
                prevChar = c
            else:
                preparedText += 'X' + c
                prevChar = ''
        if len(preparedText) % 2!= 0:
            preparedText += 'X'
        return preparedText

    def findPosition(self, c):
        pos = [0, 0]
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == c:
                    pos[0] = i
                    pos[1] = j
                    return pos
        return pos

    def encrypt(self, plaintext):
        plaintext = self.prepareText(plaintext)
        ciphertext = ""

        # Process pairs of characters
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

        # Process pairs of characters
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

if __name__ == '__main__':
    key = input()
    playfairCipher = Main(key)
    operation = input()
    if operation.lower() == 'encrypt':
        plaintext = input()
        encryptedMessage = playfairCipher.encrypt(plaintext)
        print("Encrypted Message: " + encryptedMessage)
    elif operation.lower() == 'decrypt':
        ciphertext = input()
        decryptedMessage = playfairCipher.decrypt(ciphertext)
        print("Decrypted Message: " + decryptedMessage)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

