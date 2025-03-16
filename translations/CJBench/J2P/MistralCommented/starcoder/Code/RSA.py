
import random
import sys
from math import gcd
from functools import reduce

class Main:
    # Instance variables
    modulus = None
    privateKey = None
    publicKey = None

    # Constructor
    def __init__(self, bits):
        self.generateKeys(bits)

    # Encryption method
    def encrypt(self, message):
        if message == "": # Check if message is empty
            raise Exception("Message is empty")
        return pow(int.from_bytes(message.encode(), "big"), self.publicKey, self.modulus).to_bytes(self.modulus.bit_length() // 8 + 1, "big").decode() # Encrypt the message using public key and modulus

    # Decryption method
    def decrypt(self, encryptedMessage):
        if encryptedMessage == "": # Check if encrypted message is empty
            raise Exception("Message is empty")
        return pow(int(encryptedMessage), self.privateKey, self.modulus).to_bytes(self.modulus.bit_length() // 8 + 1, "big").decode() # Decrypt the message using private key and modulus

    # Generate keys method
    def generateKeys(self, bits):
        random.seed(None) # Initialize random number generator
        p = random.getrandbits(bits // 2) # Generate prime number p with given number of bits
        q = random.getrandbits(bits // 2) # Generate prime number q with given number of bits
        self.modulus = p * q # Multiply p and q to get modulus
        phi = (p - 1) * (q - 1) # Calculate phi(n) = (p-1)*(q-1)
        self.publicKey = 3 # Initialize public key as 3

        # Find a public key such that gcd(phi, publicKey) = 1
        while gcd(phi, self.publicKey) > 1:
            self.publicKey += 2 # Increment public key by 2 until gcd(phi, publicKey) = 1
        self.privateKey = pow(self.publicKey, -1, phi) # Calculate private key as the modular inverse of public key modulo phi

if __name__ == "__main__":
    bits = int(sys.stdin.readline().strip()) # Read the number of bits from the user
    rsa = Main(bits) # Create an instance of Main class with the given number of bits
    print("Public Key: " + str(rsa.publicKey)) # Print the public key
    print("Modulus: " + str(rsa.modulus)) # Print the modulus
    operation = sys.stdin.readline().strip().lower() # Read the operation from the user

    if operation == "encrypt": # If the operation is 'encrypt'
        message = sys.stdin.readline().strip() # Read the message from the user
        encryptedMessage = rsa.encrypt(message) # Encrypt the message using the instance's encrypt method
        print("Encrypted Message: " + encryptedMessage) # Print the encrypted message
    elif operation == "decrypt": # If the operation is 'decrypt'
        encryptedMessage = sys.stdin.readline().strip() # Read the encrypted message from the user
        decryptedMessage = rsa.decrypt(encryptedMessage) # Decrypt the message using the instance's decrypt method
        print("Decrypted Message: " + decryptedMessage) # Print the decrypted message
    else: # If the operation is not 'encrypt' or 'decrypt'
        print("Invalid operation") # Print an error message

