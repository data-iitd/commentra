

import random
from math import gcd

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
        if not message: # Check if message is empty
            raise ValueError("Message is empty")
        return pow(int.from_bytes(message.encode(), 'big'), self.publicKey, self.modulus) # Encrypt the message using public key and modulus

    # Decryption method
    def decrypt(self, encryptedMessage):
        if not encryptedMessage: # Check if encrypted message is empty
            raise ValueError("Message is empty")
        return bytes.from_hex(hex(pow(int(encryptedMessage), self.privateKey, self.modulus))[2:]).decode() # Decrypt the message using private key and modulus

    # Generate keys method
    def generateKeys(self, bits):
        random.seed() # Initialize random seed
        p = random.randrange(2**(bits//2), 2**(bits//2+1)) # Generate prime number p with given number of bits
        q = random.randrange(2**(bits//2), 2**(bits//2+1)) # Generate prime number q with given number of bits
        self.modulus = p * q # Multiply p and q to get modulus
        phi = (p-1) * (q-1) # Calculate phi(n) = (p-1)*(q-1)
        self.publicKey = 3 # Initialize public key as 3

        # Find a public key such that gcd(phi, publicKey) = 1
        while gcd(phi, self.publicKey) > 1:
            self.publicKey += 2 # Increment public key by 2 until gcd(phi, publicKey) = 1

        self.privateKey = pow(self.publicKey, -1, phi) # Calculate private key as the modular inverse of public key modulo phi

# Main method
if __name__ == "__main__":
    bits = int(input("Enter the number of bits: ")) # Read the number of bits from the user
    rsa = Main(bits) # Create an instance of Main class with the given number of bits
    print("Public Key:", rsa.publicKey) # Print the public key
    print("Modulus:", rsa.modulus) # Print the modulus
    operation = input("Enter the operation (encrypt/decrypt): ") # Read the operation from the user
    if operation.lower() == "encrypt": # If the operation is 'encrypt'
        message = input("Enter the message: ") # Read the message from the user
        encryptedMessage = rsa.encrypt(message) # Encrypt the message using the instance's encrypt method
        print("Encrypted Message:", encryptedMessage) # Print the encrypted message
    elif operation.lower() == "decrypt": # If the operation is 'decrypt'
        encryptedMessage = input("Enter the encrypted message: ") # Read the encrypted message from the user
        decryptedMessage = rsa.decrypt(encryptedMessage) # Decrypt the message using the instance's decrypt method
        print("Decrypted Message:", decryptedMessage) # Print the decrypted message
    else: # If the operation is not 'encrypt' or 'decrypt'
        print("Invalid operation") # Print an error message

