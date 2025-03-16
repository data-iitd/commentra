def encrypt(message, key_matrix):
    # Convert the message to uppercase and remove non-alphabetic characters
    message = ''.join(filter(str.isalpha, message.upper()))
    matrix_size = len(key_matrix)  # Get the size of the key matrix
    validate_determinant(key_matrix, matrix_size)  # Validate the key matrix determinant
    cipher_text = []  # List to hold encrypted characters
    message_vector = [0] * matrix_size  # Vector to hold message characters
    cipher_vector = [0] * matrix_size  # Vector to hold encrypted characters
    index = 0  # Index to track the position in the message

    # Process the message in blocks of size equal to the matrix size
    while index < len(message):
        # Fill the message vector with characters from the message
        for i in range(matrix_size):
            if index < len(message):
                message_vector[i] = ord(message[index]) - ord('A')  # Convert char to int
            else:
                message_vector[i] = ord('X') - ord('A')  # Pad with 'X' if message is shorter than matrix size
            index += 1

        # Encrypt the message vector using the key matrix
        for i in range(matrix_size):
            cipher_vector[i] = 0  # Initialize cipher vector
            for j in range(matrix_size):
                cipher_vector[i] += key_matrix[i][j] * message_vector[j]  # Matrix multiplication
            cipher_vector[i] = cipher_vector[i] % 26  # Modulo 26 to wrap around alphabet
            cipher_text.append(chr(cipher_vector[i] + ord('A')))  # Convert back to char and append to cipher text

    return ''.join(cipher_text)  # Return the final encrypted message


def validate_determinant(key_matrix, n):
    det = determinant(key_matrix, n) % 26  # Calculate determinant modulo 26
    # Check if determinant is zero or not coprime to 26
    if det == 0 or gcd(det, 26) != 1:
        raise ValueError("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.")


def determinant(matrix, n):
    det = 0  # Initialize determinant
    if n == 1:
        return matrix[0][0]  # Base case for 1x1 matrix
    sign = 1  # Variable to alternate signs for cofactor expansion
    sub_matrix = [[0] * (n - 1) for _ in range(n - 1)]  # Submatrix for determinant calculation

    # Calculate determinant using cofactor expansion
    for x in range(n):
        sub_i = 0  # Row index for submatrix
        for i in range(1, n):
            sub_j = 0  # Column index for submatrix
            for j in range(n):
                if j != x:
                    sub_matrix[sub_i][sub_j] = matrix[i][j]  # Fill submatrix
                    sub_j += 1
            sub_i += 1
        det += sign * matrix[0][x] * determinant(sub_matrix, n - 1)  # Recursive determinant calculation
        sign = -sign  # Alternate sign
    return det  # Return the calculated determinant


def gcd(a, b):
    if b == 0:
        return a  # Base case for GCD
    return gcd(b, a % b)  # Recursive GCD calculation


# Main method to run the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().lower()  # Read the operation (encrypt/decrypt)
    operation, matrix_size_input = data.split()  # Split the operation and matrix size
    matrix_size = int(matrix_size_input)  # Convert matrix size to integer
    key_matrix = []  # Initialize the key matrix
    valid_matrix = False  # Flag to check if the matrix is valid

    # Loop to read the key matrix and validate it
    while not valid_matrix:
        try:
            key_matrix_input = input().split()  # Read the key matrix values from user input
            key_matrix = [list(map(int, key_matrix_input[i * matrix_size:(i + 1) * matrix_size])) for i in range(matrix_size)]  # Convert to matrix format
            validate_determinant(key_matrix, matrix_size)  # Validate the key matrix
            valid_matrix = True  # Set flag to true if validation is successful
        except ValueError as e:
            # Handle invalid matrix input
            print(e)
            print("Please enter a valid matrix.")

    # Check if the operation is encryption
    if operation == "encrypt":
        message = input().strip()  # Read the message to encrypt
        encrypted_message = encrypt(message, key_matrix)  # Encrypt the message
        print("Encrypted Message:", encrypted_message)  # Output the encrypted message
    else:
        print("Decryption functionality not implemented in this example.")  # Placeholder for decryption
