import numpy as np
from math import gcd

class HillCipher:
    def encrypt(self, message, key_matrix):
        # Convert the message to uppercase and remove all non-alphabetic characters
        message = ''.join(filter(str.isalpha, message)).upper()
        matrix_size = key_matrix.shape[0]

        # Validate that the key matrix has a valid determinant for Hill Cipher
        self.validate_determinant(key_matrix)

        cipher_text = []
        message_vector = np.zeros(matrix_size, dtype=int)
        cipher_vector = np.zeros(matrix_size, dtype=int)
        index = 0

        # Process the message in blocks of size equal to the key matrix size
        while index < len(message):
            for i in range(matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')
                    index += 1
                else:
                    message_vector[i] = ord('X') - ord('A')  # Padding with 'X' if needed

            # Encrypt the message vector using the key matrix
            cipher_vector = np.dot(key_matrix, message_vector) % 26
            cipher_text.extend(chr(c + ord('A')) for c in cipher_vector)

        return ''.join(cipher_text)

    def validate_determinant(self, key_matrix):
        det = int(round(np.linalg.det(key_matrix))) % 26
        if det == 0 or gcd(det, 26) != 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

def main():
    operation = input().strip().lower()
    matrix_size = int(input().strip())
    key_matrix = []

    valid_matrix = False
    while not valid_matrix:
        try:
            for _ in range(matrix_size):
                row = list(map(int, input().strip().split()))
                key_matrix.append(row)
            key_matrix = np.array(key_matrix)
            HillCipher().validate_determinant(key_matrix)
            valid_matrix = True
        except ValueError as e:
            print(e)
            print("Please enter a valid matrix.")

    if operation == "encrypt":
        message = input().strip()
        hill_cipher = HillCipher()
        encrypted_message = hill_cipher.encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
