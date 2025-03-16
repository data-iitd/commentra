

import string

class HillCipher:
    def __init__(self, key_matrix):
        self.key_matrix = key_matrix
        self.matrix_size = len(key_matrix)
        self.validate_determinant()

    def encrypt(self, message):
        message = message.upper().replace(' ', '').replace('-', '')
        message = message.replace('J', 'I')  # Replace 'J' with 'I' for consistency with Java
        message = message.replace('Q', 'O')  # Replace 'Q' with 'O' for consistency with Java
        message = message.replace('X', 'Z')  # Replace 'X' with 'Z' for consistency with Java
        message = message.replace('Z', 'X')  # Replace 'Z' with 'X' for consistency with Java

        cipher_text = ''
        message_vector = [0] * self.matrix_size
        cipher_vector = [0] * self.matrix_size
        index = 0

        while index < len(message):
            for i in range(self.matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')
                else:
                    message_vector[i] = 25  # Padding with 'Z' if needed
            index += 1

            for i in range(self.matrix_size):
                cipher_vector[i] = 0
                for j in range(self.matrix_size):
                    cipher_vector[i] += self.key_matrix[i][j] * message_vector[j]
                cipher_vector[i] = cipher_vector[i] % 26
                cipher_text += chr(ord('A') + cipher_vector[i])

        return cipher_text

    def validate_determinant(self):
        det = self.determinant(self.key_matrix, self.matrix_size)
        if det == 0 or self.gcd(det, 26)!= 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    def determinant(self, matrix, n):
        det = 0
        if n == 1:
            return matrix[0][0]
        sign = 1
        sub_matrix = [[0] * (n - 1) for _ in range(n - 1)]
        for x in range(n):
            sub_i = 0
            for i in range(1, n):
                sub_j = 0
                for j in range(n):
                    if j!= x:
                        sub_matrix[sub_i][sub_j] = matrix[i][j]
                        sub_j += 1
                sub_i += 1
            det += sign * matrix[0][x] * self.determinant(sub_matrix, n - 1)
            sign = -sign
        return det

    def gcd(self, a, b):
        while b!= 0:
            a, b = b, a % b
        return a

if __name__ == "__main__":
    operation = input().lower()

    matrix_size = int(input())
    key_matrix = []
    for _ in range(matrix_size):
        key_matrix.append(list(map(int, input().split())))

    hill_cipher = HillCipher(key_matrix)

    if operation == "encrypt":
        message = input()
        encrypted_message = hill_cipher.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")

