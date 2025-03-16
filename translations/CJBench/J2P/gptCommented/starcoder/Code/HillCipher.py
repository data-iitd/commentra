import re

class Main:
    # Method to encrypt a message using a key matrix
    def encrypt(self, message, keyMatrix):
        # Convert the message to uppercase and remove non-alphabetic characters
        message = message.upper().replace(r'[^A-Z]', '')
        matrixSize = len(keyMatrix) # Get the size of the key matrix
        self.validateDeterminant(keyMatrix, matrixSize) # Validate the key matrix determinant
        cipherText = '' # String to build the encrypted message
        messageVector = [0] * matrixSize # Vector to hold message characters
        cipherVector = [0] * matrixSize # Vector to hold encrypted characters
        index = 0 # Index to track the position in the message

        # Process the message in blocks of size equal to the matrix size
        while index < len(message):
            # Fill the message vector with characters from the message
            for i in range(matrixSize):
                if index < len(message):
                    messageVector[i] = ord(message[index]) - ord('A') # Convert char to int
                else:
                    messageVector[i] = ord('X') - ord('A') # Pad with 'X' if message is shorter than matrix size
                index += 1
            # Encrypt the message vector using the key matrix
            for i in range(matrixSize):
                cipherVector[i] = 0 # Initialize cipher vector
                for j in range(matrixSize):
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j] # Matrix multiplication
                cipherVector[i] = cipherVector[i] % 26 # Modulo 26 to wrap around alphabet
                cipherText += chr(cipherVector[i] + ord('A')) # Convert back to char and append to cipher text
        return cipherText # Return the final encrypted message

    # Method to validate the determinant of the key matrix
    def validateDeterminant(self, keyMatrix, n):
        det = self.determinant(keyMatrix, n) % 26 # Calculate determinant modulo 26
        # Check if determinant is zero or not coprime to 26
        if det == 0 or self.gcd(det, 26)!= 1:
            raise Exception("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    # Method to calculate the determinant of a matrix
    def determinant(self, matrix, n):
        det = 0 # Initialize determinant
        if n == 1:
            return matrix[0][0] # Base case for 1x1 matrix
        sign = 1 # Variable to alternate signs for cofactor expansion
        subMatrix = [[0] * (n - 1) for i in range(n - 1)] # Submatrix for determinant calculation

        # Calculate determinant using cofactor expansion
        for x in range(n):
            subI = 0 # Row index for submatrix
            for i in range(1, n):
                subJ = 0 # Column index for submatrix
                for j in range(n):
                    if j!= x:
                        subMatrix[subI][subJ] = matrix[i][j] # Fill submatrix
                        subJ += 1
                subI += 1
            det += sign * matrix[0][x] * self.determinant(subMatrix, n - 1) # Recursive determinant calculation
            sign = -sign # Alternate sign
        return det # Return the calculated determinant

    # Method to calculate the greatest common divisor (GCD) of two numbers
    def gcd(self, a, b):
        if b == 0:
            return a # Base case for GCD
        return self.gcd(b, a % b) # Recursive GCD calculation

if __name__ == '__main__':
    main = Main() # Create an instance of the Main class
    operation = input().lower() # Read the operation (encrypt/decrypt)
    matrixSize = int(input()) # Read the size of the key matrix
    keyMatrix = [[0] * matrixSize for i in range(matrixSize)] # Initialize the key matrix
    validMatrix = False # Flag to check if the matrix is valid

    # Loop to read the key matrix and validate it
    while not validMatrix:
        try:
            # Read the key matrix values from user input
            for i in range(matrixSize):
                for j in range(matrixSize):
                    keyMatrix[i][j] = int(input())
            main.validateDeterminant(keyMatrix, matrixSize) # Validate the key matrix
            validMatrix = True # Set flag to true if validation is successful
        except Exception as e:
            # Handle invalid matrix input
            print(e)
            print("Please enter a valid matrix.")

    # Check if the operation is encryption
    if "encrypt".equals(operation):
        message = input() # Read the message to encrypt
        encryptedMessage = main.encrypt(message, keyMatrix) # Encrypt the message
        print("Encrypted Message: " + encryptedMessage) # Output the encrypted message
    else:
        print("Decryption functionality not implemented in this example.") # Placeholder for decryption

