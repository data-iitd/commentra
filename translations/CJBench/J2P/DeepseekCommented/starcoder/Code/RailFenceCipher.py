import sys

class Main:
    # Encrypts the input string using the rail fence cipher technique
    def encrypt(self, str, rails):
        # If rails is 1 or greater than the length of the string, return the string as is
        if rails == 1 or rails >= len(str):
            return str
        
        # Initialize direction and the 2D character array
        down = True
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
        
        # Fill the array with newline characters
        for i in range(rails):
            strRail[i] = ['\n' for i in range(len(str))]
        
        # Initialize row, column, and index variables
        row = 0
        col = 0
        i = 0
        
        # Traverse the string and fill the array
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            strRail[row][col] = str[i]
            col += 1
            if down:
                row += 1
            else:
                row -= 1
            i += 1
        
        # Construct the encrypted string from the filled array
        encryptedString = ''
        for chRow in strRail:
            for ch in chRow:
                if ch!= '\n':
                    encryptedString += ch
        return encryptedString
    
    # Decrypts the input string encrypted with the rail fence cipher technique
    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        # Initialize direction and the 2D character array
        down = True
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
        
        # Mark the positions with asterisks
        row = 0
        col = 0
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            strRail[row][col] = '*'
            col += 1
            if down:
                row += 1
            else:
                row -= 1
        
        # Fill the array with the characters from the encrypted string
        index = 0
        for i in range(rails):
            for j in range(len(str)):
                if strRail[i][j] == '*':
                    strRail[i][j] = str[index]
                    index += 1
        
        # Construct the decrypted string by traversing the array
        decryptedString = ''
        row = 0
        col = 0
        while col < len(str):
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            decryptedString += strRail[row][col]
            col += 1
            if down:
                row += 1
            else:
                row -= 1
        return decryptedString
    
    # Main method to handle user input and provide output
    def main(self):
        operation = sys.stdin.readline().strip()
        rails = int(sys.stdin.readline().strip())
        sys.stdin.readline()
        
        if operation.lower() == 'encrypt':
            plaintext = sys.stdin.readline().strip()
            cipher = Main()
            encrypted = cipher.encrypt(plaintext, rails)
            print("Encrypted Message: " + encrypted)
        elif operation.lower() == 'decrypt':
            ciphertext = sys.stdin.readline().strip()
            cipher = Main()
            decrypted = cipher.decrypt(ciphertext, rails)
            print("Decrypted Message: " + decrypted)
        else:
            print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    Main().main()

