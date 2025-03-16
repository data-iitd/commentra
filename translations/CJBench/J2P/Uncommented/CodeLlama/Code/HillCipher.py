
import math
import re

def encrypt(message, key_matrix):
    message = message.upper().replace("[^A-Z]", "")
    matrix_size = len(key_matrix)
    validate_determinant(key_matrix, matrix_size)
    cipher_text = ""
    message_vector = [0] * matrix_size
    cipher_vector = [0] * matrix_size
    index = 0
    while index < len(message):
        for i in range(matrix_size):
            if index < len(message):
                message_vector[i] = ord(message[index]) - ord('A')
            else:
                message_vector[i] = ord('X') - ord('A')
            index += 1
        for i in range(matrix_size):
            cipher_vector[i] = 0
            for j in range(matrix_size):
                cipher_vector[i] += key_matrix[i][j] * message_vector[j]
            cipher_vector[i] = cipher_vector[i] % 26
            cipher_text += chr(cipher_vector[i] + ord('A'))
    return cipher_text

def validate_determinant(key_matrix, n):
    det = determinant(key_matrix, n) % 26
    if det == 0 or gcd(det, 26) != 1:
        raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

def determinant(matrix, n):
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
                if j != x:
                    sub_matrix[sub_i][sub_j] = matrix[i][j]
                    sub_j += 1
            sub_i += 1
        det += sign * matrix[0][x] * determinant(sub_matrix, n - 1)
        sign = -sign
    return det

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

if __name__ == "__main__":
    operation = input().lower()
    matrix_size = int(input())
    key_matrix = [[0] * matrix_size for _ in range(matrix_size)]
    valid_matrix = False
    while not valid_matrix:
        try:
            for i in range(matrix_size):
                for j in range(matrix_size):
                    key_matrix[i][j] = int(input())
            validate_determinant(key_matrix, matrix_size)
            valid_matrix = True
        except ValueError as e:
            print(e.args[0])
            print("Please enter a valid matrix.")
    if "encrypt" == operation:
        message = input()
        encrypted_message = encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")

