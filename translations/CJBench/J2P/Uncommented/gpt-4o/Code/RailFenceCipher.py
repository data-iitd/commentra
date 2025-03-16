import numpy as np

class Main:
    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        down = True
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]
        row, col, i = 0, 0, 0
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            str_rail[row][col] = str[i]
            i += 1
            col += 1
            
            if down:
                row += 1
            else:
                row -= 1
        
        encrypted_string = ''.join(ch for ch_row in str_rail for ch in ch_row if ch != '\n')
        return encrypted_string

    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        down = True
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]
        row, col = 0, 0
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            str_rail[row][col] = '*'
            col += 1
            
            if down:
                row += 1
            else:
                row -= 1
        
        index = 0
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1
        
        decrypted_string = []
        row, col = 0, 0
        
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            decrypted_string.append(str_rail[row][col])
            col += 1
            
            if down:
                row += 1
            else:
                row -= 1
        
        return ''.join(decrypted_string)

if __name__ == "__main__":
    operation = input()
    rails = int(input())
    if operation.lower() == "encrypt":
        plaintext = input()
        cipher = Main()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == "decrypt":
        ciphertext = input()
        cipher = Main()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
        
# <END-OF-CODE>
