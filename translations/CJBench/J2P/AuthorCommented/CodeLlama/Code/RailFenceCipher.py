
import sys

# Encrypts the input string using the rail fence cipher method with the given number of rails.
def encrypt(str, rails):
    # Base case of single rail or rails are more than the number of characters in the string
    if rails == 1 or rails >= len(str):
        return str

    # Boolean flag to determine if the movement is downward or upward in the rail matrix.
    down = True
    # Create a 2D array to represent the rails (rows) and the length of the string (columns).
    strRail = [['\n'] * len(str) for _ in range(rails)]

    row = 0
    col = 0
    i = 0
    # Fill the rail matrix with characters from the string based on the rail pattern.
    while col < len(str):
        # Change direction to down when at the first row.
        if row == 0:
            down = True
        # Change direction to up when at the last row.
        elif row == rails - 1:
            down = False

        # Place the character in the current position of the rail matrix.
        strRail[row][col] = str[i]
        col += 1
        # Move to the next row based on the direction.
        if down:
            row += 1
        else:
            row -= 1
        i += 1

    # Construct the encrypted string by reading characters row by row.
    encryptedString = ''
    for chRow in strRail:
        for ch in chRow:
            if ch != '\n':
                encryptedString += ch

    return encryptedString

# Decrypts the input string using the rail fence cipher method with the given number of rails.
def decrypt(str, rails):
    # Base case of single rail or rails are more than the number of characters in the string
    if rails == 1 or rails >= len(str):
        return str

    # Boolean flag to determine if the movement is downward or upward in the rail matrix.
    down = True

    # Create a 2D array to represent the rails (rows) and the length of the string (columns).
    strRail = [['\n'] * len(str) for _ in range(rails)]
    row = 0
    col = 0

    # Mark the pattern on the rail matrix using '*'.
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
    # Fill the rail matrix with characters from the input string based on the marked pattern.
    for i in range(rails):
        for j in range(len(str)):
            if strRail[i][j] == '*':
                strRail[i][j] = str[index]
                index += 1

    # Construct the decrypted string by following the zigzag pattern.
    decryptedString = ''
    row = 0
    col = 0

    while col < len(str):
        # Change direction to down when at the first row.
        if row == 0:
            down = True
        elif row == rails - 1:
            down = False

        # Append the character from the rail matrix to the decrypted string.
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
    if operation == 'encrypt':
        plaintext = sys.stdin.readline().strip()
        encrypted = encrypt(plaintext, rails)
        print("Encrypted Message: " + encrypted)
    elif operation == 'decrypt':
        ciphertext = sys.stdin.readline().strip()
        decrypted = decrypt(ciphertext, rails)
        print("Decrypted Message: " + decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

