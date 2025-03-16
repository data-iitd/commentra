import string

# Private constructor to prevent instantiation of the class
class Main:
    # Static variables for encryption parameters
    a = 17
    b = 20

    # Method to encrypt a message using a simple affine cipher
    def encryptMessage(self, msg):
        cipher = "" # StringBuilder to hold the encrypted message
        # Iterate through each character in the message
        for i in range(len(msg)):
            # Check if the character is not a space
            if msg[i]!='':
                # Apply the affine transformation and append the encrypted character
                cipher += chr((((self.a * (ord(msg[i]) - ord('A'))) + self.b) % 26) + ord('A'))
            else:
                # If it's a space, append it directly
                cipher += msg[i]
        # Return the final encrypted message as a string
        return cipher

    # Method to decrypt a cipher text back to the original message
    def decryptCipher(self, cipher):
        msg = "" # StringBuilder to hold the decrypted message
        aInv = 0 # Variable to hold the modular inverse of 'a'
        flag = 0 # Variable to check the condition for finding aInv

        # Find the modular inverse of 'a' such that (a * aInv) % 26 == 1
        for i in range(26):
            flag = (self.a * i) % 26
            if flag == 1:
                aInv = i # Store the value of aInv
                break # Exit the loop once found
        # Iterate through each character in the cipher text
        for i in range(len(cipher)):
            # Check if the character is not a space
            if cipher[i]!='':
                # Apply the inverse affine transformation and append the decrypted character
                msg += chr((((aInv * ((ord(cipher[i]) - ord('A') - self.b + 26)) % 26)) + ord('A')))
            else:
                # If it's a space, append it directly
                msg += cipher[i]
        # Return the final decrypted message as a string
        return msg

    # Main method to execute the program
    def main(self):
        msg = input().upper() # Read input message and convert to uppercase
        cipherText = self.encryptMessage(msg) # Encrypt the message
        print("Encrypted Message: " + cipherText) # Display the encrypted message
        decryptedText = self.decryptCipher(cipherText) # Decrypt the cipher text
        print("Decrypted Message: " + decryptedText) # Display the decrypted message

# Main function to execute the program
if __name__ == '__main__':
    Main().main()

