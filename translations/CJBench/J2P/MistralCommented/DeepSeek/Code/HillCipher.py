def encrypt(message, key_matrix):
    # Convert message to uppercase and remove non-alphabetic characters
    message = ''.join(filter(str.isalpha, message)).upper()

    # Validate the size of the key_matrix
    matrix_size = len(key_matrix)

    # Validate determinant of the key_matrix
    validate_determinant(key_matrix, matrix_size)

    # Initialize cipher_text
    cipher_text = []

    # Initialize message_vector and cipher_vector of size matrix_size
    message_vector = [0] * matrix_size
    cipher_vector = [0] * matrix_size

    # Initialize index for iterating through message
    index = 0

    # Encrypt message character by character
    while index < len(message):

        # Convert each character of message to its corresponding integer value
        for i in range(matrix_size):
            if index < len(message):
                # Store the integer value of current character in message_vector
                message_vector[i] = ord(message[index]) - ord('A')
                index += 1
            else:
                # If message is shorter than the key_matrix, fill the remaining message_vector with 'X'
                message_vector[i] = ord('X') - ord('A')

        # Multiply message_vector with key_matrix and store the result in cipher_vector
        for i in range(matrix_size):
            for j in range(matrix_size):
                cipher_vector[i] += key_matrix[i][j] * message_vector[j]
            # Perform modulo 26 operation on cipher_vector to get the final cipher_text character
            cipher_vector[i] = cipher_vector[i] % 26
            # Append the final character to cipher_text
            cipher_text.append(chr(cipher_vector[i] + ord('A')))

    # Return the encrypted message as a String
    return ''.join(cipher_text)


def validate_determinant(key_matrix, n):
    # Calculate the determinant of key_matrix modulo 26
    det = determinant(key_matrix, n) % 26

    # Check if determinant is zero or not coprime to 26
    if det == 0 or gcd(det, 26) != 1:
        # Raise an exception if determinant is invalid
        raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")


def determinant(matrix, n):
    # Base case: determinant of a 1x1 matrix
    if n == 1:
        return matrix[0][0]

    # Initialize sign, sub_matrix and calculate determinant recursively
    sign = 1
    sub_matrix = [[0] * (n - 1) for _ in range(n - 1)]
    det = 0

    # Calculate determinant of sub_matrices and add to the final determinant
    for x in range(n):
        sub_i = 0
        for i in range(1, n):
            sub_j = 0
            for j in range(n):
                if j != x:
                    # Store the sub_matrix elements
                    sub_matrix[sub_i][sub_j] = matrix[i][j]
                    sub_j += 1
            sub_i += 1
        det += sign * matrix[0][x] * determinant(sub_matrix, n - 1)
        sign = -sign

    # Return the final determinant
    return det


def gcd(a, b):
    # Base case: if b is zero, return a
    if b == 0:
        return a

    # Recursive case: calculate gcd of b and the remainder of a modulo b
    return gcd(b, a % b)


# Main method for taking user input and calling encrypt method
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    # Get user operation and matrix size
    operation = data[0].lower()
    matrix_size = int(data[1])

    # Initialize key_matrix with user input
    key_matrix = []
    valid_matrix = False

    # Validate user input for key_matrix
    index = 2
    while not valid_matrix:
        try:
            key_matrix = [[int(data[index + i * matrix_size + j]) for j in range(matrix_size)] for i in range(matrix_size)]
            validate_determinant(key_matrix, matrix_size)
            valid_matrix = True
        except (ValueError, IndexError):
            print("Invalid key matrix. Please enter a valid matrix.")
            index = -1
        index += 1

    # Perform encryption or decryption based on user operation
    if operation == "encrypt":
        message = ''.join(data[index + 1:])
        encrypted_message = encrypt(message, key_matrix)
        print("Encrypted Message:", encrypted_message)
    else:
        print("Decryption functionality not implemented in this example.")
