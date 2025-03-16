class Main:
    # Private constructor to prevent instantiation of the class
    def __init__(self):
        pass

    # Static variables for encryption parameters
    a = 17
    b = 20

    # Method to encrypt a message using a simple affine cipher
    @staticmethod
    def encrypt_message(msg):
        cipher = []  # List to hold the encrypted message
        # Iterate through each character in the message
        for char in msg:
            # Check if the character is not a space
            if char != ' ':
                # Apply the affine transformation and append the encrypted character
                encrypted_char = chr((((Main.a * (ord(char) - ord('A')) + Main.b) % 26) + ord('A')))
                cipher.append(encrypted_char)
            else:
                # If it's a space, append it directly
                cipher.append(char)
        # Return the final encrypted message as a string
        return ''.join(cipher)

    # Method to decrypt a cipher text back to the original message
    @staticmethod
    def decrypt_cipher(cipher):
        msg = []  # List to hold the decrypted message
        a_inv = 0  # Variable to hold the modular inverse of 'a'
        flag = 0  # Variable to check the condition for finding a_inv

        # Find the modular inverse of 'a' such that (a * a_inv) % 26 == 1
        for i in range(26):
            if (Main.a * i) % 26 == 1:
                a_inv = i  # Store the value of a_inv
                break  # Exit the loop once found

        # Iterate through each character in the cipher text
        for char in cipher:
            # Check if the character is not a space
            if char != ' ':
                # Apply the inverse affine transformation and append the decrypted character
                decrypted_char = chr((((a_inv * ((ord(char) - ord('A')) - Main.b + 26)) % 26) + ord('A')))
                msg.append(decrypted_char)
            else:
                # If it's a space, append it directly
                msg.append(char)
        # Return the final decrypted message as a string
        return ''.join(msg)

    # Main method to execute the program
    @staticmethod
    def main():
        msg = input().upper()  # Read input message and convert to uppercase
        cipher_text = Main.encrypt_message(msg)  # Encrypt the message
        print("Encrypted Message:", cipher_text)  # Display the encrypted message
        decrypted_text = Main.decrypt_cipher(cipher_text)  # Decrypt the cipher text
        print("Decrypted Message:", decrypted_text)  # Display the decrypted message

# Execute the main method
Main.main()
