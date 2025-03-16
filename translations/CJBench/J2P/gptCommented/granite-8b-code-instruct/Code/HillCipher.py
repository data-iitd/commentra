
import numpy as np

class Main:
    # Method to encrypt a message using a key matrix
    def encrypt(self, message, key_matrix):
        message = message.upper().replace(' ', '').replace('.', '') # Convert message to uppercase and remove non-alphabetic characters
        matrix_size = len(key_matrix) # Get the size of the key matrix
        determinant = np.linalg.det(key_matrix) % 26 # Calculate determinant modulo 26
        if determinant == 0: # Check if determinant is zero
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26.")
        message_vector = np.array([ord(c) - 65 for c in message]) % 26 # Convert message characters to integers and pad with 'X' if message is shorter than matrix size
        cipher_vector = np.zeros(matrix_size, dtype=int) # Initialize cipher vector
        for i in range(matrix_size):
            for j in range(matrix_size):
                cipher_vector[i] += key_matrix[i][j] * message_vector[j] # Matrix multiplication
            cipher_vector[i] = cipher_vector[i] % 26 # Modulo 26 to wrap around alphabet
        cipher_text = ''.join([chr(c + 65) for c in cipher_vector]) # Convert integers back to characters and join into a string
        return cipher_text # Return the final encrypted message

    # Main method to run the program
    def main(self):
        operation = input().lower() # Read the operation (encrypt/decrypt)
        matrix_size = int(input()) # Read the size of the key matrix
        key_matrix = np.zeros((matrix_size, matrix_size), dtype=int) # Initialize the key matrix
        valid_matrix = False # Flag to check if the matrix is valid

        # Loop to read the key matrix and validate it
        while not valid_matrix:
            try:
                # Read the key matrix values from user input
                for i in range(matrix_size):
                    key_matrix[i] = list(map(int, input().split()))
                if np.linalg.det(key_matrix) % 26 == 0: # Validate the key matrix determinant
                    raise ValueError("Invalid key matrix. Determinant is zero modulo 26.")
                valid_matrix = True # Set flag to true if validation is successful
            except ValueError as e:
                # Handle invalid matrix input
                print(e)
                print("Please enter a valid matrix.")

        # Check if the operation is encryption
        if operation == "encrypt":
            message = input() # Read the message to encrypt
            encrypted_message = self.encrypt(message, key_matrix) # Encrypt the message
            print("Encrypted Message:", encrypted_message) # Output the encrypted message
        else:
            print("Decryption functionality not implemented in this example.") # Placeholder for decryption

if __name__ == "__main__":
    Main().main() # Run the main method

