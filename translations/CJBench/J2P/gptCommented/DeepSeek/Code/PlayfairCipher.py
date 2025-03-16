def remove_duplicate_chars(str):
    result = ""
    for char in str:
        if char not in result:
            result += char
    return result

def generate_matrix(key):
    key_without_duplicates = remove_duplicate_chars(key + "ABCDEFGHIKLMNOPQRSTUVWXYZ")
    matrix = [['' for _ in range(5)] for _ in range(5)]
    index = 0

    for i in range(5):
        for j in range(5):
            matrix[i][j] = key_without_duplicates[index]
            index += 1
    return matrix

def prepare_text(text):
    text = text.upper().replace("J", "I")
    prepared_text = ""
    prev_char = ''

    for char in text:
        if char != prev_char:
            prepared_text += char
            prev_char = char
        else:
            prepared_text += 'X' + char
            prev_char = ''
    if len(prepared_text) % 2 != 0:
        prepared_text += 'X'
    return prepared_text

def find_position(matrix, char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return [i, j]
    return [None, None]

def encrypt(matrix, plaintext):
    plaintext = prepare_text(plaintext)
    ciphertext = ""

    for i in range(0, len(plaintext), 2):
        char1 = plaintext[i]
        char2 = plaintext[i + 1]
        pos1 = find_position(matrix, char1)
        pos2 = find_position(matrix, char2)
        row1, col1 = pos1
        row2, col2 = pos2

        if row1 == row2:
            ciphertext += matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            ciphertext += matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
        else:
            ciphertext += matrix[row1][col2] + matrix[row2][col1]
    return ciphertext

def decrypt(matrix, ciphertext):
    plaintext = ""

    for i in range(0, len(ciphertext), 2):
        char1 = ciphertext[i]
        char2 = ciphertext[i + 1]
        pos1 = find_position(matrix, char1)
        pos2 = find_position(matrix, char2)
        row1, col1 = pos1
        row2, col2 = pos2

        if row1 == row2:
            plaintext += matrix[row1][(col1 + 4) % 5] + matrix[row2][(col2 + 4) % 5]
        elif col1 == col2:
            plaintext += matrix[(row1 + 4) % 5][col1] + matrix[(row2 + 4) % 5][col2]
        else:
            plaintext += matrix[row1][col2] + matrix[row2][col1]
    return plaintext

def main():
    key = input()
    matrix = generate_matrix(key)
    operation = input().strip()

    if operation.lower() == "encrypt":
        plaintext = input().strip()
        encrypted_message = encrypt(matrix, plaintext)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        ciphertext = input().strip()
        decrypted_message = decrypt(matrix, ciphertext)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()
