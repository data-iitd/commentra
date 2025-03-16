
import sys

class Main:
    def __init__(self):
        pass
    
    # Method to encrypt a given string using the Rail Fence cipher technique
    def encrypt(self, str, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(str):
            return str
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        str_rail = [['\n'] * len(str) for _ in range(rails)]
        
        # Initialize the rail array with newline characters
        for i in range(rails):
            str_rail[i] = ['\n'] * len(str)
        
        # Variables to track the current position in the rail
        row = 0
        col = 0
        i = 0
        
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
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
            i += 1
        
        # Build the encrypted string from the rail array
        encrypted_str = ''.join([ch for row in str_rail for ch in row if ch!= '\n'])
        
        # Return the final encrypted string
        return encrypted_str
    
    # Method to decrypt a given string using the Rail Fence cipher technique
    def decrypt(self, str, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(str):
            return str
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        str_rail = [['\n'] * len(str) for _ in range(rails)]
        
        # Variables to track the current position in the rail
        row = 0
        col = 0
        
        # Mark the positions in the rail array where characters will be placed
        i = 0
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
                # Replace placeholders with actual characters from the input string
                if str_rail[i][j] == '*':
                    str_rail[i][j] = str[index]
                    index += 1
        
        # Build the decrypted string from the rail array
        decrypted_str = ''.join([ch for row in str_rail for ch in row if ch!= '\n'])
        
        # Return the final decrypted string
        return decrypted_str

# Main method to execute the program
if __name__ == "__main__":
    # Read the operation type (encrypt or decrypt) and the number of rails
    operation = input("Enter operation type (encrypt or decrypt): ")
    rails = int(input("Enter the number of rails: "))
    
    # Perform encryption or decryption based on user input
    if operation.lower() == "encrypt":
        plaintext = input("Enter the plaintext to encrypt: ")
        cipher = Main() # Create an instance of the Main class
        encrypted = cipher.encrypt(plaintext, rails) # Encrypt the plaintext
        print("Encrypted Message:", encrypted) # Output the encrypted message
    elif operation.lower() == "decrypt":
        ciphertext = input("Enter the ciphertext to decrypt: ")
        cipher = Main() # Create an instance of the Main class
        decrypted = cipher.decrypt(ciphertext, rails) # Decrypt the ciphertext
        print("Decrypted Message:", decrypted) # Output the decrypted message
    else:
        # Handle invalid operation input
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

