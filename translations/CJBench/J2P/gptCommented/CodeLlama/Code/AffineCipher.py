
# Import the necessary modules
import math

# Define the encryption parameters
a = 17
b = 20

# Define the encryption function
def encrypt_message(msg):
    cipher = ""
    for char in msg:
        if char != " ":
            cipher += chr(((a * (ord(char) - ord("A"))) + b) % 26 + ord("A"))
        else:
            cipher += char
    return cipher

# Define the decryption function
def decrypt_cipher(cipher):
    msg = ""
    a_inv = 0
    for i in range(26):
        if (a * i) % 26 == 1:
            a_inv = i
            break
    for char in cipher:
        if char != " ":
            msg += chr((a_inv * ((ord(char) - ord("A")) - b + 26)) % 26 + ord("A"))
        else:
            msg += char
    return msg

# Main function to execute the program
def main():
    msg = input("Enter the message: ").upper()
    cipher_text = encrypt_message(msg)
    print("Encrypted Message:", cipher_text)
    decrypted_text = decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

# Call the main function
main()

