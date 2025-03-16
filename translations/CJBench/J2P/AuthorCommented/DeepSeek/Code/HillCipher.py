def encrypt(message, key_matrix):
    # Convert the message to uppercase and remove all non-alphabetic characters
    message = ''.join(filter(str.isalpha, message.upper()))
    matrix_size = len(key_matrix)

    # Validate that the key matrix has a valid determinant for Hill Cipher
    validate_determinant(key_matrix, matrix_size)

    cipher_text = []
    message_vector = [0] * matrix_size
    cipher_vector = [0] * matrix_size

    # Process the message in blocks of size equal to the key matrix size
    index = 0
    while index < len(message):
        for i in range(matrix_size):
            if index < len(message):
                message_vector[i] = ord(message[index]) - ord('A')
                index += 1
            else:
                message_vector[i] = ord('X') - ord('A')  # Padding with 'X' if needed

        # Encrypt the message vector using the key matrix
        for i in range(matrix_size):
            cipher_vector[i] = 0
            for j in range(matrix_size):
                cipher_vector[i] += key_matrix[i][j] * message_vector[j]
            cipher_vector[i] = cipher_vector[i] % 26
            cipher_text.append(chr(cipher_vector[i] + ord('A')))

    return ''.join(cipher_text)


def validate_determinant(key_matrix, n):
    det = determinant(key_matrix, n) % 26
    if det == 0 or gcd(det, 26) != 1:
        raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")


def determinant(matrix, n):
    if n == 1:
        return matrix[0][0]
    det = 0
    sign = 1
    for x in range(n):
        sub_matrix = [row[:x] + row[x+1:] for row in matrix[1:]]
        det += sign * matrix[0][x] * determinant(sub_matrix, n - 1)
        sign = -sign
    return det


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def main():
    import sys
    input = sys.stdin.read
    data = input().lower()

    operation = data.split()[0]
    matrix_size = int(data.split()[1])
    key_matrix = [list(map(int, input().split())) for _ in range(matrix_size)]

    # Validate the key matrix
    try:
        validate_determinant(key_matrix, matrix_size)
    except ValueError as e:
        print(e)
        return

    if operation == 'encrypt':
        message = input().strip()
        encrypted_message = encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")


if __name__ == "__main__":
    main()
