
import numpy as np

class Main:
    def __init__(self):
        pass

    def encrypt(self, message, key_matrix):
        message = message.upper().replace(' ', '').replace('.', '')
        matrix_size = key_matrix.shape[0]
        determinant = np.linalg.det(key_matrix) % 26
        if determinant == 0 or np.gcd(determinant, 26)!= 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")
        message_vector = np.zeros(matrix_size, dtype=int)
        cipher_vector = np.zeros(matrix_size, dtype=int)
        index = 0
        cipher_text = ''
        while index < len(message):
            for i in range(matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')
                else:
                    message_vector[i] = ord('X') - ord('A')
            for i in range(matrix_size):
                cipher_vector[i] = 0
                for j in range(matrix_size):
                    cipher_vector[i] += key_matrix[i][j] * message_vector[j]
                cipher_vector[i] = cipher_vector[i] % 26
                cipher_text += chr(cipher_vector[i] + ord('A'))
            index += 1
        return cipher_text

    def validate_determinant(self, key_matrix, n):
        det = np.linalg.det(key_matrix) % 26
        if det == 0 or np.gcd(det, 26)!= 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    def gcd(self, a, b):
        while b!= 0:
            a, b = b, a % b
        return a

if __name__ == "__main__":
    operation = input().lower()
    matrix_size = int(input())
    key_matrix = np.zeros((matrix_size, matrix_size), dtype=int)
    valid_matrix = False
    while not valid_matrix:
        try:
            for i in range(matrix_size):
                key_matrix[i] = list(map(int, input().split()))
            main = Main()
            main.validate_determinant(key_matrix, matrix_size)
            valid_matrix = True
        except ValueError as e:
            print(e)
            print("Please enter a valid matrix.")
    if operation == "encrypt":
        message = input()
        encrypted_message = main.encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")
