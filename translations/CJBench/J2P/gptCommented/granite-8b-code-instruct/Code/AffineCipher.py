
import string

# Private function to find the modular inverse of 'a'
def find_modular_inverse(a):
    for i in range(26):
        if (a * i) % 26 == 1:
            return i
    return -1

# Function to encrypt a message using a simple affine cipher
def encrypt_message(msg):
    cipher = ""
    a = 17  # Multiplier for encryption
    b = 20  # Increment for encryption
    for char in msg:
        if char!='':
            cipher += chr(((a * (ord(char) - ord('A'))) + b) % 26 + ord('A'))
        else:
            cipher += char
    return cipher

# Function to decrypt a cipher text back to the original message
def decrypt_cipher(cipher):
    msg = ""
    a_inv = find_modular_inverse(17)  # Find the modular inverse of 'a'
    for char in cipher:
        if char!='':
            msg += chr(((a_inv * ((ord(char) - ord('A')) - 20 + 26)) % 26) + ord('A'))
        else:
            msg += char
    return msg

# Main function to execute the program
def main():
    msg = input().upper()  # Read input message and convert to uppercase
    cipher_text = encrypt_message(msg)  # Encrypt the message
    print("Encrypted Message:", cipher_text)  # Display the encrypted message
    decrypted_text = decrypt_cipher(cipher_text)  # Decrypt the cipher text
    print("Decrypted Message:", decrypted_text)  # Display the decrypted message

if __name__ == "__main__":
    main()

