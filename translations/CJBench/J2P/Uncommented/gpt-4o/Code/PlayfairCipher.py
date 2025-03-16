class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.matrix = self.generate_matrix()

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext.replace("J", "I"))
        ciphertext = []
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            row1, col1 = pos1
            row2, col2 = pos2
            if row1 == row2:
                ciphertext.append(self.matrix[row1][(col1 + 1) % 5])
                ciphertext.append(self.matrix[row2][(col2 + 1) % 5])
            elif col1 == col2:
                ciphertext.append(self.matrix[(row1 + 1) % 5][col1])
                ciphertext.append(self.matrix[(row2 + 1) % 5][col2])
            else:
                ciphertext.append(self.matrix[row1][col2])
                ciphertext.append(self.matrix[row2][col1])
        return ''.join(ciphertext)

    def decrypt(self, ciphertext):
        plaintext = []
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            row1, col1 = pos1
            row2, col2 = pos2
            if row1 == row2:
                plaintext.append(self.matrix[row1][(col1 + 4) % 5])
                plaintext.append(self.matrix[row2][(col2 + 4) % 5])
            elif col1 == col2:
                plaintext.append(self.matrix[(row1 + 4) % 5][col1])
                plaintext.append(self.matrix[(row2 + 4) % 5][col2])
            else:
                plaintext.append(self.matrix[row1][col2])
                plaintext.append(self.matrix[row2][col1])
        return ''.join(plaintext)

    def generate_matrix(self):
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
        matrix = []
        index = 0
        for i in range(5):
            row = []
            for j in range(5):
                row.append(key_without_duplicates[index])
                index += 1
            matrix.append(row)
        return matrix

    def remove_duplicate_chars(self, string):
        result = []
        for char in string:
            if char not in result:
                result.append(char)
        return ''.join(result)

    def prepare_text(self, text):
        text = text.upper().replace(" ", "").replace("J", "I")
        prepared_text = []
        prev_char = ''
        for c in text:
            if c != prev_char:
                prepared_text.append(c)
                prev_char = c
            else:
                prepared_text.append('X')
                prepared_text.append(c)
                prev_char = ''
        if len(prepared_text) % 2 != 0:
            prepared_text.append('X')
        return ''.join(prepared_text)

    def find_position(self, char):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == char:
                    return (i, j)
        return (-1, -1)

if __name__ == "__main__":
    key = input()
    playfair_cipher = PlayfairCipher(key)
    operation = input()
    if operation.lower() == "encrypt":
        plaintext = input()
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = input()
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")
        
# <END-OF-CODE>
