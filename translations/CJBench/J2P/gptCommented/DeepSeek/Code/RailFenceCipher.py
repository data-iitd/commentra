import numpy as np

class RailFenceCipher:
    
    # Method to encrypt a given string using the Rail Fence cipher technique
    def encrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        # Initialize the rail array with newline characters
        str_rail = [['\n' for _ in range(len(str))] for _ in range(rails)]
        
        # Variables to track the current position in the rail
        row, col, i = 0, 0, 0
        down = True
        
        # Fill the rail array with characters from the input string
        while col < len(str):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Place the character in the current rail position
            str_rail[row][col] = str[i]
            col += 1
            i += 1
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
        
        # Build the encrypted string from the rail array
        encrypted_string = ''
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] != '\n':
                    encrypted_string += str_rail[i][j]
        
        return encrypted_string
    
    # Method to decrypt a given string using the Rail Fence cipher technique
    def decrypt(self, str, rails):
        if rails == 1 or rails >= len(str):
            return str
        
        # Initialize the rail array with placeholders
        str_rail = [['' for _ in range(len(str))] for _ in range(rails)]
        
        # Variables to track the current position in the rail
        row, col = 0, 0
        down = True
        
        # Mark the positions in the rail array where characters will be placed
        while col < len(str):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Mark the current position with a placeholder
            str_rail[row][col] = '*'
            col += 1
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
        
        # Fill the rail array with characters from the input string based on marked positions
        index = 0
        for i in range(rails):
            for j in range(len(str)):
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1
        
        # Build the decrypted string from the rail array
        decrypted_string = ''
        row, col = 0, 0
        
        # Read characters from the rail array to form the decrypted string
        while col < len(str):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Append the character at the current rail position to the result
            decrypted_string += str_rail[row][col]
            col += 1
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
        
        return decrypted_string

# Main function to execute the program
def main():
    # Read the operation type (encrypt or decrypt) and the number of rails
    operation = input().strip()
    rails = int(input().strip())
    
    # Perform encryption or decryption based on user input
    cipher = RailFenceCipher()
    if operation.lower() == 'encrypt':
        plaintext = input().strip()
        encrypted = cipher.encrypt(plaintext, rails)
        print("Encrypted Message:", encrypted)
    elif operation.lower() == 'decrypt':
        ciphertext = input().strip()
        decrypted = cipher.decrypt(ciphertext, rails)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

# Execute the main function
if __name__ == "__main__":
    main()
