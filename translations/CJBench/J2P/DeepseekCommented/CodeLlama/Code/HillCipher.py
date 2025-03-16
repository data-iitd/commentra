
# Importing the Scanner class for user input
from java.util import Scanner

# Defining the Main class
class Main:

    # Encrypt method to encrypt the message using Hill cipher algorithm
    def encrypt(self, message, keyMatrix):
        message = message.upper().replace("[^A-Z]", "") # Convert message to uppercase and remove non-alphabetic characters
        matrixSize = len(keyMatrix) # Get the size of the key matrix
        self.validateDeterminant(keyMatrix, matrixSize) # Validate the key matrix determinant
        cipherText = "" # Initialize an empty string to build the cipher text
        messageVector = [0] * matrixSize # Initialize an array to hold the message vector
        cipherVector = [0] * matrixSize # Initialize an array to hold the cipher vector
        index = 0 # Initialize the index to traverse the message
        while index < len(message): # Loop through the message
            for i in range(matrixSize): # Populate the message vector
                if index < len(message):
                    messageVector[i] = ord(message[index]) - ord('A') # Convert character to number and add to message vector
                else:
                    messageVector[i] = ord('X') - ord('A') # If message ends, use 'X' as padding
                index += 1
            for i in range(matrixSize): # Calculate the cipher vector
                cipherVector[i] = 0
                for j in range(matrixSize):
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j] # Multiply key matrix row by message vector and add to cipher vector
                cipherVector[i] = cipherVector[i] % 26 # Modulo 26 to keep within the alphabet range
                cipherText += chr(cipherVector[i] + ord('A')) # Convert number back to character and append to cipher text
        return cipherText # Return the encrypted message

    # Validate determinant method to check if the key matrix is valid
    def validateDeterminant(self, keyMatrix, n):
        det = self.determinant(keyMatrix, n) % 26 # Calculate determinant modulo 26
        if det == 0 or self.gcd(det, 26) != 1: # Check if determinant is zero or not coprime to 26
            raise IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.") # Throw exception if invalid

    # Recursive method to calculate the determinant of the key matrix
    def determinant(self, matrix, n):
        det = 0
        if n == 1:
            return matrix[0][0] # Base case for 1x1 matrix
        sign = 1
        subMatrix = [[0] * (n - 1) for _ in range(n - 1)] # Initialize submatrix for recursion
        for x in range(n): # Loop through each element in the first row
            subI = 0
            for i in range(1, n): # Populate submatrix excluding the current row and column
                subJ = 0
                for j in range(n):
                    if j != x:
                        subMatrix[subI][subJ] = matrix[i][j]
                        subJ += 1
                subI += 1
            det += sign * matrix[0][x] * self.determinant(subMatrix, n - 1) # Recursive call and add to determinant
            sign = -sign # Alternate the sign
        return det # Return the determinant

    # Method to calculate the greatest common divisor
    def gcd(self, a, b):
        if b == 0:
            return a # Base case for gcd
        return self.gcd(b, a % b) # Recursive call

    # Main method to handle user input and call the encrypt method
    def main(self):
        scanner = Scanner(System.in) # Initialize scanner for user input
        operation = scanner.nextLine().lower() # Read the operation (encrypt or decrypt)
        matrixSize = scanner.nextInt() # Read the size of the key matrix
        keyMatrix = [[0] * matrixSize for _ in range(matrixSize)] # Initialize the key matrix
        validMatrix = False # Flag to check if the matrix is valid
        while not validMatrix: # Loop until a valid matrix is entered
            try:
                for i in range(matrixSize): # Read the key matrix elements
                    for j in range(matrixSize):
                        keyMatrix[i][j] = scanner.nextInt()
                self.validateDeterminant(keyMatrix, matrixSize) # Validate the key matrix
                validMatrix = True # Set flag to true if valid
            except IllegalArgumentException as e:
                print(e.getMessage()) # Print error message if invalid
                print("Please enter a valid matrix.") # Prompt user to enter a valid matrix
        if "encrypt" == operation: # Check if the operation is encrypt
            scanner.nextLine() # Consume the newline character
            message = scanner.nextLine() # Read the message to encrypt
            encryptedMessage = self.encrypt(message, keyMatrix) # Encrypt the message
            print("Encrypted Message: " + encryptedMessage) # Print the encrypted message
        else:
            print("Decryption functionality not implemented in this example.") # Print message if decryption is not implemented
        scanner.close() # Close the scanner

# Create an instance of the Main class
main = Main()

# Call the main method
main.main()

# End of code
