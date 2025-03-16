import numpy as np

class HillCipher:
    def encrypt(self, message, key_matrix):
        message = message.upper().replace(" ", "").replace("\n", "")
        matrix_size = key_matrix.shape[0]
        self.validate_determinant(key_matrix, matrix_size)
        cipher_text = []
        message_vector = np.zeros(matrix_size, dtype=int)
        cipher_vector = np.zeros(matrix_size, dtype=int)
        index = 0
        
        while index < len(message):
            for i in range(matrix_size):
                if index < len(message):
                    message_vector[i] = ord(message[index]) - ord('A')
                    index += 1
                else:
                    message_vector[i] = ord('X') - ord('A')  # Padding with 'X'
            
            cipher_vector = np.dot(key_matrix, message_vector) % 26
            cipher_text.extend(chr(c + ord('A')) for c in cipher_vector)
        
        return ''.join(cipher_text)

    def validate_determinant(self, key_matrix, n):
        det = int(np.round(np.linalg.det(key_matrix))) % 26
        if det == 0 or self.gcd(det, 26) != 1:
            raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

if __name__ == "__main__":
    import sys
    
    hill_cipher = HillCipher()
    operation = input().strip().lower()
    matrix_size = int(input().strip())
    key_matrix = np.zeros((matrix_size, matrix_size), dtype=int)
    
    valid_matrix = False
    while not valid_matrix:
        try:
            for i in range(matrix_size):
                key_matrix[i] = list(map(int, input().strip().split()))
            hill_cipher.validate_determinant(key_matrix, matrix_size)
            valid_matrix = True
        except ValueError as e:
            print(e)
            print("Please enter a valid matrix.")
    
    if operation == "encrypt":
        message = input().strip()
        encrypted_message = hill_cipher.encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")

# <END-OF-CODE>
