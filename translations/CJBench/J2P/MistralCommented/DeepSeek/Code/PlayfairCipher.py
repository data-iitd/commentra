class PlayfairCipher:
    def __init__(self, key):
        self.key = key
        self.matrix = self.generate_matrix()

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext.replace("J", "I"))
        ciphertext = ""

        for i in range(0, len(plaintext), 2):
            char1 = plaintext[i]
            char2 = plaintext[i + 1]

            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)

            row1, col1 = pos1
            row2, col2 = pos2

            if row1 == row2:
                ciphertext += self.matrix[row1][(col1 + 1) % 5] + self.matrix[row2][(col2 + 1) % 5]
            elif col1 == col2:
                ciphertext += self.matrix[(row1 + 1) % 5][col1] + self.matrix[(row2 + 1) % 5][col2]
            else:
                ciphertext += self.matrix[row1][col2] + self.matrix[row2][col1]

        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ""

        for i in range(0, len(ciphertext), 2):
            char1 = ciphertext[i]
            char2 = ciphertext[i + 1]

            pos1 = self.find_position(char1)
            pos2 = self.find_position(char2)

            row1, col1 = pos1
            row2, col2 = pos2

            if row1 == row2:
                plaintext += self.matrix[row1][(col1 + 4) % 5] + self.matrix[row2][(col2 + 4) % 5]
            elif col1 == col2:
                plaintext += self.matrix[(row1 + 4) % 5][col1] + self.matrix[(row2 + 4) % 5][col2]
            else:
                plaintext += self.matrix[row1][col2] + self.matrix[row2][col1]

        return plaintext

    def generate_matrix(self):
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
        matrix = [['' for _ in range(5)] for _ in range(5)]
        index = 0

        for i in range(5):
            for j in range(5):
                matrix[i][j] = key_without_duplicates[index]
                index += 1

        return matrix

    def remove_duplicate_chars(self, str):
        result = ""

        for char in str:
            if char not in result:
                result += char

        return result

    def prepare_text(self, text):
        text = text.upper()
        text = ''.join(filter(str.isalpha, text))
        text = text.replace("J", "I")

        prepared_text = ""
        prev_char = None

        for char in text:
            if char != prev_char:
                prepared_text += char
                prev_char = char
            else:
                prepared_text += 'X' + char
                prev_char = None

        if len(prepared_text) % 2 != 0:
            prepared_text += 'X'

        return prepared_text

    def find_position(self, char):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == char:
                    return (i, j)

        return None


if __name__ == "__main__":
    key = input()
    playfair_cipher = PlayfairCipher(key)
    operation = input().strip()

    if operation.lower() == "encrypt":
        plaintext = input().strip()
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = input().strip()
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")
