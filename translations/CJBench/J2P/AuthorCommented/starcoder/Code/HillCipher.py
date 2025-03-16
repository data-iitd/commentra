
import re

class Main:

    def __init__(self):
        self.matrixSize = 0
        self.keyMatrix = []
        self.message = ""
        self.encryptedMessage = ""

    def encrypt(self, message, keyMatrix):
        # Convert the message to uppercase and remove all non-alphabetic characters
        message = message.upper().replace(r'[^A-Z]', '')
        self.matrixSize = len(keyMatrix)

        # Validate that the key matrix has a valid determinant for Hill Cipher
        self.validateDeterminant(keyMatrix)

        self.message = message
        self.encryptedMessage = ""
        index = 0

        # Process the message in blocks of size equal to the key matrix size
        while index < len(message):
            for i in range(self.matrixSize):
                if index < len(message):
                    self.messageVector[i] = ord(message[index]) - ord('A')
                else:
                    self.messageVector[i] = ord('X') - ord('A') # Padding with 'X' if needed
                index += 1

            # Encrypt the message vector using the key matrix
            for i in range(self.matrixSize):
                self.cipherVector[i] = 0
                for j in range(self.matrixSize):
                    self.cipherVector[i] += keyMatrix[i][j] * self.messageVector[j]
                self.cipherVector[i] = self.cipherVector[i] % 26
                self.encryptedMessage += chr(self.cipherVector[i] + ord('A'))

        return self.encryptedMessage

    def validateDeterminant(self, keyMatrix):
        det = self.determinant(keyMatrix) % 26
        if det == 0 or self.gcd(det, 26)!= 1:
            raise Exception("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    def determinant(self, matrix):
        det = 0
        if self.matrixSize == 1:
            return matrix[0][0]
        sign = 1
        subMatrix = []
        for x in range(self.matrixSize):
            subMatrix.append([])
            for i in range(1, self.matrixSize):
                for j in range(self.matrixSize):
                    if j!= x:
                        subMatrix[i - 1].append(matrix[i][j])
            det += sign * matrix[0][x] * self.determinant(subMatrix)
            sign = -sign
        return det

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

if __name__ == "__main__":
    main = Main()

    operation = input().lower()

    matrixSize = int(input())
    keyMatrix = []
    for i in range(matrixSize):
        keyMatrix.append([])
        for j in range(matrixSize):
            keyMatrix[i].append(int(input()))

    if "encrypt" == operation:
        message = input()
        encryptedMessage = main.encrypt(message, keyMatrix)
        print("Encrypted Message: " + encryptedMessage)
    else:
        print("Decryption functionality not implemented in this example.")

