import numpy as np

# Class definition for Main
class Main:

    # Method definition for encrypting a message using Hill Cipher algorithm
    def encrypt(self, message, key_matrix):
        # Convert message to uppercase and remove non-alphabetic characters
        message = ''.join(filter(str.isalpha, message)).upper()

        # Validate the size of the key_matrix
        matrix_size = key_matrix.shape[0]

        # Validate determinant of the key_matrix
        self.validate_determinant(key_matrix)

        # Initialize cipherText
        cipher_text = []

        # Encrypt message character by character
        index = 0

        while index < len(message):
            # Create message vector
            message_vector = np.zeros(matrix_size, dtype=int)

            for i in range(matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')
                    index += 1
                else:
                    message_vector[i] = ord('X') - ord('A')  # Fill with 'X' if message is shorter

            # Multiply message_vector with key_matrix
            cipher_vector = np.dot(key_matrix, message_vector) % 26

            # Append the final characters to cipher_text
            cipher_text.extend(chr(c + ord('A')) for c in cipher_vector)

        # Return the encrypted message as a string
        return ''.join(cipher_text)

    # Private method for validating determinant of key_matrix
    def validate_determinant(self, key_matrix):
        det = int(round(np.linalg.det(key_matrix))) % 26

        # Check if determinant is zero or not coprime to 26
        if det == 0 or self.gcd(det, 26) != 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    # Helper method for calculating greatest common divisor
    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

# Main method for taking user input and calling encrypt method
if __name__ == "__main__":
    import sys

    # Get user operation and matrix size
    operation = input().strip().lower()
    matrix_size = int(input().strip())

    # Initialize key_matrix with user input
    key_matrix = np.zeros((matrix_size, matrix_size), dtype=int)

    valid_matrix = False

    # Validate user input for key_matrix
    while not valid_matrix:
        try:
            for i in range(matrix_size):
                row = list(map(int, input().strip().split()))
                key_matrix[i] = row
            Main().validate_determinant(key_matrix)
            valid_matrix = True
        except ValueError as e:
            print(e)
            print("Please enter a valid matrix.")

    # Perform encryption or decryption based on user operation
    if operation == "encrypt":
        message = input().strip()
        encrypted_message = Main().encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")

# <END-OF-CODE>
