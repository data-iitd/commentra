class Main:
    # Static variables for encryption parameters
    a = 17  # Multiplier for encryption
    b = 20  # Increment for encryption

    @staticmethod
    def encrypt_message(msg):
        cipher = []  # List to hold the encrypted message
        # Iterate through each character in the message
        for char in msg:
            # Check if the character is not a space
            if char != ' ':
                # Apply the affine transformation and append the encrypted character
                cipher.append(chr(((Main.a * (ord(char) - ord('A')) + Main.b) % 26) + ord('A')))
            else:
                # If it's a space, append it directly
                cipher.append(char)
        # Return the final encrypted message as a string
        return ''.join(cipher)

    @staticmethod
    def decrypt_cipher(cipher):
        msg = []  # List to hold the decrypted message
        a_inv = 0  # Variable to hold the modular inverse of 'a'

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
                msg.append(chr((a_inv * ((ord(char) - ord('A')) - Main.b + 26)) % 26 + ord('A')))
            else:
                # If it's a space, append it directly
                msg.append(char)
        # Return the final decrypted message as a string
        return ''.join(msg)

# Main execution
if __name__ == "__main__":
    msg = input().upper()  # Read input message and convert to uppercase
    cipher_text = Main.encrypt_message(msg)  # Encrypt the message
    print("Encrypted Message:", cipher_text)  # Display the encrypted message
    decrypted_text = Main.decrypt_cipher(cipher_text)  # Decrypt the cipher text
    print("Decrypted Message:", decrypted_text)  # Display the decrypted message

# <END-OF-CODE>
