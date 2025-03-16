
class RailFenceCipher:
    def __init__(self):
        pass
    
    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        str_rail = [['\n'] * len(str) for _ in range(rails)]
        down = True
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
        
        encrypted_str = ''.join(''.join(row).strip('\n') for row in str_rail)
        return encrypted_str
    
    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        str_rail = [['*'] * len(str) for _ in range(rails)]
        down = True
        row, col, index = 0, 0, 0
        
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
        
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1
        
        decrypted_str = ''.join(''.join(row).strip('*') for row in str_rail)
        return decrypted_str

# Main method to handle user input and provide output
if __name__ == "__main__":
    operation = input("Enter operation (encrypt/decrypt): ")
    rails = int(input("Enter number of rails: "))
    
    if operation.lower() == "encrypt":
        plaintext = input("Enter plaintext: ")
        cipher = RailFenceCipher()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter ciphertext: ")
        cipher = RailFenceCipher()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")