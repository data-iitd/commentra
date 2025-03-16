
# Import the necessary libraries
import array


def encrypt(string, rails):
    if rails == 1 or rails >= len(string):
        # If the number of rails is 1 or equal to the length of the string, return the original string
        return string

    down = True  # Flag to determine the direction of traversing the rail fence
    str_rail = [['\n' for _ in range(len(string))] for _ in range(rails)]  # 2D array to store the encrypted string

    # Initialize the 2D array with newline character
    for i in range(rails):
        for j in range(len(string)):
            str_rail[i][j] = '\n'

    row = 0
    col = 0
    i = 0
    # Fill the 2D array with the given string
    while col < len(string):
        if row == 0:
            down = True  # Reset the direction flag if we start a new row
        elif row == rails - 1:
            down = False  # Change the direction flag if we reach the last row
        str_rail[row][col] = string[i]  # Store the character from the string into the 2D array
        col += 1  # Increment the column index
        if down:
            row += 1  # Increment the row index if moving down
        else:
            row -= 1  # Decrement the row index if moving up
        i += 1

    # Build the encrypted string from the 2D array
    encrypted_string = ''
    for ch_row in str_rail:
        for ch in ch_row:
            if ch != '\n':  # Skip newline character while building the encrypted string
                encrypted_string += ch

    # Return the encrypted string
    return encrypted_string


def decrypt(string, rails):
    if rails == 1 or rails >= len(string):
        # If the number of rails is 1 or equal to the length of the string, return the original string
        return string

    down = True  # Flag to determine the direction of traversing the rail fence
    str_rail = [['*' for _ in range(len(string))] for _ in range(rails)]  # 2D array to store the decrypted string

    # Initialize the 2D array with asterisks
    for i in range(rails):
        for j in range(len(string)):
            str_rail[i][j] = '*'

    index = 0  # Index to fill the characters from the given string into the 2D array

    # Fill the 2D array with the given string
    for i in range(rails):
        for j in range(len(string)):
            if str_rail[i][j] == '*':
                str_rail[i][j] = string[index]  # Replace the asterisk with the character from the string
                index += 1

    # Build the decrypted string from the 2D array
    decrypted_string = ''
    row = 0
    col = 0

    # Fill the StringBuilder with the characters from the 2D array
    while col < len(string):
        if row == 0:
            down = True  # Reset the direction flag if we start a new row
        elif row == rails - 1:
            down = False  # Change the direction flag if we reach the last row
        decrypted_string += str_rail[row][col]  # Append the character from the 2D array to the StringBuilder
        col += 1  # Increment the column index
        if down:
            row += 1  # Increment the row index if moving down
        else:
            row -= 1  # Decrement the row index if moving up

    # Return the decrypted string
    return decrypted_string


# Main method to take user input and call the encryption or decryption method based on the user's choice
def main():
    operation = input()  # Read the operation ('encrypt' or 'decrypt') from the user
    rails = int(input())  # Read the number of rails from the user
    plaintext = input()  # Read the plaintext from the user

    if operation.lower() == 'encrypt':  # If the user chooses to encrypt
        encrypted = encrypt(plaintext, rails)  # Encrypt the plaintext using the rail fence cipher
        print("Encrypted Message:", encrypted)  # Print the encrypted message
    elif operation.lower() == 'decrypt':  # If the user chooses to decrypt
        ciphertext = input()  # Read the ciphertext from the user
        decrypted = decrypt(ciphertext, rails)  # Decrypt the ciphertext using the rail fence cipher
        print("Decrypted Message:", decrypted)  # Print the decrypted message
    else:  # If the user enters an invalid operation
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")  # Print an error message


if __name__ == '__main__':
    main()


