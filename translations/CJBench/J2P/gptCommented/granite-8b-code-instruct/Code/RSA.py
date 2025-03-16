
import random
from Crypto.Util.number import *

class Main:
    # Constructor that initializes the Main keys based on the specified bit length
    def __init__(self, bits):
        self.generateKeys(bits)

    # Method to encrypt a message using the public key
    def encrypt(self, message):
        # Check if the message is empty and throw an exception if it is
        if not message:
            raise ValueError("Message is empty")
        # Convert the message to a bytes object, encrypt it, and return the encrypted string
        return long_to_bytes(pow(bytes_to_long(message), self.publicKey, self.modulus))

    # Method to decrypt an encrypted message using the private key
    def decrypt(self, encryptedMessage):
        # Check if the encrypted message is empty and throw an exception if it is
        if not encryptedMessage:
            raise ValueError("Message is empty")
        # Convert the encrypted message to a long integer, decrypt it, and return the original message
        return bytes_to_long(pow(long_to_bytes(encryptedMessage), self.privateKey, self.modulus))

    # Method to generate Main keys (public and private) based on the specified bit length
    def generateKeys(self, bits):
        # Generate two large prime numbers p and q
        p = getPrime(bits // 2)
        q = getPrime(bits // 2)
        
        # Calculate the modulus as p * q
        self.modulus = p * q
        
        # Calculate phi(n) = (p-1)(q-1)
        phi = (p - 1) * (q - 1)
        
        # Initialize the public key with a small odd number
        self.publicKey = 3
        
        # Ensure that publicKey is coprime to phi(n)
        while gcd(phi, self.publicKey) > 1:
            self.publicKey += 2
        
        # Calculate the private key as the modular inverse of publicKey mod phi(n)
        self.privateKey = inverse(self.publicKey, phi)

# Main method to run the Main encryption/decryption program
if __name__ == "__main__":
    import sys
    from Crypto.Util.number import *
    
    # Read the bit length for key generation from user input
    bits = int(input("Enter the bit length for key generation: "))
    
    # Create an instance of Main to generate Main keys
    rsa = Main(bits)
    
    # Display the generated public key and modulus
    print("Public Key:", rsa.publicKey)
    print("Modulus:", rsa.modulus)
    
    # Read the operation type (encrypt or decrypt) from user input
    operation = input("Enter the operation type (encrypt or decrypt): ")
    
    # Perform encryption if the user chose "encrypt"
    if operation.lower() == "encrypt":
        message = input("Enter the message to encrypt: ")
        encryptedMessage = rsa.encrypt(message)
        print("Encrypted Message:", encryptedMessage)
    # Perform decryption if the user chose "decrypt"
    elif operation.lower() == "decrypt":
        encryptedMessage = input("Enter the encrypted message to decrypt: ")
        decryptedMessage = rsa.decrypt(encryptedMessage)
        print("Decrypted Message:", decryptedMessage)
    # Handle invalid operation input
    else:
        print("Invalid operation")

