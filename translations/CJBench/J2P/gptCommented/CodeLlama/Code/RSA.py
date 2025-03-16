import math
import random

class Main:
    # Variables to hold the modulus, private key, and public key
    modulus = None
    privateKey = None
    publicKey = None

    # Constructor that initializes the Main keys based on the specified bit length
    def __init__(self, bits):
        self.generateKeys(bits)

    # Method to encrypt a message using the public key
    def encrypt(self, message):
        # Check if the message is empty and throw an exception if it is
        if message == "":
            raise ValueError("Message is empty")
        # Convert the message to a BigInteger, encrypt it, and return the encrypted string
        return str((int(message) ** self.publicKey) % self.modulus)

    # Method to decrypt an encrypted message using the private key
    def decrypt(self, encryptedMessage):
        # Check if the encrypted message is empty and throw an exception if it is
        if encryptedMessage == "":
            raise ValueError("Message is empty")
        # Convert the encrypted message to a BigInteger, decrypt it, and return the original message
        return str((int(encryptedMessage) ** self.privateKey) % self.modulus)

    # Method to generate Main keys (public and private) based on the specified bit length
    def generateKeys(self, bits):
        random.seed()
        # Generate two large prime numbers p and q
        p = random.randint(1, 2 ** (bits / 2))
        q = random.randint(1, 2 ** (bits / 2))
        
        # Calculate the modulus as p * q
        self.modulus = p * q
        
        # Calculate phi(n) = (p-1)(q-1)
        phi = (p - 1) * (q - 1)
        
        # Initialize the public key with a small odd number
        self.publicKey = 3
        
        # Ensure that publicKey is coprime to phi(n)
        while self.publicKey % phi != 1:
            self.publicKey += 2
        
        # Calculate the private key as the modular inverse of publicKey mod phi(n)
        self.privateKey = self.publicKey ** -1 % phi

# Main method to run the Main encryption/decryption program
def main():
    # Read the bit length for key generation from user input
    bits = int(input())
    
    # Create an instance of Main to generate Main keys
    rsa = Main(bits)
    
    # Display the generated public key and modulus
    print("Public Key: " + str(rsa.publicKey))
    print("Modulus: " + str(rsa.modulus))
    
    # Read the operation type (encrypt or decrypt) from user input
    operation = input()
    
    # Perform encryption if the user chose "encrypt"
    if operation == "encrypt":
        message = input() # Read the message to encrypt
        encryptedMessage = rsa.encrypt(message) # Encrypt the message
        print("Encrypted Message: " + encryptedMessage) # Display the encrypted message
    # Perform decryption if the user chose "decrypt"
    elif operation == "decrypt":
        encryptedMessage = input() # Read the encrypted message
        decryptedMessage = rsa.decrypt(encryptedMessage) # Decrypt the message
        print("Decrypted Message: " + decryptedMessage) # Display the decrypted message
    # Handle invalid operation input
    else:
        print("Invalid operation")

# Call the main method to start the program
main()

