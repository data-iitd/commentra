import numpy as np

class RailFenceCipher:
    
    # Method to encrypt a given string using the Rail Fence cipher technique
    def encrypt(self, text, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(text):
            return text
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        str_rail = [['\n' for _ in range(len(text))] for _ in range(rails)]
        
        # Variables to track the current position in the rail
        row, col = 0, 0
        
        # Fill the rail array with characters from the input string
        for char in text:
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Place the character in the current rail position
            str_rail[row][col] = char
            col += 1
            
            # Move up or down the rails based on the current direction
            row += 1 if down else -1
        
        # Build the encrypted string from the rail array
        encrypted_string = ''.join(''.join(ch for ch in ch_row if ch != '\n') for ch_row in str_rail)
        
        # Return the final encrypted string
        return encrypted_string
    
    # Method to decrypt a given string using the Rail Fence cipher technique
    def decrypt(self, text, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(text):
            return text
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        str_rail = [['\n' for _ in range(len(text))] for _ in range(rails)]
        
        # Mark the positions in the rail array where characters will be placed
        row, col = 0, 0
        for _ in range(len(text)):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Mark the current position with a placeholder
            str_rail[row][col] = '*'
            col += 1
            
            # Move up or down the rails based on the current direction
            row += 1 if down else -1
        
        # Fill the rail array with characters from the input string based on marked positions
        index = 0
        for i in range(rails):
            for j in range(len(text)):
                # Replace placeholders with actual characters from the input string
                if str_rail[i][j] == '*':
                    str_rail[i][j] = text[index]
                    index += 1
        
        # Build the decrypted string from the rail array
        decrypted_string = []
        row, col = 0, 0
        
        # Read characters from the rail array to form the decrypted string
        for _ in range(len(text)):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Append the character at the current rail position to the result
            decrypted_string.append(str_rail[row][col])
            col += 1
            
            # Move up or down the rails based on the current direction
            row += 1 if down else -1
        
        # Return the final decrypted string
        return ''.join(decrypted_string)

# Main function to execute the program
if __name__ == "__main__":
    # Read the operation type (encrypt or decrypt) and the number of rails
    operation = input("Enter operation (encrypt/decrypt): ")
    rails = int(input("Enter number of rails: "))
    
    # Perform encryption or decryption based on user input
    cipher = RailFenceCipher()  # Create an instance of the RailFenceCipher class
    if operation.lower() == "encrypt":
        plaintext = input("Enter plaintext to encrypt: ")  # Read the plaintext to encrypt
        encrypted = cipher.encrypt(plaintext, rails)  # Encrypt the plaintext
        print("Encrypted Message:", encrypted)  # Output the encrypted message
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter ciphertext to decrypt: ")  # Read the ciphertext to decrypt
        decrypted = cipher.decrypt(ciphertext, rails)  # Decrypt the ciphertext
        print("Decrypted Message:", decrypted)  # Output the decrypted message
    else:
        # Handle invalid operation input
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

# <END-OF-CODE>
