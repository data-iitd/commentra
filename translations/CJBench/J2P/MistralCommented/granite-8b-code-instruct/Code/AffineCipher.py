

a = 17
b = 20

# Method to encrypt a message using the given Caesar cipher algorithm
def encrypt_message(msg):
    cipher = "" # Initialize an empty string to store the encrypted message
    for i in range(len(msg)):
        if msg[i]!='': # If the current character is not a space
            cipher += chr(((a * (ord(msg[i]) - ord('A'))) + b) % 26 + ord('A')) # Encrypt the character using the Caesar cipher algorithm and append it to the string
        else:
            cipher += msg[i] # If the current character is a space, just append it to the string as it is
    return cipher # Return the encrypted message as a string

# Method to decrypt a message encrypted using the given Caesar cipher algorithm
def decrypt_cipher(cipher):
    msg = "" # Initialize an empty string to store the decrypted message
    a_inv = 0
    flag = 0

    # Find the multiplicative inverse of 'a' modulo 26 to decrypt the message
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            a_inv = i
            break

    for i in range(len(cipher)):
        if cipher[i]!='': # If the current character is not a space
            msg += chr((((a_inv * ((ord(cipher[i]) - ord('A')) - b + 26)) % 26) + ord('A')) # Decrypt the character using the inverse of 'a' and append it to the string
        else:
            msg += cipher[i] # If the current character is a space, just append it to the string as it is
    return msg # Return the decrypted message as a string

if __name__ == "__main__":
    msg = input().upper() # Read a line of input from the user and convert it to uppercase
    cipher_text = encrypt_message(msg) # Encrypt the message using the encrypt_message() method and store the result in a string variable
    print("Encrypted Message:", cipher_text) # Print the encrypted message to the console
    decrypted_text = decrypt_cipher(cipher_text) # Decrypt the encrypted message using the decrypt_cipher() method and store the result in a string variable
    print("Decrypted Message:", decrypted_text) # Print the decrypted message to the console

