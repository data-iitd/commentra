
# Class definition for Main
class Main:

    # Method definition for encrypting a message using Hill Cipher algorithm
    def encrypt(self, message, keyMatrix):

        # Convert message to uppercase and remove non-alphabetic characters
        message = message.upper().replace("[^A-Z]", "")

        # Validate the size of the keyMatrix
        matrixSize = len(keyMatrix)

        # Validate determinant of the keyMatrix
        self.validateDeterminant(keyMatrix, matrixSize)

        # Initialize StringBuilder for storing cipherText
        cipherText = StringBuilder()

        # Initialize messageVector and cipherVector of size matrixSize
        messageVector = [0] * matrixSize
        cipherVector = [0] * matrixSize

        # Initialize index for iterating through message
        index = 0

        # Encrypt message character by character
        while index < len(message):

            # Convert each character of message to its corresponding integer value
            for i in range(matrixSize):
                if index < len(message):
                    # Store the integer value of current character in messageVector
                    messageVector[i] = ord(message[index]) - ord('A')
                else:
                    # If message is shorter than the keyMatrix, fill the remaining messageVector with 'X'
                    messageVector[i] = ord('X') - ord('A')
                index += 1

            # Multiply messageVector with keyMatrix and store the result in cipherVector
            for i in range(matrixSize):
                cipherVector[i] = 0
                for j in range(matrixSize):
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j]
                # Perform modulo 26 operation on cipherVector to get the final cipherText character
                cipherVector[i] = cipherVector[i] % 26
                # Append the final character to StringBuilder cipherText
                cipherText.append(chr(cipherVector[i] + ord('A')))

        # Return the encrypted message as a String
        return cipherText.toString()

    # Private method for validating determinant of keyMatrix
    def validateDeterminant(self, keyMatrix, n):

        # Calculate the determinant of keyMatrix modulo 26
        det = self.determinant(keyMatrix, n) % 26

        # Check if determinant is zero or not coprime to 26
        if det == 0 or self.gcd(det, 26)!= 1:
            # Throw an exception if determinant is invalid
            raise Exception("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    # Recursive method for calculating determinant of a matrix
    def determinant(self, matrix, n):

        # Base case: determinant of a 1x1 matrix
        if n == 1:
            return matrix[0][0]

        # Initialize sign, subMatrix and calculate determinant recursively
        sign = 1
        subMatrix = [[0] * (n - 1) for i in range(n - 1)]
        det = 0

        # Calculate determinant of subMatrices and add to the final determinant
        for x in range(n):
            subI = 0
            for i in range(1, n):
                subJ = 0
                for j in range(n):
                    if j!= x:
                        # Store the subMatrix elements
                        subMatrix[subI][subJ] = matrix[i][j]
                        subJ += 1
                subI += 1
            det += sign * matrix[0][x] * self.determinant(subMatrix, n - 1)
            sign = -sign

        # Return the final determinant
        return det

    # Helper method for calculating greatest common divisor
    def gcd(self, a, b):

        # Base case: if b is zero, return a
        if b == 0:
            return a

        # Recursive case: calculate gcd of b and the remainder of a modulo b
        return self.gcd(b, a % b)

# Main method for taking user input and calling encrypt method
if __name__ == "__main__":

    # Initialize Scanner for user input
    scanner = Scanner(sys.stdin)

    # Get user operation and matrix size
    operation = scanner.nextLine().lower()
    matrixSize = scanner.nextInt()

    # Initialize keyMatrix with user input
    keyMatrix = [[0] * matrixSize for i in range(matrixSize)]
    validMatrix = False

    # Validate user input for keyMatrix
    while not validMatrix:
        try:
            for i in range(matrixSize):
                for j in range(matrixSize):
                    keyMatrix[i][j] = scanner.nextInt()
                scanner.nextLine() # consume newline character
            Main().validateDeterminant(keyMatrix, matrixSize)
            validMatrix = True
        except Exception as e:
            print(e.getMessage())
            print("Please enter a valid matrix.")
            scanner.nextLine() # consume error message and newline character

    # Perform encryption or decryption based on user operation
    if "encrypt".equals(operation):
        scanner.nextLine() # consume newline character
        message = scanner.nextLine()
        encryptedMessage = Main().encrypt(message, keyMatrix)
        print("Encrypted Message: " + encryptedMessage)
    else:
        print("Decryption functionality not implemented in this example.")

    # Close Scanner
    scanner.close()

