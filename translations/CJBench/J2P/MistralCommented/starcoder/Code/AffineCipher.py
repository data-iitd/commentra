
import string

class Main:
    def __init__(self):
        # Private constructor to prevent instantiation of the class from outside
        pass

    a = 17
    b = 20

    # Method to encrypt a message using the given Caesar cipher algorithm
    def encryptMessage(self, msg):
        cipher = "" # Initialize an empty String to store the encrypted message
        for i in range(len(msg)):
            if msg[i]!='': # If the current character is not a space
                cipher += chr((((self.a * (ord(msg[i]) - ord('A'))) + self.b) % 26) + ord('A')) # Encrypt the character using the Caesar cipher algorithm and append it to the String
            else:
                cipher += msg[i] # If the current character is a space, just append it to the String as it is
        return cipher # Return the encrypted message as a String

    # Method to decrypt a message encrypted using the given Caesar cipher algorithm
    def decryptCipher(self, cipher):
        msg = "" # Initialize an empty String to store the decrypted message
        aInv = 0
        flag = 0

        # Find the multiplicative inverse of 'a' modulo 26 to decrypt the message
        for i in range(26):
            flag = (self.a * i) % 26
            if flag == 1:
                aInv = i
                break

        for i in range(len(cipher)):
            if cipher[i]!='': # If the current character is not a space
                msg += chr((((aInv * ((ord(cipher[i]) - ord('A') - self.b + 26)) % 26) + ord('A')))) # Decrypt the character using the inverse of 'a' and append it to the String
            else:
                msg += cipher[i] # If the current character is a space, just append it to the String as it is
        return msg # Return the decrypted message as a String

    def main(self):
        msg = input().upper() # Read a line of input from the user and convert it to uppercase
        msgChars = list(msg) # Convert the input String to a list of characters for processing
        cipherText = self.encryptMessage(msgChars) # Encrypt the message using the encryptMessage() method and store the result in a String variable
        print("Encrypted Message: " + cipherText) # Print the encrypted message to the console
        decryptedText = self.decryptCipher(cipherText) # Decrypt the encrypted message using the decryptCipher() method and store the result in a String variable
        print("Decrypted Message: " + decryptedText) # Print the decrypted message to the console

# 