
# Importing the required libraries
import math

# Key values of a and b
a = 17
b = 20

# Function to encrypt a message using the Affine cipher
def encrypt_message(msg):
    # Cipher Text initially empty
    cipher = ""
    for i in range(len(msg)):
        # Avoid space to be encrypted
        # Applying encryption formula ( a * x + b ) mod m
        # {here x is msg[i] and m is 26} and added 'A' to
        # bring it in the range of ASCII alphabet [65-90 | A-Z]
        if msg[i] != ' ':
            cipher += chr((((a * (ord(msg[i]) - 65)) + b) % 26) + 65)
        else:
            cipher += msg[i]
    return cipher

# Function to decrypt a ciphertext using the Affine cipher
def decrypt_cipher(cipher):
    msg = ""
    a_inv = 0
    flag = 0

    # Find a^-1 (the multiplicative inverse of a mod 26)
    for i in range(26):
        # Check if (a * i) % 26 == 1,
        # then i will be the multiplicative inverse of a
        flag = (a * i) % 26
        if flag == 1:
            a_inv = i
            break

    for i in range(len(cipher)):
        # Applying decryption formula a^-1 * (x - b) mod m
        # {here x is cipher[i] and m is 26} and added 'A'
        # to bring it in the range of ASCII alphabet [65-90 | A-Z]
        if cipher[i] != ' ':
            msg += chr(((a_inv * ((ord(cipher[i]) - 65) - b + 26)) % 26) + 65)
        else:
            msg += cipher[i]

    return msg

# Main method to handle user input
if __name__ == "__main__":
    # Get input message
    msg = input("Enter the message: ").upper()

    # Encrypt the message
    cipher_text = encrypt_message(msg)
    print("Encrypted Message:", cipher_text)

    # Decrypt the ciphertext
    decrypted_text = decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

