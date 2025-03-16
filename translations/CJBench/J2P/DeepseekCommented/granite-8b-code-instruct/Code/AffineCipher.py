
# Python code to implement the affine cipher

# Static variables for the affine cipher
a = 17
b = 20

# Method to encrypt the message using the affine cipher
def encrypt_message(msg):
    cipher = ""
    for char in msg:
        if char!='':
            # Applying the affine cipher encryption formula
            cipher += chr(((a * (ord(char) - ord('A'))) + b) % 26 + ord('A'))
        else:
            cipher += char
    return cipher

# Method to decrypt the cipher text using the affine cipher
def decrypt_cipher(cipher):
    msg = ""
    a_inv = 0
    flag = 0
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            a_inv = i
            break
    for char in cipher:
        if char!='':
            # Applying the affine cipher decryption formula
            msg += chr(((a_inv * ((ord(char) - ord('A')) - b + 26)) % 26) + ord('A'))
        else:
            msg += char
    return msg

# Main method to run the program
if __name__ == "__main__":
    msg = input().upper()
    cipher_text = encrypt_message(msg)
    print("Encrypted Message:", cipher_text)
    decrypted_text = decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

