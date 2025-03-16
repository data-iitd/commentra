

def encrypt(self, str, rails):
    if rails == 1 or rails >= len(str):
        return str
    down = True
    str_rail = [['\n'] * len(str) for _ in range(rails)]
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
    encrypted_str = ''.join(''.join(row) for row in str_rail)
    return encrypted_str

def decrypt(self, str, rails):
    if rails == 1 or rails >= len(str):
        return str
    down = True
    str_rail = [['*'] * len(str) for _ in range(rails)]
    row, col = 0, 0
    for i in range(rails):
        for j in range(len(str)):
            if str_rail[i][j] == '*':
                str_rail[i][j] = str[col]
                col += 1
    decrypted_str = ''.join(''.join(row) for row in str_rail)
    return decrypted_str

if __name__ == '__main__':
    operation = input().strip().lower()
    rails = int(input().strip())
    if operation == 'encrypt':
        plaintext = input().strip()
        cipher = RailFenceCipher()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message: {}".format(encrypted))
    elif operation == 'decrypt':
        ciphertext = input().strip()
        cipher = RailFenceCipher()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message: {}".format(decrypted))
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
