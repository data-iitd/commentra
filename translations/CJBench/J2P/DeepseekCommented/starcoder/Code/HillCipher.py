import re

class Main:
    def encrypt(self, message, keyMatrix):
        message = message.upper().replace('[^A-Z]', '')
        matrixSize = len(keyMatrix)
        self.validateDeterminant(keyMatrix, matrixSize)
        cipherText = []
        messageVector = [0] * matrixSize
        cipherVector = [0] * matrixSize
        index = 0
        while index < len(message):
            for i in range(matrixSize):
                if index < len(message):
                    messageVector[i] = ord(message[index]) - ord('A')
                    index += 1
                else:
                    messageVector[i] = ord('X') - ord('A')
            for i in range(matrixSize):
                cipherVector[i] = 0
                for j in range(matrixSize):
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j]
                cipherVector[i] = cipherVector[i] % 26
                cipherText.append(chr(cipherVector[i] + ord('A')))
        return ''.join(cipherText)

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

    def main(self):
        scanner = Scanner(System.in)
        hillCipher = Main()
        operation = scanner.nextLine().lower()
        matrixSize = scanner.nextInt()
        keyMatrix = [[0] * matrixSize for i in range(matrixSize)]
        validMatrix = False
        while not validMatrix:
            try:
                for i in range(matrixSize):
                    for j in range(matrixSize):
                        keyMatrix[i][j] = scanner.nextInt()
                hillCipher.validateDeterminant(keyMatrix, matrixSize)
                validMatrix = True
            except Exception as e:
                print(e.args[0])
                print("Please enter a valid matrix.")
        if "encrypt" == operation:
            scanner.nextLine()
            message = scanner.nextLine()
            encryptedMessage = hillCipher.encrypt(message, keyMatrix)
            print("Encrypted Message: " + encryptedMessage)
        else:
            print("Decryption functionality not implemented in this example.")
        scanner.close()

# 