import numpy as np

class HillCipher:
    # Method to encrypt a message using a key matrix
    def encrypt(self, message, key_matrix):
        # Convert the message to uppercase and remove non-alphabetic characters
        message = ''.join(filter(str.isalpha, message)).upper()
        matrix_size = key_matrix.shape[0]  # Get the size of the key matrix
        self.validate_determinant(key_matrix)  # Validate the key matrix determinant
        cipher_text = []  # List to build the encrypted message
        message_vector = np.zeros(matrix_size, dtype=int)  # Vector to hold message characters
        cipher_vector = np.zeros(matrix_size, dtype=int)  # Vector to hold encrypted characters
        index = 0  # Index to track the position in the message

        # Process the message in blocks of size equal to the matrix size
        while index < len(message):
            # Fill the message vector with characters from the message
            for i in range(matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')  # Convert char to int
                    index += 1
                else:
                    message_vector[i] = ord('X') - ord('A')  # Pad with 'X' if message is shorter than matrix size
            
            # Encrypt the message vector using the key matrix
            cipher_vector = np.dot(key_matrix, message_vector) % 26  # Matrix multiplication and modulo 26
            cipher_text.extend((chr(c + ord('A')) for c in cipher_vector))  # Convert back to char and append to cipher text

        return ''.join(cipher_text)  # Return the final encrypted message

    # Method to validate the determinant of the key matrix
    def validate_determinant(self, key_matrix):
        det = int(round(np.linalg.det(key_matrix))) % 26  # Calculate determinant modulo 26
        # Check if determinant is zero or not coprime to 26
        if det == 0 or self.gcd(det, 26) != 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    # Method to calculate the greatest common divisor (GCD) of two numbers
    def gcd(self, a, b):
        if b == 0:
            return a  # Base case for GCD
        return self.gcd(b, a % b)  # Recursive GCD calculation

# Main function to run the program
if __name__ == "__main__":
    import sys

    hill_cipher = HillCipher()  # Create an instance of the HillCipher class
    operation = input().strip().lower()  # Read the operation (encrypt/decrypt)
    matrix_size = int(input().strip())  # Read the size of the key matrix
    key_matrix = np.zeros((matrix_size, matrix_size), dtype=int)  # Initialize the key matrix
    valid_matrix = False  # Flag to check if the matrix is valid

    # Loop to read the key matrix and validate it
    while not valid_matrix:
        try:
            # Read the key matrix values from user input
            for i in range(matrix_size):
                key_matrix[i] = list(map(int, input().strip().split()))
            hill_cipher.validate_determinant(key_matrix)  # Validate the key matrix
            valid_matrix = True  # Set flag to true if validation is successful
        except ValueError as e:
            # Handle invalid matrix input
            print(e)
            print("Please enter a valid matrix.")

    # Check if the operation is encryption
    if operation == "encrypt":
        message = input().strip()  # Read the message to encrypt
        encrypted_message = hill_cipher.encrypt(message, key_matrix)  # Encrypt the message
        print("Encrypted Message:", encrypted_message)  # Output the encrypted message
    else:
        print("Decryption functionality not implemented in this example.")  # Placeholder for decryption
