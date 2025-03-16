import numpy as np

class RailFenceCipher:
    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]
        row, col, i = 0, 0, 0
        down = True
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            str_rail[row][col] = str[i]
            col += 1
            i += 1
            row += 1 if down else -1
        
        encrypted_string = ''
        for ch_row in str_rail:
            for ch in ch_row:
                if ch != '\n':
                    encrypted_string += ch
        return encrypted_string
    
    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        str_rail = [['' for _ in range(len(str))] for _ in range(rails)]
        row, col = 0, 0
        down = True
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            str_rail[row][col] = '*'
            col += 1
            row += 1 if down else -1
        
        index = 0
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1
        
        decrypted_string = ''
        row, col = 0, 0
        down = True
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            decrypted_string += str_rail[row][col]
            col += 1
            row += 1 if down else -1
        
        return decrypted_string

# Main method to handle user input and provide output
def main():
    operation = input().strip()
    rails = int(input().strip())
    
    cipher = RailFenceCipher()
    
    if operation.lower() == 'encrypt':
        plaintext = input().strip()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == 'decrypt':
        ciphertext = input().strip()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
