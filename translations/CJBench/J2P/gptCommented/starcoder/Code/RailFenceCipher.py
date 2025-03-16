import sys

class Main:
    # Method to encrypt a given string using the Rail Fence cipher technique
    def encrypt(self, str, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(str):
            return str
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
        
        # Initialize the rail array with newline characters
        for i in range(rails):
            strRail[i] = ['\n' for j in range(len(str))]
        
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
            strRail[row][col] = str[i]
            col += 1
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
            
            i += 1
        
        # Build the encrypted string from the rail array
        encryptedString = ''
        for chRow in strRail:
            for ch in chRow:
                # Append only non-newline characters to the result
                if ch!= '\n':
                    encryptedString += ch
        
        # Return the final encrypted string
        return encryptedString
    
    # Method to decrypt a given string using the Rail Fence cipher technique
    def decrypt(self, str, rails):
        # If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if rails == 1 or rails >= len(str):
            return str
        
        # Variable to determine the direction of movement (down or up the rails)
        down = True
        
        # Create a 2D array to represent the rails
        strRail = [['\n' for i in range(len(str))] for j in range(rails)]
        
        # Variables to track the current position in the rail
        row = 0
        col = 0
        
        # Mark the positions in the rail array where characters will be placed
        while col < len(str):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Mark the current position with a placeholder
            strRail[row][col] = '*'
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
                if strRail[i][j] == '*':
                    strRail[i][j] = str[index]
                    index += 1
        
        # Build the decrypted string from the rail array
        decryptedString = ''
        row = 0
        col = 0
        
        # Read characters from the rail array to form the decrypted string
        while col < len(str):
            # Change direction at the top and bottom rails
            if row == 0:
                down = True
            elif row == rails - 1:
                down = False
            
            # Append the character at the current rail position to the result
            decryptedString += strRail[row][col]
            col += 1
            
            # Move up or down the rails based on the current direction
            if down:
                row += 1
            else:
                row -= 1
        
        # Return the final decrypted string
        return decryptedString

# Main method to execute the program
if __name__ == '__main__':
    # Create a scanner object to read input from the user
    scanner = sys.stdin
    
    # Read the operation type (encrypt or decrypt) and the number of rails
    operation = scanner.readline().strip()
    rails = int(scanner.readline().strip())
    
    # Perform encryption or decryption based on user input
    if operation.lower() == 'encrypt':
        plaintext = scanner.readline().strip() # Read the plaintext to encrypt
        cipher = Main() # Create an instance of the Main class
        encrypted = cipher.encrypt(plaintext, rails) # Encrypt the plaintext
        print("Encrypted Message: " + encrypted) # Output the encrypted message
    elif operation.lower() == 'decrypt':
        ciphertext = scanner.readline().strip() # Read the ciphertext to decrypt
        cipher = Main() # Create an instance of the Main class
        decrypted = cipher.decrypt(ciphertext, rails) # Decrypt the ciphertext
        print("Decrypted Message: " + decrypted) # Output the decrypted message
    else:
        # Handle invalid operation input
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
    
    # Close the scanner to free resources
    scanner.close()

