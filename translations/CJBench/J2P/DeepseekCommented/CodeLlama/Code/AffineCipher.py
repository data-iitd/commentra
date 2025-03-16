
# Static variables for the affine cipher
a = 17
b = 20

# Method to encrypt the message using the affine cipher
def encryptMessage(msg):
    cipher = ""
    for i in range(len(msg)):
        if msg[i] != " ":
            # Applying the affine cipher encryption formula
            cipher += chr((((a * (ord(msg[i]) - ord("A"))) + b) % 26) + ord("A"))
        else:
            cipher += msg[i]
    return cipher

# Method to decrypt the cipher text using the affine cipher
def decryptCipher(cipher):
    msg = ""
    aInv = 0
    flag = 0
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            aInv = i
            break
    for i in range(len(cipher)):
        if cipher[i] != " ":
            # Applying the affine cipher decryption formula
            msg += chr((((aInv * ((ord(cipher[i]) - ord("A")) - b + 26)) % 26) + ord("A")))
        else:
            msg += cipher[i]
    return msg

# Main method to run the program
def main():
    msg = input("Enter the message: ").upper()
    cipherText = encryptMessage(msg)
    print("Encrypted Message: " + cipherText)
    decryptedText = decryptCipher(cipherText)
    print("Decrypted Message: " + decryptedText)

if __name__ == "__main__":
    main()

