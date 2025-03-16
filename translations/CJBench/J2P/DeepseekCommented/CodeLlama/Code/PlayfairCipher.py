import re

class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.matrix = self.generate_matrix()

    def generate_matrix(self):
        key_without_duplicates = re.sub(r'(.)(?=.*\1)', '', self.key + 'ABCDEFGHIKLMNOPQRSTUVWXYZ')
        matrix = [[''] * 5 for _ in range(5)]
        index = 0
        for i in range(5):
            for j in range(5):
                matrix[i][j] = key_without_duplicates[index]
                index += 1
        return matrix

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext.replace('J', 'I'))
        ciphertext = ''
        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]
            if row1 == row2:
                ciphertext += self.matrix[row1][(col1 + 1) % 5]
                ciphertext += self.matrix[row2][(col2 + 1) % 5]
            elif col1 == col2:
                ciphertext += self.matrix[(row1 + 1) % 5][col1]
                ciphertext += self.matrix[(row2 + 1) % 5][col2]
            else:
                ciphertext += self.matrix[row1][col2]
                ciphertext += self.matrix[row2][col1]
        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ''
        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]
            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)
            row1 = pos1[0]
            col1 = pos1[1]
            row2 = pos2[0]
            col2 = pos2[1]
            if row1 == row2:
                plaintext += self.matrix[row1][(col1 + 4) % 5]
                plaintext += self.matrix[row2][(col2 + 4) % 5]
            elif col1 == col2:
                plaintext += self.matrix[(row1 + 4) % 5][col1]
                plaintext += self.matrix[(row2 + 4) % 5][col2]
            else:
                plaintext += self.matrix[row1][col2]
                plaintext += self.matrix[row2][col1]
        return plaintext

    def find_position(self, c):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == c:
                    return [i, j]

    def prepare_text(self, text):
        text = text.upper().replace('[^A-Z]', '')
        prepared_text = ''
        prev_char = '\0'
        for c in text:
            if c != prev_char:
                prepared_text += c
                prev_char = c
            else:
                prepared_text += 'X' + c
                prev_char = '\0'
        if len(prepared_text) % 2 != 0:
            prepared_text += 'X'
        return prepared_text


if __name__ == '__main__':
    key = input()
    playfair_cipher = PlayfairCipher(key)
    operation = input()
    if operation.lower() == 'encrypt':
        plaintext = input()
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print('Encrypted Message:', encrypted_message)
    elif operation.lower() == 'decrypt':
        ciphertext = input()
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print('Decrypted Message:', decrypted_message)
    else:
        print('Invalid operation. Please enter "encrypt" or "decrypt".')


