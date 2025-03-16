
import re

class Main:
    def __init__(self):
        self.matrixSize = 0
        self.keyMatrix = []
        self.message = ""
        self.encryptedMessage = ""

    def encrypt(self, message, keyMatrix):
        self.message = message.upper()
        self.message = re.sub(r'[^A-Z]', '', self.message)
        self.matrixSize = len(keyMatrix)
        self.validateDeterminant(keyMatrix, self.matrixSize)
        self.encryptedMessage = ""
        messageVector = [0] * self.matrixSize
        cipherVector = [0] * self.matrixSize
        index = 0
        while index < len(self.message):
            for i in range(self.matrixSize):
                if index < len(self.message):
                    messageVector[i] = ord(self.message[index]) - ord('A')
                else:
                    messageVector[i] = ord('X') - ord('A')
                index += 1
            for i in range(self.matrixSize):
                cipherVector[i] = 0
                for j in range(self.matrixSize):
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j]
                cipherVector[i] = cipherVector[i] % 26
                self.encryptedMessage += chr(cipherVector[i] + ord('A'))
        return self.encryptedMessage

    def validateDeterminant(self, keyMatrix, n):
        det = self.determinant(keyMatrix, n) % 26
        if det == 0 or self.gcd(det, 26)!= 1:
            raise Exception("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    def determinant(self, matrix, n):
        det = 0
        if n == 1:
            return matrix[0][0]
        sign = 1
        subMatrix = [[0] * (n - 1) for i in range(n - 1)]
        for x in range(n):
            subI = 0
            for i in range(1, n):
                subJ = 0
                for j in range(n):
                    if j!= x:
                        subMatrix[subI][subJ] = matrix[i][j]
                        subJ += 1
                subI += 1
            det += sign * matrix[0][x] * self.determinant(subMatrix, n - 1)
            sign = -sign
        return det

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

if __name__ == "__main__":
    main = Main()
    operation = input().lower()
    main.matrixSize = int(input())
    keyMatrix = [[0] * main.matrixSize for i in range(main.matrixSize)]
    validMatrix = False
    while not validMatrix:
        try:
            for i in range(main.matrixSize):
                for j in range(main.matrixSize):
                    keyMatrix[i][j] = int(input())
            main.validateDeterminant(keyMatrix, main.matrixSize)
            validMatrix = True
        except Exception as e:
            print(e)
            print("Please enter a valid matrix.")
    if "encrypt" == operation:
        message = input()
        encryptedMessage = main.encrypt(message, keyMatrix)
        print("Encrypted Message: " + encryptedMessage)
    else:
        print("Decryption functionality not implemented in this example.")

