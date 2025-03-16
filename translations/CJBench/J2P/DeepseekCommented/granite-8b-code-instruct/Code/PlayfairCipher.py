
import string

class Main:
    def __init__(self, key):
        self.key = key
        self.generate_matrix()

    def encrypt(self, plaintext):
        plaintext = self.prepare_text(plaintext.replace("J", "I"))
        ciphertext = ""
        for i in range(0, len(plaintext), 2):
            char1, char2 = plaintext[i], plaintext[i + 1]
            pos1, pos2 = self.find_position(char1), self.find_position(char2)
            row1, col1 = pos1[0], pos1[1]
            row2, col2 = pos2[0], pos2[1]
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
        plaintext = ""
        for i in range(0, len(ciphertext), 2):
            char1, char2 = ciphertext[i], ciphertext[i + 1]
            pos1, pos2 = self.find_position(char1), self.find_position(char2)
            row1, col1 = pos1[0], pos1[1]
            row2, col2 = pos2[0], pos2[1]
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

    def generate_matrix(self):
        key_without_duplicates = self.remove_duplicate_chars(self.key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
        self.matrix = [[""] * 5 for _ in range(5)]
        index = 0
        for i in range(5):
            for j in range(5):
                self.matrix[i][j] = key_without_duplicates[index]
                index += 1

    def remove_duplicate_chars(self, s):
        result = ""
        for c in s:
            if c not in result:
                result += c
        return result

    def prepare_text(self, text):
        text = text.upper().replace(" ", "")
        prepared_text = ""
        prev_char = ""
        for c in text:
            if c!= prev_char:
                prepared_text += c
                prev_char = c
            else:
                prepared_text += "X" + c
                prev_char = ""
        if len(prepared_text) % 2!= 0:
            prepared_text += "X"
        return prepared_text

    def find_position(self, c):
        for i in range(5):
            for j in range(5):
                if self.matrix[i][j] == c:
                    return [i, j]
        return [0, 0]

if __name__ == "__main__":
    key = input("Enter the key: ")
    playfair_cipher = Main(key)
    operation = input("Enter the operation (encrypt/decrypt): ")
    if operation.lower() == "encrypt":
        plaintext = input("Enter the plaintext: ")
        encrypted_message = playfair_cipher.encrypt(plaintext)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter the ciphertext: ")
        decrypted_message = playfair_cipher.decrypt(ciphertext)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

