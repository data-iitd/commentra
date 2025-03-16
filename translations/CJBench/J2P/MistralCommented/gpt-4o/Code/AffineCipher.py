class Main:
    a = 17
    b = 20

    @staticmethod
    def encrypt_message(msg):
        cipher = []  # Initialize an empty list to store the encrypted message
        for char in msg:
            if char != ' ':  # If the current character is not a space
                encrypted_char = chr(((Main.a * (ord(char) - ord('A')) + Main.b) % 26) + ord('A'))  # Encrypt the character
                cipher.append(encrypted_char)  # Append the encrypted character to the list
            else:
                cipher.append(char)  # If the current character is a space, just append it
        return ''.join(cipher)  # Return the encrypted message as a string

    @staticmethod
    def decrypt_cipher(cipher):
        msg = []  # Initialize an empty list to store the decrypted message
        a_inv = 0

        # Find the multiplicative inverse of 'a' modulo 26 to decrypt the message
        for i in range(26):
            if (Main.a * i) % 26 == 1:
                a_inv = i
                break

        for char in cipher:
            if char != ' ':  # If the current character is not a space
                decrypted_char = chr((a_inv * ((ord(char) - ord('A')) - Main.b + 26)) % 26 + ord('A'))  # Decrypt the character
                msg.append(decrypted_char)  # Append the decrypted character to the list
            else:
                msg.append(char)  # If the current character is a space, just append it
        return ''.join(msg)  # Return the decrypted message as a string

if __name__ == "__main__":
    msg = input().upper()  # Read a line of input from the user and convert it to uppercase
    cipher_text = Main.encrypt_message(msg)  # Encrypt the message
    print("Encrypted Message:", cipher_text)  # Print the encrypted message
    decrypted_text = Main.decrypt_cipher(cipher_text)  # Decrypt the encrypted message
    print("Decrypted Message:", decrypted_text)  # Print the decrypted message

# <END-OF-CODE>
