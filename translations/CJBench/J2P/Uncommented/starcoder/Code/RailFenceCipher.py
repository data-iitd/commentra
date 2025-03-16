
import sys
import string

class Main:
    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        down = True
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
        row = 0
        col = 0
        i = 0
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
        encryptedString = ''
        for chRow in strRail:
            for ch in chRow:
                if ch!= '\n':
                    encryptedString += ch
        return encryptedString

    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        down = True
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
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
        index = 0
        for i in range(rails):
            for j in range(len(str)):
                if strRail[i][j] == '*':
                    strRail[i][j] = str[index]
                    index += 1
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

if __name__ == '__main__':
    operation = sys.stdin.readline().strip()
    rails = int(sys.stdin.readline().strip())
    str = sys.stdin.readline().strip()
    cipher = Main()
    if operation.lower() == 'encrypt':
        print('Encrypted Message:'+ cipher.encrypt(str, rails))
    elif operation.lower() == 'decrypt':
        print('Decrypted Message:'+ cipher.decrypt(str, rails))
    else:
        print('Invalid operation. Please choose \'encrypt\' or \'decrypt\'.')

