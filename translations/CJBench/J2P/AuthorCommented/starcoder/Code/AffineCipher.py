
# Key values of a and b
a = 17
b = 20

# Function to encrypt a message
def encryptMessage(msg):
    # Cipher Text initially empty
    cipher = ""
    for i in range(len(msg)):
        # Avoid space to be encrypted
        if msg[i]!='':
            # applying encryption formula ( a * x + b ) mod m
            # {here x is msg[i] and m is 26} and added 'A' to
            # bring it in the range of ASCII alphabet [65-90 | A-Z]
            cipher += chr((((a * (ord(msg[i]) - ord('A'))) + b) % 26) + ord('A'))
        else:
            cipher += msg[i]
    return cipher

# Function to decrypt a ciphertext
def decryptCipher(cipher):
    msg = ""
    aInv = 0
    flag = 0

    # Find a^-1 (the multiplicative inverse of a mod 26)
    for i in range(26):
        flag = (a * i) % 26
        # Check if (a * i) % 26 == 1,
        # then i will be the multiplicative inverse of a
        if flag == 1:
            aInv = i
            break

    for i in range(len(cipher)):
        # Applying decryption formula a^-1 * (x - b) mod m
        # {here x is cipher[i] and m is 26} and added 'A'
        # to bring it in the range of ASCII alphabet [65-90 | A-Z]
        if cipher[i]!='':
            msg += chr((((aInv * ((ord(cipher[i]) - ord('A') - b + 26)) % 26)) + ord('A')))
        else:
            msg += cipher[i]

    return msg

# Main method to handle user input
if __name__ == '__main__':
    # Get input message
    msg = input("Enter message to be encrypted: ").upper()

    # Encrypt the message
    cipherText = encryptMessage(msg)
    print("Encrypted Message: " + cipherText)

    # Decrypt the ciphertext
    decryptedText = decryptCipher(cipherText)
    print("Decrypted Message: " + decryptedText)

