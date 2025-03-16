

import string

# Key values of a and b
a = 17
b = 20

# Encrypts a message using the Affine cipher
def encrypt_message(msg):
    # Cipher Text initially empty
    cipher = ""
    for char in msg:
        # Avoid space to be encrypted
        # applying encryption formula ( a * x + b ) mod m
        # {here x is msg[i] and m is 26} and added 'A' to
        # bring it in the range of ASCII alphabet [65-90 | A-Z]
        if char!='':
            cipher += chr(((a * (ord(char) - ord('A'))) + b) % 26 + ord('A'))
        else:
            cipher += char
    return cipher

# Decrypts a ciphertext using the Affine cipher
def decrypt_cipher(cipher):
    msg = ""
    a_inv = 0
    flag = 0

    # Find a^-1 (the multiplicative inverse of a mod 26)
    for i in range(26):
        flag = (a * i) % 26
        # Check if (a * i) % 26 == 1,
        # then i will be the multiplicative inverse of a
        if flag == 1:
            a_inv = i
            break

    for char in cipher:
        # Applying decryption formula a^-1 * (x - b) mod m
        # {here x is cipher[i] and m is 26} and added 'A'
        # to bring it in the range of ASCII alphabet [65-90 | A-Z]
        if char!='':
            msg += chr(((a_inv * ((ord(char) - ord('A')) - b + 26)) % 26) + ord('A'))
        else:
            msg += char

    return msg

# Main method to handle user input
def main():
    msg = input("Enter a message: ").upper()

    # Encrypt the message
    cipher_text = encrypt_message(msg)
    print("Encrypted Message:", cipher_text)

    # Decrypt the ciphertext
    decrypted_text = decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

if __name__ == "__main__":
    main()

